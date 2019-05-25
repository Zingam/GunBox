// Self
#include "Instance.hpp"

// Project headers - Application
#include "Application/CommandLineArgs.hpp"
#include "Application/ModuleInfo.hpp"
// Project headers - Logger
#include "Logger/LogAPI.hpp"
// Project headers - Renderer
#include "Renderer/Graphics/GraphicsRenderer_Interface.hpp"
#include "Renderer/Graphics/GraphicsRenderer_InterfaceAccessor.hpp"
#include "Renderer/Graphics/Vulkan/Objects/Utilities/PropertyEnumerators.hpp"
#include "Renderer/Graphics/Vulkan/Objects/Utilities/Utilities.hpp"

// Project headers - System
#include "System/HostPlatform.hpp"

// C Standard Library
#include <cstdint>
#include <cstring>

NAMESPACE_BEGIN(Renderer::Graphics)

////////////////////////////////////////////////////////////////////////////////
// Constructors & Destructors
////////////////////////////////////////////////////////////////////////////////

Instance::Instance(GraphicsRenderer_Interface const& graphicsRenderer)
  : graphicsRenderer{ graphicsRenderer }
  , instance{ nullptr }
{
  this->Create();
}

////////////////////////////////////////////////////////////////////////////////
// Properties
////////////////////////////////////////////////////////////////////////////////
VkInstance
Instance::Get() const
{
  return this->instance;
}

std::vector<PhysicalDevice>&
Instance::PhysicalDevices()
{
  return physicalDevices;
};

////////////////////////////////////////////////////////////////////////////////
// Properties
////////////////////////////////////////////////////////////////////////////////

void
Instance::Create()
{
  // Initialize glad
  auto& vulkanDevice =
    GraphicsRenderer_InterfaceAccessor::HostPlatform(graphicsRenderer)
      .GPUDevice_Vulkan();
  gladLoadVulkanUserPtr(
    nullptr,
    reinterpret_cast<GLADuserptrloadfunc>(vulkanDevice.InstanceProcAddress()),
    nullptr);

  // Create Vulkan instance
  auto const& applicationInfo =
    GraphicsRenderer_InterfaceAccessor::ApplicationInfo(graphicsRenderer);
  auto const& engineInfo =
    GraphicsRenderer_InterfaceAccessor::EngineInfo(graphicsRenderer);

  VkApplicationInfo vulkanApplicationInfo{
    .sType = VK_STRUCTURE_TYPE_APPLICATION_INFO,
    .pNext = nullptr,
    .pApplicationName = applicationInfo.Title().c_str(),
    .applicationVersion = applicationInfo.GetVersion().AsNumber(),
    .pEngineName = engineInfo.Title().c_str(),
    .engineVersion = engineInfo.GetVersion().AsNumber(),
    .apiVersion = VK_API_VERSION_1_1,
  };

  auto layersToEnable = GetLayerNamesToEnable();
  auto const& extensionsToEnable = vulkanDevice.SurfaceCreationExtensions();

  if (2LL <= vulkanDevice.SurfaceCreationExtensions().size()) {
    VkInstanceCreateInfo instanceCreateInfo{
      .sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
      .pNext = nullptr,
      .flags = 0L,
      .pApplicationInfo = &vulkanApplicationInfo,
      .enabledLayerCount = static_cast<std::uint32_t>(layersToEnable.size()),
      .ppEnabledLayerNames = layersToEnable.data(),
      .enabledExtensionCount =
        static_cast<std::uint32_t>(extensionsToEnable.size()),
      .ppEnabledExtensionNames = extensionsToEnable.data(),
    };
    if (vkCallSuccess(
          vkCreateInstance(&instanceCreateInfo, nullptr, &instance))) {
      gladLoadVulkanUserPtr(
        nullptr,
        reinterpret_cast<GLADuserptrloadfunc>(
          vulkanDevice.InstanceProcAddress()),
        instance);
    }

    assert(IsInstance(instance) && "Vulkan instance is not initialized!");
  }
}

std::vector<char const*>
Instance::GetLayerNamesToEnable() const
{
  auto const& commandLineArgs =
    GraphicsRenderer_InterfaceAccessor::CommandLineArgs(graphicsRenderer);
  auto debugFeature = std::find(
    commandLineArgs.RendererFeatures().begin(),
    commandLineArgs.RendererFeatures().end(),
    System::DeviceTypes::Graphics::APIFeatures_t::Debug);
  if (debugFeature != commandLineArgs.RendererFeatures().end()) {
    return GetRequiredLayerNames();
  }

  return {};
}

std::vector<char const*>
Instance::GetRequiredLayerNames() const
{
  std::vector<char const*> availableLayers;
  auto& vulkanDevice =
    GraphicsRenderer_InterfaceAccessor::HostPlatform(graphicsRenderer)
      .GPUDevice_Vulkan();
  auto layers = EnumerateInstanceLayers();
  for (auto const layerName : vulkanDevice.ValidationLayerNames()) {
    for (auto& layer : layers) {
      if (!std::strcmp(layerName, layer.layerName)) {
        availableLayers.emplace_back(layerName);
      }
    }
  }

  return availableLayers;
}

void
Instance::EnumeratePhysicalDevices()
{
  physicalDevices =
    Renderer::Graphics::EnumeratePhysicalDevices<PhysicalDevice>(*this);
}

PhysicalDevice const&
Instance::SelectPhysicalDevice(
  PhysicalDevice::Type_t const physicalDeviceType) const
{
  assert(
    IsFalse(physicalDevices.empty()) && "No physical devices are available");

  auto physicalDevice = SelectPreferredPhysicalDevice(physicalDeviceType);
  if (physicalDevice.has_value()) {
    return physicalDevice.value();
  } else {
    return physicalDevices[0];
  }
}

std::optional<std::reference_wrapper<PhysicalDevice const>>
Instance::SelectPreferredPhysicalDevice(
  PhysicalDevice::Type_t physicalDeviceType) const
{
  assert(
    IsFalse(physicalDevices.empty()) && "No physical devices are available");

  for (auto const& physicalDevice : physicalDevices) {
    if (physicalDevice.Type() == physicalDeviceType) {
      return std::reference_wrapper<PhysicalDevice const>{ physicalDevice };
    }
  }

  return {};
}

////////////////////////////////////////////////////////////////////////////////
// Free functions
////////////////////////////////////////////////////////////////////////////////

std::vector<VkExtensionProperties>
EnumerateInstanceExtensions()
{
  return EnumerateInstanceExtensions({});
}

std::vector<VkExtensionProperties>
EnumerateInstanceExtensions(std::optional<std::string> const& layerName)
{
  // clang-format off
  assert(
    IsInstance(vkEnumerateInstanceExtensionProperties) &&
    "vkEnumerateInstanceExtensionProperties is not initialized. Were Vulkan function pointers properly loaded?");
  // clang-fomrat on

  char const* layerName_cstr = nullptr;
  if (layerName) {
    layerName_cstr = layerName.value().c_str();
  }

  auto instanceExtensionCount = 0U;
  if (vkCallSuccess(vkEnumerateInstanceExtensionProperties(
        layerName_cstr, &instanceExtensionCount, nullptr))) {
    std::vector<VkExtensionProperties> instanceExtensions(instanceExtensionCount);
    if (vkCallSuccess(vkEnumerateInstanceExtensionProperties(
          layerName_cstr,
          &instanceExtensionCount,
          instanceExtensions.data()))) {
      return instanceExtensions;
    }
  }

  return {};
}

std::vector<VkLayerProperties>
EnumerateInstanceLayers()
{
  // clang-format off
  assert(
    IsInstance(vkEnumerateInstanceLayerProperties) &&
    "vkEnumerateInstanceLayerProperties is not initialized. Were Vulkan function pointers properly loaded?");
  // clang-fomrat on

  auto instanceLayerCount = 0U;
  if (vkCallSuccess(
        vkEnumerateInstanceLayerProperties(&instanceLayerCount, nullptr))) {
    std::vector<VkLayerProperties> instanceLayers(instanceLayerCount);
    if (vkCallSuccess(vkEnumerateInstanceLayerProperties(
          &instanceLayerCount, instanceLayers.data()))) {
      return instanceLayers;
    }
  }

  return {};
}

NAMESPACE_END(Renderer::Graphics)

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

////////////////////////////////////////////////////////////////////////////////
// Macros
////////////////////////////////////////////////////////////////////////////////

#if !defined(GetGRIProp)
/// <summary>
/// Returns a property of <c>GraphicsRenderer_Interface.</c>
/// </summary>
#  define GetGRIProp(PropertyName)                                             \
    GraphicsRenderer_InterfaceAccessor::PropertyName(graphicsRenderer)
#else
#  error GetGRIProp is already defined!
#endif

////////////////////////////////////////////////////////////////////////////////

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
  auto& vulkanDevice = GetGRIProp(HostPlatform).GPUDevice_Vulkan();
  // Load the global level function pointers
  gladLoadVulkanUserPtr(
    nullptr,
    reinterpret_cast<GLADuserptrloadfunc>(
      vulkanDevice.GetInstanceProcAddress()),
    nullptr);

  // Create Vulkan instance
  auto const& applicationInfo = GetGRIProp(ApplicationInfo);
  auto const& engineInfo = GetGRIProp(EngineInfo);

  VkApplicationInfo vulkanApplicationInfo{
    .sType = VK_STRUCTURE_TYPE_APPLICATION_INFO,
    .pNext = nullptr,
    .pApplicationName = applicationInfo.Title().c_str(),
    .applicationVersion = applicationInfo.GetVersion().AsNumber(),
    .pEngineName = engineInfo.Title().c_str(),
    .engineVersion = engineInfo.GetVersion().AsNumber(),
    .apiVersion = VK_API_VERSION_1_1,
  };

  auto const& layersToEnable = GetLayerNamesToEnable();
  auto const& extensionNamesToEnable = GetExtensionNamesToEnable();

  // Check if enough extensions are available (the surface creation extensions
  // are the minimum requirement)
  if (0ULL < extensionNamesToEnable.size()) {
    VkInstanceCreateInfo instanceCreateInfo{
      .sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
      .pNext = nullptr,
      .flags = 0L,
      .pApplicationInfo = &vulkanApplicationInfo,
      .enabledLayerCount = static_cast<std::uint32_t>(layersToEnable.size()),
      .ppEnabledLayerNames = layersToEnable.data(),
      .enabledExtensionCount =
        static_cast<std::uint32_t>(extensionNamesToEnable.size()),
      .ppEnabledExtensionNames = extensionNamesToEnable.data(),
    };

    if (vkCallSuccess(
          vkCreateInstance(&instanceCreateInfo, nullptr, &instance))) {
      // Load the instance level function pointers
      gladLoadVulkanUserPtr(
        nullptr,
        reinterpret_cast<GLADuserptrloadfunc>(
          vulkanDevice.GetInstanceProcAddress()),
        instance);
    }

    assert(IsInstance(instance) && "Vulkan instance is not initialized!");
  }
}

std::vector<char const*>
Instance::GetExtensionNamesToEnable() const
{
  auto& vulkanDevice = GetGRIProp(HostPlatform).GPUDevice_Vulkan();
  auto const& surfaceExtenionNames =
    vulkanDevice.SurfaceCreationExtensionNames();

  std::vector<char const*> extensionNamesToEnable;
  // Check if surface extensions are available:
  //   VK_KHR_surface
  //   VK_KHR_<platform>_surface
  // which are the required minimum for the graphics renderer
  if (2ULL <= surfaceExtenionNames.size()) {
    for (auto extensionName : surfaceExtenionNames) {
      extensionNamesToEnable.push_back(extensionName);
    }

    return extensionNamesToEnable;
  }

  return {};
}

std::vector<char const*>
Instance::GetLayerNamesToEnable() const
{
  auto const& rendererFeatures = GetGRIProp(CommandLineArgs).RendererFeatures();
  auto debugFeature = std::find(
    rendererFeatures.begin(),
    rendererFeatures.end(),
    System::DeviceTypes::Graphics::APIFeatures_t::Debug);

  if (debugFeature != rendererFeatures.end()) {
    return GetRequiredLayerNames();
  }

  return {};
}

std::vector<char const*>
Instance::GetRequiredLayerNames() const
{
  std::vector<char const*> availableLayers;
  auto& vulkanDevice = GetGRIProp(HostPlatform).GPUDevice_Vulkan();
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

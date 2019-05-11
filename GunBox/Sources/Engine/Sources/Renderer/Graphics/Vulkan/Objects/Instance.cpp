// Self
#include "Instance.hpp"

//// Project headers - Application
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
    static_cast<GLADuserptrloadfunc>(vulkanDevice.InstanceProcAddress()),
    nullptr);

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

  auto& surfaceCreationExtensions = vulkanDevice.SurfaceCreationExtensions();
  if (2LL <= vulkanDevice.SurfaceCreationExtensions().size()) {
    VkInstanceCreateInfo instanceCreateInfo{
      .sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
      .pNext = nullptr,
      .flags = 0L,
      .pApplicationInfo = &vulkanApplicationInfo,
      .enabledLayerCount = 0L,
      .ppEnabledLayerNames = nullptr,
      .enabledExtensionCount = static_cast<std::uint32_t>(
        vulkanDevice.SurfaceCreationExtensions().size()),
      .ppEnabledExtensionNames =
        vulkanDevice.SurfaceCreationExtensions().data(),
    };
    if (vkCallSuccess(
          vkCreateInstance(&instanceCreateInfo, nullptr, &instance))) {
      gladLoadVulkanUserPtr(
        nullptr,
        static_cast<GLADuserptrloadfunc>(vulkanDevice.InstanceProcAddress()),
        instance);
    }
  }
}

void
Instance::EnumeratePhysicalDevices()
{
  physicalDevices =
    Renderer::Graphics::EnumeratePhysicalDevices<PhysicalDevice>(*this);
}

////////////////////////////////////////////////////////////////////////////////
// Free functions
////////////////////////////////////////////////////////////////////////////////

std::vector<VkExtensionProperties>
EnumerateInstanceExtensions(std::optional<std::string> layerName)
{
  char const* layerName_cstr = nullptr;
  if (layerName) {
    layerName_cstr = layerName.value().c_str();
  }

  auto instanceExtensionCount = 0U;
  if (vkCallSuccess(vkEnumerateInstanceExtensionProperties(
        layerName_cstr, &instanceExtensionCount, nullptr))) {
    std::vector<VkExtensionProperties> instanceExtensions(0);
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
  auto instanceLayerCount = 0U;
  if (vkCallSuccess(
        vkEnumerateInstanceLayerProperties(&instanceLayerCount, nullptr))) {
    std::vector<VkLayerProperties> instanceLayers(0);
    if (vkCallFail(vkEnumerateInstanceLayerProperties(
          &instanceLayerCount, instanceLayers.data()))) {
      return instanceLayers;
    }
  }

  return {};
}

NAMESPACE_END(Renderer::Graphics)

// Self
#include "GraphicsRenderer_Vulkan.hpp"

// Project headers - Application
#include "Application/ModuleInfo.hpp"
// Project headers - Logger
#include "Logger/LogAPI.hpp"
// Project headers - System
#include "System/HostPlatform.hpp"

#include "glad/vulkan.h"

// C Standard Library
#include <cassert>

////////////////////////////////////////////////////////////////////////////////
// Macros
////////////////////////////////////////////////////////////////////////////////

#define vk_(x) (VK_SUCCESS == x)

NAMESPACE_BEGIN(Renderer::Graphics)

////////////////////////////////////////////////////////////////////////////////
// Constructors & Destructors
////////////////////////////////////////////////////////////////////////////////

GraphicsRenderer_Vulkan::GraphicsRenderer_Vulkan(
  Application::ApplicationInfo const& applicationInfo,
  Application::EngineInfo const& engineInfo,
  Application::Preferences& preferences,
  System::HostPlatform& hostPlatform)
  : GraphicsRenderer_Interface{ applicationInfo,
                                engineInfo,
                                preferences,
                                hostPlatform }
{}

GraphicsRenderer_Vulkan::~GraphicsRenderer_Vulkan() {}

////////////////////////////////////////////////////////////////////////////////
// Methods
////////////////////////////////////////////////////////////////////////////////

void
GraphicsRenderer_Vulkan::Finalize()
{
  hostPlatform.GPUDevice_Vulkan().Finalize();
  gladLoaderUnloadVulkan();
  GraphicsRenderer_Interface::Finalize();
}

bool
GraphicsRenderer_Vulkan::Initialize()
{
  assert(!isInitialized && "Renderer is already initialized!");

  auto isSuccess = GraphicsRenderer_Interface::Initialize();
  if (isSuccess) {
    auto& GPUDevice_Vulkan = hostPlatform.GPUDevice_Vulkan();
    isSuccess = GPUDevice_Vulkan.Initialize(*window);
    if (isSuccess) {
      auto& surfaceCreationExtensions =
        GPUDevice_Vulkan.SurfaceCreationExtensions();
      if (2 >= surfaceCreationExtensions.size()) {
        auto version = gladLoaderLoadVulkan(nullptr, nullptr, nullptr);
        if (0 < version) {
          reLogI("Graphics Renderer: OpenGL");
          reLogI("  Surface creation extensions:");
          for (auto extension : surfaceCreationExtensions) {
            reLogI("    ", extension);
          }

          std::uint32_t vkVersion = 0L;
          vkEnumerateInstanceVersion(&vkVersion);
          std::uint32_t instanceLayerCount;
          vkEnumerateInstanceLayerProperties(&instanceLayerCount, nullptr);
          std::vector<VkLayerProperties> instanceLayers;
          instanceLayers.resize(instanceLayerCount);
          vkEnumerateInstanceLayerProperties(
            &instanceLayerCount, instanceLayers.data());

          reLogI("  Instance layers:");
          for (auto layer : instanceLayers) {
            reLogI("    ", layer.layerName);
          }

          std::uint32_t instanceExtensionCount;
          vkEnumerateInstanceExtensionProperties(
            nullptr, &instanceExtensionCount, nullptr);
          std::vector<VkExtensionProperties> instanceExtensions;
          instanceExtensions.resize(instanceExtensionCount);
          auto result = vkEnumerateInstanceExtensionProperties(
            nullptr, &instanceExtensionCount, instanceExtensions.data());

          reLogI("  Instance extensions:");
          for (auto extension : instanceExtensions) {
            reLogI("    ", extension.extensionName);
          }

          VkApplicationInfo applicationInfo{
            .sType = VK_STRUCTURE_TYPE_APPLICATION_INFO,
            .pNext = nullptr,
            .pApplicationName = this->applicationInfo.Title().c_str(),
            .applicationVersion = this->applicationInfo.GetVersion().AsNumber(),
            .pEngineName = this->engineInfo.Title().c_str(),
            .engineVersion = this->engineInfo.GetVersion().AsNumber(),
            .apiVersion = VK_API_VERSION_1_1,
          };
          VkInstanceCreateInfo instanceCreateInfo{
            .sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
            .pNext = nullptr,
            .flags = 0L,
            .pApplicationInfo = &applicationInfo,
            .enabledLayerCount = 0L,
            .ppEnabledLayerNames = nullptr,
            .enabledExtensionCount =
              static_cast<std::uint32_t>(surfaceCreationExtensions.size()),
            .ppEnabledExtensionNames = surfaceCreationExtensions.data(),
          };
          VkInstance instance = nullptr;
          if (vk_(vkCreateInstance(&instanceCreateInfo, nullptr, &instance))) {
            std::uint32_t physicalDeviceGroupCount = 0L;
            std::vector<VkPhysicalDeviceGroupProperties> physicalDeviceGroups;
            if (vk_(vkEnumeratePhysicalDeviceGroups(
                  instance, &physicalDeviceGroupCount, nullptr))) {
              physicalDeviceGroups.resize(physicalDeviceGroupCount);
              vkEnumeratePhysicalDeviceGroups(
                instance,
                &physicalDeviceGroupCount,
                physicalDeviceGroups.data());
            }
            std::uint32_t physicalDeviceCount = 0L;
            std::vector<VkPhysicalDevice> physicalDevices;
            std::vector<VkPhysicalDeviceProperties> physicalDeviceProperties;
            if (vk_(vkEnumeratePhysicalDevices(
                  instance, &physicalDeviceCount, nullptr))) {
              physicalDevices.resize(physicalDeviceCount);
              vkEnumeratePhysicalDevices(
                instance, &physicalDeviceCount, physicalDevices.data());

              physicalDeviceProperties.resize(physicalDeviceCount);
              size_t i = 0LL;
              for (auto physicalDevice : physicalDevices) {
                vkGetPhysicalDeviceProperties(
                  physicalDevice, &physicalDeviceProperties[i++]);
              }

              auto DeviceTypeAsString =
                [](VkPhysicalDeviceType physicalDeviceType) {
                  using namespace std::string_literals;
                  switch (physicalDeviceType) {
                    case VK_PHYSICAL_DEVICE_TYPE_OTHER:
                      return "Other"s;
                    case VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU:
                      return "Integrated GPU"s;
                    case VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU:
                      return "Discrete GPU"s;
                    case VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU:
                      return "Virtual GPU"s;
                    case VK_PHYSICAL_DEVICE_TYPE_CPU:
                      return "CPU"s;
                    default:
                      return "Unnown Vulkan device"s;
                  }
                };
              auto ApiVersionAsString = [](std::uint32_t apiVersion) {
                auto major = apiVersion >> 22 & 0x3ff;
                auto minor = apiVersion >> 12 & 0x3ff;
                auto patch = apiVersion & 0x3ff;

                std::stringstream ss;
                ss << major << "." << minor << "." << patch;

                return ss.str();
              };

              reLogI("  Physical devices:");
              for (auto& physicalDevice : physicalDeviceProperties) {
                reLogI("    deviceName:      ", physicalDevice.deviceName);
                reLogI(
                  "      deviceType:    ",
                  DeviceTypeAsString(physicalDevice.deviceType));
                reLogI(
                  "      apiVersion:    ",
                  ApiVersionAsString(physicalDevice.apiVersion));
                reLogI("      driverVersion: ", physicalDevice.driverVersion);
                reLogI("      vendorID:      ", physicalDevice.vendorID);
                reLogI("      deviceID:      ", physicalDevice.deviceID);
                // reLogI("    ", physicalDevice.limits);
                // reLogI("    ", physicalDevice.pipelineCacheUUID);
                // reLogI("    ", physicalDevice.sparseProperties);
              }

              isInitialized = true;

              return isInitialized;
            }
          } else {
            reLogE("Failed to enumerate physical devices!");
          }
        } else {
          reLogE("Failed to create Vulkan instance!");
        }
      } else {
        reLogE("Failed to load Vulkan function pointers!");
      }
    } else {
      reLogE("No Vulkan surfrace creation extensions are available!");
    }
  }

  isInitialized = false;

  return isInitialized;
}

void
GraphicsRenderer_Vulkan::Render()
{}

NAMESPACE_END(Renderer::Graphics)

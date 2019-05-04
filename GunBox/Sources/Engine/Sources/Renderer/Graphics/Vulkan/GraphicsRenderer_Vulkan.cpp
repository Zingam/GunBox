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

#define _vk(x) (VK_SUCCESS == x)

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
            .apiVersion = VK_MAKE_VERSION(1, 1, 0),
          };
          VkInstanceCreateInfo instanceCreateInfo{
            .sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
            .pNext = nullptr,
            .flags = 0,
            .pApplicationInfo = &applicationInfo,
            .enabledLayerCount = 0L,
            .ppEnabledLayerNames = nullptr,
            .enabledExtensionCount = 0L,
            .ppEnabledExtensionNames = nullptr,
          };
          VkInstance instance = nullptr;
          if (_vk(vkCreateInstance(&instanceCreateInfo, nullptr, &instance))) {
            isInitialized = true;

            return isInitialized;
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
  }

  isInitialized = false;

  return isInitialized;
}

void
GraphicsRenderer_Vulkan::Render()
{}

NAMESPACE_END(Renderer::Graphics)

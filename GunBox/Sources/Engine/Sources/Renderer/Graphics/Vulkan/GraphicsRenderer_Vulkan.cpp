// Self
#include "GraphicsRenderer_Vulkan.hpp"

// Project headers - Application
#include "Application/ModuleInfo.hpp"
// Project headers - Logger
#include "Logger/LogAPI.hpp"
// Project headers - Renderer
#include "Renderer/Graphics/Vulkan/Objects/Instance.hpp"
// Project headers - System
#include "System/HostPlatform.hpp"

// C Standard Library
#include <cassert>

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

  // Create window
  auto isSuccess = GraphicsRenderer_Interface::Initialize();
  if (isSuccess) {
    auto& GPUDevice_Vulkan = hostPlatform.GPUDevice_Vulkan();
    isSuccess = GPUDevice_Vulkan.Initialize(*window);
    if (isSuccess) {
      instance = std::make_unique<Instance>(*this);
      instance->EnumeratePhysicalDevices();
      auto& physicalDevices = instance->PhysicalDevices();
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

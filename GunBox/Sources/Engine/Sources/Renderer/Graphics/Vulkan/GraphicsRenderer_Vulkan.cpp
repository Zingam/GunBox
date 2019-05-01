// Self
#include "GraphicsRenderer_Vulkan.hpp"

// Project headers - Logger
#include "Logger/LogAPI.hpp"
// Project headers - System
#include "System/HostPlatform.hpp"

// C Standard Library
#include <cassert>

NAMESPACE_BEGIN(Renderer::Graphics)

////////////////////////////////////////////////////////////////////////////////
// Constructors & Destructors
////////////////////////////////////////////////////////////////////////////////

GraphicsRenderer_Vulkan::GraphicsRenderer_Vulkan(
  Application::ApplicationInfo const& info,
  Application::Preferences& preferences,
  System::HostPlatform& hostPlatform)
  : GraphicsRenderer_Interface{ info, preferences, hostPlatform }
{}

GraphicsRenderer_Vulkan::~GraphicsRenderer_Vulkan() {}

////////////////////////////////////////////////////////////////////////////////
// Methods
////////////////////////////////////////////////////////////////////////////////

void
GraphicsRenderer_Vulkan::Finalize()
{
  hostPlatform.VulkanDevice().Finalize();

  GraphicsRenderer_Interface::Finalize();
}

bool
GraphicsRenderer_Vulkan::Initialize()
{
  assert(!isInitialized && "Renderer is already initialized!");

  auto& vulkanDevice = hostPlatform.VulkanDevice();
  auto isSuccess = vulkanDevice.Initialize(*window);
  if (isSuccess) {
    isSuccess = GraphicsRenderer_Interface::Initialize();
    if (isSuccess) {
      isInitialized = true;

      return isInitialized;
    }
  }

  isInitialized = false;

  return isInitialized;
}

void
GraphicsRenderer_Vulkan::Render()
{}

NAMESPACE_END(Renderer::Graphics)

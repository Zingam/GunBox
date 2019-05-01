// Self
#include "GraphicsRendererFactory.hpp"

// Project headers - Application
#include "Application/ApplicationInfo.hpp"
#include "Application/Preferences.hpp"
// Project headers - Renderer/Graphics
#include "Renderer/Graphics/GraphicsRenderer_Interface.hpp"
#include "Renderer/Graphics/OpenGL/GraphicsRenderer_OpenGL.hpp"
#include "Renderer/Graphics/Vulkan/GraphicsRenderer_Vulkan.hpp"

// C Standard Library
#include <cassert>

NAMESPACE_BEGIN(Renderer::Graphics)

std::unique_ptr<GraphicsRenderer_Interface>
Create(
  Application::ApplicationInfo const& info,
  Application::Preferences& preferences,
  System::HostPlatform& hostPlatform)
{
  std::unique_ptr<GraphicsRenderer_Interface> graphicsRenderer;
  switch (preferences.RendererAPI()) {
    case System::DeviceTypes::Graphics::API_t::OpenGL: {
      graphicsRenderer.reset(
        new GraphicsRenderer_OpenGL(info, preferences, hostPlatform));
      break;
    }
    case System::DeviceTypes::Graphics::API_t::Vulkan: {
      graphicsRenderer.reset(
        new GraphicsRenderer_Vulkan(info, preferences, hostPlatform));
      break;
    }
    default: {
      assert((0 && "Unknown Graphics API type"));
    }
  }

  return graphicsRenderer;
};

NAMESPACE_END(Renderer::Graphics)

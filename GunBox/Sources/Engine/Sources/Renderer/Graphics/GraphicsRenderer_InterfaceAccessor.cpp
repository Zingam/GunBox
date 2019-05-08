// Self
#include "GraphicsRenderer_InterfaceAccessor.hpp"

NAMESPACE_BEGIN(Renderer::Graphics)

////////////////////////////////////////////////////////////////////////////////
// Static methods
////////////////////////////////////////////////////////////////////////////////

Application::ApplicationInfo const&
GraphicsRenderer_InterfaceAccessor::ApplicationInfo(
  GraphicsRenderer_Interface const& graphicsRenderer)
{
  return graphicsRenderer.applicationInfo;
}

Application::EngineInfo const&
GraphicsRenderer_InterfaceAccessor::EngineInfo(
  GraphicsRenderer_Interface const& graphicsRenderer)
{
  return graphicsRenderer.engineInfo;
}

System::HostPlatform&
GraphicsRenderer_InterfaceAccessor::HostPlatform(
  GraphicsRenderer_Interface const& graphicsRenderer)
{
  return graphicsRenderer.hostPlatform;
}

NAMESPACE_END(Renderer::Graphics)

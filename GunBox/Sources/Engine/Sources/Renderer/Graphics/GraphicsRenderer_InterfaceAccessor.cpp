// Self
#include "GraphicsRenderer_InterfaceAccessor.hpp"

#include "Application/CommandLineArgs.hpp"
#include "Application/CoreApplication.hpp"
#include "Application/ModuleInfo.hpp"

NAMESPACE_BEGIN(Renderer::Graphics)

////////////////////////////////////////////////////////////////////////////////
// Static methods
////////////////////////////////////////////////////////////////////////////////

Application::ApplicationInfo const&
GraphicsRenderer_InterfaceAccessor::ApplicationInfo(
  GraphicsRenderer_Interface const& graphicsRenderer)
{
  return graphicsRenderer.coreApplication.GetApplicationInfo();
}

Application::CommandLineArgs const&
GraphicsRenderer_InterfaceAccessor::CommandLineArgs(
  GraphicsRenderer_Interface const& graphicsRenderer)
{
  return graphicsRenderer.coreApplication.GetCommandLineArgs();
}

Application::EngineInfo const&
GraphicsRenderer_InterfaceAccessor::EngineInfo(
  GraphicsRenderer_Interface const& graphicsRenderer)
{
  return graphicsRenderer.coreApplication.GetEngineInfo();
}

System::HostPlatform&
GraphicsRenderer_InterfaceAccessor::HostPlatform(
  GraphicsRenderer_Interface const& graphicsRenderer)
{
  return graphicsRenderer.hostPlatform;
}

NAMESPACE_END(Renderer::Graphics)

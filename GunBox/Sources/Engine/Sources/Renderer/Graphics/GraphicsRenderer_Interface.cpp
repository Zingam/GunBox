// Self
#include "GraphicsRenderer_Interface.hpp"

// Project headers - Application
#include "Application/ApplicationInfo.hpp"
#include "Application/Preferences.hpp"
// Project headers - System
#include "System/HostPlatform.hpp"

NAMESPACE_BEGIN(Renderer::Graphics)

////////////////////////////////////////////////////////////////////////////////
// Constructors & Destructors
////////////////////////////////////////////////////////////////////////////////

GraphicsRenderer_Interface::GraphicsRenderer_Interface(
  Application::ApplicationInfo const& applicationInfo,
  Application::Preferences& preferences,
  System::HostPlatform& hostPlatform)
  : hostPlatform{ hostPlatform }
  , preferences{ preferences }
  , window{ std::make_unique<System::Window>(
      applicationInfo.Title(),
      this->MakeWindowProperties(preferences)) }
{}

GraphicsRenderer_Interface::~GraphicsRenderer_Interface() {}

auto
GraphicsRenderer_Interface::Initialize() -> bool
{
  return window->Show();
}

auto
GraphicsRenderer_Interface::Finalize() -> void
{
  auto position = window->Position();
  preferences.MainWindowMetrics().Coordinate.X = position.X;
  preferences.MainWindowMetrics().Coordinate.Y = position.Y;

  hostPlatform.OpenGLDevice().Finalize();
}

auto
GraphicsRenderer_Interface::MakeWindowProperties(
  Application::Preferences& preferences) -> System::Window::Properties
{
  System::Window::Properties properties{};
  properties.Coordinate.X = preferences.MainWindowMetrics().Coordinate.X;
  properties.Coordinate.Y = preferences.MainWindowMetrics().Coordinate.Y;
  if (preferences.Fullscreen()) {
    properties.Fullscreen =
      System::Window::Properties::FullscreenState_t::Desktop;
  } else {
    properties.Fullscreen =
      System::Window::Properties::FullscreenState_t::Windowed;
  }
  if (preferences.SuccesfullyLoaded()) {
    properties.Location = System::Window::Properties::Location_t::Custom;
  } else {
    properties.Location = System::Window::Properties::Location_t::Centered;
  }
  properties.RendererAPI = preferences.RendererAPI();
  properties.Size.Height = preferences.MainWindowMetrics().Size.Height;
  properties.Size.Width = preferences.MainWindowMetrics().Size.Width;

  return properties;
}

NAMESPACE_END(Renderer::Graphics)

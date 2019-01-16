// Self
#include "GraphicsRenderer_Interface.hpp"

// Project headers - Application
#include "Application/ApplicationInfo.hpp"
#include "Application/Preferences.hpp"
// Project headers - System
#include "System/HostPlatform.hpp"

// C Standard Library
#include <cassert>

NAMESPACE_BEGIN(Renderer::Graphics)

////////////////////////////////////////////////////////////////////////////////
// Constructors & Destructors
////////////////////////////////////////////////////////////////////////////////

GraphicsRenderer_Interface::GraphicsRenderer_Interface(
  Application::ApplicationInfo const& applicationInfo,
  Application::Preferences& preferences,
  System::HostPlatform& hostPlatform)
  : hostPlatform{ hostPlatform }
  , window{ std::make_unique<System::Window>(
      applicationInfo.Title(),
      this->MakeWindowProperties(preferences)) }
  , preferences{ preferences }
{}

GraphicsRenderer_Interface::~GraphicsRenderer_Interface() {}

bool
GraphicsRenderer_Interface::Initialize()
{
  assert(!isInitialized && "Renderer is already initialized!");

  isInitialized = true;

  return window->Show();
}

void
GraphicsRenderer_Interface::Finalize()
{
  auto position = window->Position();
  preferences.MainWindowMetrics().Coordinate.X = position.X;
  preferences.MainWindowMetrics().Coordinate.Y = position.Y;
}

System::Window::Properties
GraphicsRenderer_Interface::MakeWindowProperties(
  Application::Preferences& preferences)
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

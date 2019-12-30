// Self
#include "GraphicsRenderer_Interface.hpp"

// Project headers - Application
#include "Application/CoreApplication.hpp"
#include "Application/ModuleInfo.hpp"
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
  Application::CoreApplication const& coreApplication,
  Application::Preferences& preferences,
  System::HostPlatform& hostPlatform)
  : coreApplication{ coreApplication }
  , hostPlatform{ hostPlatform }
  , window{ std::make_unique<System::Window>(
      coreApplication.GetApplicationInfo().Title(),
      this->MakeWindowProperties(preferences)) }
  , preferences{ preferences }
{}

GraphicsRenderer_Interface::~GraphicsRenderer_Interface() {}

////////////////////////////////////////////////////////////////////////////////
// Methods
////////////////////////////////////////////////////////////////////////////////

bool
GraphicsRenderer_Interface::Initialize()
{
  assert(!isInitialized && "Renderer is already initialized!");

  return window->Show();
}

void
GraphicsRenderer_Interface::Finalize()
{
  auto position = window->Position();
  auto& mainWindowMetrics = preferences.MainWindowMetrics();
  mainWindowMetrics.Coordinate.X = position.X;
  mainWindowMetrics.Coordinate.Y = position.Y;
}

System::Window::Properties
GraphicsRenderer_Interface::MakeWindowProperties(
  Application::Preferences const& preferences) const
{
  System::Window::Properties properties{};
  auto mainWindowMetrics = preferences.MainWindowMetrics();
  properties.Coordinate.X = mainWindowMetrics.Coordinate.X;
  properties.Coordinate.Y = mainWindowMetrics.Coordinate.Y;
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
  properties.Size.Height = mainWindowMetrics.Size.Height;
  properties.Size.Width = mainWindowMetrics.Size.Width;

  return properties;
}

NAMESPACE_END(Renderer::Graphics)

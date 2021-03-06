#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

// Project headers - System
#include "System/DeviceTypes/Graphics/RendererTypes.hpp"
#include "System/GUI/Window.hpp"

// C++ Standard Library
#include <memory>

////////////////////////////////////////////////////////////////////////////////
// Forward declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(Application)

class CoreApplication;
class Preferences;

NAMESPACE_END(Application)

NAMESPACE_BEGIN(Renderer::Graphics)

class GraphicsRenderer_InterfaceAccessor;

NAMESPACE_END(Renderer::Graphics)

NAMESPACE_BEGIN(System)

class HostPlatform;

NAMESPACE_END(System)

////////////////////////////////////////////////////////////////////////////////
// Class declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(Renderer::Graphics)

class GraphicsRenderer_Interface
{
protected:
  GraphicsRenderer_Interface(
    Application::CoreApplication const& coreApplication,
    Application::Preferences& preferences,
    System::HostPlatform& hostPlatform);

public:
  virtual ~GraphicsRenderer_Interface() = 0;

public:
  virtual auto Initialize() -> bool;
  virtual auto Finalize() -> void;
  virtual auto Render() -> void = 0;

private:
  auto MakeWindowProperties(Application::Preferences const& preferences) const
    -> System::Window::Properties;

protected:
  Application::CoreApplication const& coreApplication;
  System::HostPlatform& hostPlatform;
  bool isInitialized = false;
  std::unique_ptr<System::Window> window;

private:
  friend class Renderer::Graphics::GraphicsRenderer_InterfaceAccessor;

private:
  Application::Preferences& preferences;
};

////////////////////////////////////////////////////////////////////////////////
// Aliases
////////////////////////////////////////////////////////////////////////////////

using GraphicsRenderer_UPtr = std::unique_ptr<GraphicsRenderer_Interface>;
using GraphicsRenderer_SPtr = std::unique_ptr<GraphicsRenderer_Interface>;

NAMESPACE_END(Renderer::Graphics)

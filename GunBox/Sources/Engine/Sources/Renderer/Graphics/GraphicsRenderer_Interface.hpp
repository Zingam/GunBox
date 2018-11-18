#pragma once

// BASE MACROS header
#include "Common/Macros/Base.hpp"

// Project headers - System
#include "System/Window.hpp"

// C++ Standard Library
#include <memory>

////////////////////////////////////////////////////////////////////////////////
// Forward declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(Application)

class ApplicationInfo;
class Preferences;

NAMESPACE_END(Application)

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
    Application::ApplicationInfo const& applicationInfo,
    Application::Preferences& preferences,
    System::HostPlatform& hostPlatform);

public:
  virtual ~GraphicsRenderer_Interface() = 0;

public:
  virtual auto Initialize() -> bool;
  virtual auto Finalize() -> void;

private:
  auto MakeWindowProperties(Application::Preferences& preferences)
    -> System::Window::Properties;

protected:
  System::HostPlatform& hostPlatform;
  bool isInitialized = false;
  std::unique_ptr<System::Window> window;

private:
  Application::Preferences& preferences;
};

using GraphicsRenderer_UPtr = std::unique_ptr<GraphicsRenderer_Interface>;
using GraphicsRenderer_SPtr = std::unique_ptr<GraphicsRenderer_Interface>;

NAMESPACE_END(Renderer::Graphics)

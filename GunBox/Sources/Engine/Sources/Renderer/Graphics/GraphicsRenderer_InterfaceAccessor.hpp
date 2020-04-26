#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

// Engine headers - Renderer
#include "Renderer/Graphics/GraphicsRenderer_Interface.hpp"

// C++ Standard Library
#include <optional>

////////////////////////////////////////////////////////////////////////////////
// Forward declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(Application)

class ApplicationInfo;
class CommandLineArgs;
class EngineInfo;

NAMESPACE_END(Application)

NAMESPACE_BEGIN(Renderer::Graphics)

class Instance;

NAMESPACE_END(Renderer::Graphics)

////////////////////////////////////////////////////////////////////////////////
// Class declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(Renderer::Graphics)

class GraphicsRenderer_InterfaceAccessor
{
  // Static methods
private:
  // clang-format off
  static auto ApplicationInfo(GraphicsRenderer_Interface const& graphicsRenderer)
    -> Application::ApplicationInfo const&;
  static auto CommandLineArgs(GraphicsRenderer_Interface const& graphicsRenderer)
    -> std::optional<Application::CommandLineArgs> const&;
  static auto EngineInfo(GraphicsRenderer_Interface const& graphicsRenderer)
    -> Application::EngineInfo const&;
  static auto HostPlatform(GraphicsRenderer_Interface const& graphicsRenderer)
    -> System::HostPlatform&;
  // clang-format on

private:
  friend class Renderer::Graphics::Instance;
};

NAMESPACE_END(Renderer::Graphics)

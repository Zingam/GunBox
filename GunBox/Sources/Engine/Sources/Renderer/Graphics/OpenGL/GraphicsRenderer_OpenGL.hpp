#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

// Project headers - Renderer/Graphics
#include "Renderer/Graphics/GraphicsRenderer_Interface.hpp"

// C++ Standard Library
#include <memory>

////////////////////////////////////////////////////////////////////////////////
// Forward declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(Application)

class CoreApplication;
class Preferences;

NAMESPACE_END(Application)

NAMESPACE_BEGIN(System)

class HostPlatform;

NAMESPACE_END(System)

////////////////////////////////////////////////////////////////////////////////
// Class declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(Renderer::Graphics)

class GraphicsRenderer_OpenGL final : public GraphicsRenderer_Interface
{
  // Constructors & Destructors
private:
  GraphicsRenderer_OpenGL(
    Application::CoreApplication const& coreApplication,
    Application::Preferences& preferences,
    System::HostPlatform& hostPlatform);

public:
  ~GraphicsRenderer_OpenGL() final;

  // Methods
public:
  auto Initialize() -> bool final;
  auto Finalize() -> void final;
  auto Render() -> void final;

public:
  //friend std::unique_ptr<Renderer::Graphics::GraphicsRenderer_Interface> Create(
  //  Application::CoreApplication const& coreApplication,
  //  Application::Preferences& preferences,
  //  System::HostPlatform& hostPlatform);
  friend std::unique_ptr<GraphicsRenderer_Interface> Create(
    Application::CoreApplication const& coreApplication,
    Application::Preferences& preferences,
    System::HostPlatform& hostPlatform);
};

NAMESPACE_END(Renderer::Graphics)

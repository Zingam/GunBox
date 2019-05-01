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

class GraphicsRenderer_Vulkan final : public GraphicsRenderer_Interface
{
  // Constructors & Destructors
private:
  GraphicsRenderer_Vulkan(Application::ApplicationInfo const& info,
                          Application::Preferences& preferences,
                          System::HostPlatform& hostPlatform);

public:
  ~GraphicsRenderer_Vulkan() final;

  // Methods
public:
  auto Finalize() -> void final;
  auto Initialize() -> bool final;
  auto Render() -> void final;

public:
  friend std::unique_ptr<Renderer::Graphics::GraphicsRenderer_Interface> Create(
    Application::ApplicationInfo const& info,
    Application::Preferences& preferences,
    System::HostPlatform& hostPlatform);
};

NAMESPACE_END(Renderer::Graphics)

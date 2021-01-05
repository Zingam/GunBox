#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

// Project headers - Renderer/Graphics
#include "Renderer/Graphics/Vulkan/Objects/Instance.hpp"
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

class GraphicsRenderer_Vulkan final : public GraphicsRenderer_Interface
{
  // Constructors & Destructors
private:
  GraphicsRenderer_Vulkan(
    Application::CoreApplication const& coreApplication,
    Application::Preferences& preferences,
    System::HostPlatform& hostPlatform);

public:
  ~GraphicsRenderer_Vulkan() final;

  // Methods
public:
  auto SetupRenderingPipeLine() -> bool;

  // Virtual methods
public:
  auto Finalize() -> void final;
  auto Initialize() -> bool final;
  auto Render() -> void final;

  // Friend functions
public:
  friend std::unique_ptr<GraphicsRenderer_Interface> Create(
    Application::CoreApplication const& coreApplication,
    Application::Preferences& preferences,
    System::HostPlatform& hostPlatform);

  // Private data members
private:
  std::unique_ptr<Instance> instance;
};

NAMESPACE_END(Renderer::Graphics)

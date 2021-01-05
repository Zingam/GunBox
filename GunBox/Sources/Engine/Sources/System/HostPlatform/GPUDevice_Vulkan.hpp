#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

// Project headers - System
#include "System/Platforms/GPUDevice_Vulkan_Implementation.hpp"

// Project headers - Common
#include "Common/implementedBy.hpp"

// C++ Standard Library
#include <memory>
#include <vector>

////////////////////////////////////////////////////////////////////////////////
// Forward declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(Renderer::Graphics)

class Instance;
class Surface;

NAMESPACE_END(Renderer::Graphics)

NAMESPACE_BEGIN(System)

class Window;

NAMESPACE_END(System)

////////////////////////////////////////////////////////////////////////////////
// Class declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(System::HostPlatformClasses)

class GPUDevice_Vulkan : public implementedBy<GPUDevice_Vulkan_Implementation>
{
  // Properties
public:
  auto DebugExtensionNames() const -> std::vector<char const*> const&;
  auto GetInstanceProcAddress() const -> void*;
  auto InstanceExtensionNames() const -> std::vector<char const*> const&;
  auto SurfaceCreationExtensionNames() const -> std::vector<char const*> const&;
  auto ValidationLayerNames() const -> std::vector<char const*> const&;

  // Methods
public:
  auto EnumerateInstanceExtensions() -> bool;
  auto CreateSurface(
    Renderer::Graphics::Instance const& instance,
    System::Window const& window) const
    -> std::unique_ptr<Renderer::Graphics::Surface>;
  auto Initialize() -> bool;
  auto InstanceVersion() const -> std::optional<Version>;
};

NAMESPACE_END(System::HostPlatformClasses)

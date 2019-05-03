#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

// Project headers - System
#include "System/DeviceTypes/Graphics/RendererTypes.hpp"

// C++ Standard Library
#include <optional>
#include <string>
#include <vector>

////////////////////////////////////////////////////////////////////////////////
// Forward declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(System)

class Window;

NAMESPACE_END(System)

////////////////////////////////////////////////////////////////////////////////
// Class declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(System::HostPlatformClasses)

using GPUDevice_Vulkan_Implementation = class GPUDevice_Vulkan_SDL
{
  // Constructors & Destructors
public:
  GPUDevice_Vulkan_SDL();

  // Properties
public:
  auto InstanceProcAddress() const -> void*;
  auto SurfaceCreationExtensions() const -> std::vector<char const*> const&;

  // Methods
public:
  auto Finalize() -> void;
  auto Initialize(Window const& window) -> bool;

  // Data members
private:
  std::optional<std::string> errorStatus;
  std::string platformName;
  std::vector<char const*> surfaceCreationExtensions;
  Window const* window = nullptr;
};

NAMESPACE_END(System::HostPlatformClasses)

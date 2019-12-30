#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

// Project headers - System
#include "System/DeviceTypes/Graphics/RendererTypes.hpp"
#include "System/Platforms/GPUDevice_Vulkan_Base.hpp"

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

using GPUDevice_Vulkan_Implementation =
  class GPUDevice_Vulkan_SDL : protected GPUDevice_Vulkan_Base
{
  // Constructors & Destructors
public:
  GPUDevice_Vulkan_SDL();

  // Properties
public:
  auto DebugExtensionNames() const -> std::vector<char const*> const&;
  auto InstanceExtensionNames() const -> std::vector<char const*> const&;
  auto InstanceProcAddress() const -> void*;
  auto SurfaceCreationExtensionNames() const -> std::vector<char const*> const&;
  auto ValidationLayerNames() const -> std::vector<char const*> const&;

  // Methods
public:
  auto Finalize() -> void;
  auto Initialize(System::Window const& window) -> bool;

  // Data members
private:
  std::optional<std::string> errorStatus;
  std::string platformName;
  std::vector<char const*> surfaceCreationExtensionNames;
  System::Window const* window = nullptr;
};

NAMESPACE_END(System::HostPlatformClasses)

#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

// Project headers - System
#include "System/Platforms/GPUDevice_Vulkan_Implementation.hpp"

// Project headers - Common
#include "Common/implementedBy.hpp"

// C++ Standard Library
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

class GPUDevice_Vulkan : public implementedBy<GPUDevice_Vulkan_Implementation>
{
  // Properties
public:
  auto InstanceProcAddress() const -> void*;
  auto SurfaceCreationExtensions() const -> std::vector<char const*> const&;

  // Methods
public:
  auto Initialize(Window const& window) -> bool;
};

NAMESPACE_END(System::HostPlatformClasses)

#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

// Project headers - Common
#include "Common/Version.hpp"
// Project headers - System
#include "System/DeviceTypes/Graphics/RendererTypes.hpp"
#include "System/Platforms/GPUDevice_Vulkan_Base.hpp"

// C++ Standard Library
#include <memory>
#include <optional>
#include <string>
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
  auto InstanceVersion() const -> std::optional<Version>;
  auto SurfaceCreationExtensionNames() const -> std::vector<char const*> const&;
  auto ValidationLayerNames() const -> std::vector<char const*> const&;

  // Methods
public:
  // clang-format off
  auto EnumerateInstanceExtensions()
    -> bool;
  auto CreateSurface(Renderer::Graphics::Instance const& instance,
                     System::Window const& window) const
    -> std::unique_ptr<Renderer::Graphics::Surface>;
  auto Finalize()
    -> void;
  auto Initialize()
    -> bool;
  // clang-format on

  // Data members
private:
  std::optional<std::string> errorStatus;
  std::string platformName;
  std::vector<char const*> surfaceCreationExtensionNames;
  std::optional<Version> instanceVersion;
};

NAMESPACE_END(System::HostPlatformClasses)

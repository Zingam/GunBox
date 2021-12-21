#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

// Project headers - Renderer
#include "Renderer/Graphics/Vulkan/Vulkan.hpp"

// C Standard Library
#include <cstdint>
// C++ Standard Library
#include <memory>
#include <vector>

////////////////////////////////////////////////////////////////////////////////
// Forward declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(System)

class Window;

NAMESPACE_END(System)

NAMESPACE_BEGIN(Renderer::Graphics)

class Instance;
class PhysicalDevice;

NAMESPACE_END(Renderer::Graphics)

////////////////////////////////////////////////////////////////////////////////
// Class declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(Renderer::Graphics)

class Surface
{
public:
  Surface(System::Window const&, Instance const& instance, VkSurfaceKHR handle);
  ~Surface();

public:
  auto Get() const -> VkSurfaceKHR;

private:
  friend auto EnumerateSurfaceProperties(Surface&, PhysicalDevice const&)
    -> void;

private:
  VkSurfaceKHR const handle;
  Instance const& instance;
  System::Window const& window;
};

struct SurfaceInfo
{
  VkBool32 canPresent = VK_FALSE;
  VkSurfaceCapabilitiesKHR capabilities{};
  std::vector<VkSurfaceFormatKHR> formats;
  VkSurfaceKHR handle = nullptr;
  std::vector<VkPresentModeKHR> presentModes;
};

NAMESPACE_END(Renderer::Graphics)

////////////////////////////////////////////////////////////////////////////////
// Free functions
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(Renderer::Graphics)

// clang-format off
auto
EnumerateSurfaceProperties(Surface&, PhysicalDevice const&)
  -> void;
// clang-format on

NAMESPACE_END(Renderer::Graphics)

////////////////////////////////////////////////////////////////////////////////

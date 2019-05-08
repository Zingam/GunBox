#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

// Third party libraries
#include <glad/vulkan.h>

// C++ Standard Library
#include <optional>
#include <string>
#include <vector>

////////////////////////////////////////////////////////////////////////////////
// Forward declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(Renderer::Graphics)

class Instance;

NAMESPACE_END(Renderer::Graphics)

////////////////////////////////////////////////////////////////////////////////
// Class declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(Renderer::Graphics)

class PhysicalDevice
{
  // Constructors & Destructors
public:
  PhysicalDevice(Instance const& instance);
  PhysicalDevice(PhysicalDevice const&) = delete;

  // Properties
public:
  auto Get() const -> VkPhysicalDevice;

  // Private data members
private:
  Instance const& instance;
  VkPhysicalDevice physicalDevice = nullptr;
};

////////////////////////////////////////////////////////////////////////////////
// Free function declarations
////////////////////////////////////////////////////////////////////////////////

// clang-format off

auto
EnumeratePhysicalDevices(Instance const& instance)
  ->std::vector<VkPhysicalDevice>;

auto
EnumeratePhysicalDeviceProperties(PhysicalDevice const& physicalDevice)
  -> std::vector<VkPhysicalDeviceProperties>;

// clang-format on

NAMESPACE_END(Renderer::Graphics)

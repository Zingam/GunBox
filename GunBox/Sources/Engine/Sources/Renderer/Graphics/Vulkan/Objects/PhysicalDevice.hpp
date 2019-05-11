#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

// Project headers - Renderer
#include "Renderer/Graphics/Vulkan/Objects/QueueFamily.hpp"

// Third party libraries
#include <glad/vulkan.h>

// C++ Standard Library
#include <vector>

////////////////////////////////////////////////////////////////////////////////
// Class declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(Renderer::Graphics)
class Instance;

class PhysicalDevice
{
  // Constructors & Destructors
public:
  PhysicalDevice(
    Instance const& instance,
    VkPhysicalDevice const physicalDevice);

public:
  PhysicalDevice(PhysicalDevice const&) = delete;
  PhysicalDevice(PhysicalDevice&&) = default;

  // Properties
public:
  auto Get() const -> VkPhysicalDevice;

  // Private data members
private:
  Instance const& instance;
  VkPhysicalDevice const physicalDevice;
  VkPhysicalDeviceProperties properties;
  std::vector<QueueFamily> queueFamilies;
};

NAMESPACE_END(Renderer::Graphics)

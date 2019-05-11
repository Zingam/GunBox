#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

// Project headers - Renderer
#include "Renderer/Graphics/Vulkan/Objects/Instance.hpp"
#include "Renderer/Graphics/Vulkan/Objects/QueueFamily.hpp"
#include "Renderer/Graphics/Vulkan/Objects/Utilities/Utilities.hpp"

// Third party libraries
#include <glad/vulkan.h>

// C++ Standard Library
#include <vector>

////////////////////////////////////////////////////////////////////////////////
// Class declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(Renderer::Graphics)

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

////////////////////////////////////////////////////////////////////////////////
// Function templates
////////////////////////////////////////////////////////////////////////////////

template<typename T>
auto
EnumeratePhysicalDeviceQueueFamilies(PhysicalDevice const& physicalDevice)
  -> std::vector<T>;

template<>
auto
EnumeratePhysicalDeviceQueueFamilies(PhysicalDevice const& physicalDevice)
  -> std::vector<VkQueueFamilyProperties>;

template<>
auto
EnumeratePhysicalDeviceQueueFamilies(PhysicalDevice const& physicalDevice)
  -> std::vector<QueueFamily>;

template<typename T>
auto
EnumeratePhysicalDevices(Instance const& instance) -> std::vector<T>;

template<>
inline auto
EnumeratePhysicalDevices<VkPhysicalDevice>(Instance const& instance)
  -> std::vector<VkPhysicalDevice>;

template<>
inline auto
EnumeratePhysicalDevices<PhysicalDevice>(Instance const& instance)
  -> std::vector<PhysicalDevice>;

NAMESPACE_END(Renderer::Graphics)

////////////////////////////////////////////////////////////////////////////////
// Inline method implementations
////////////////////////////////////////////////////////////////////////////////

#include "PhysicalDevice.inl"

////////////////////////////////////////////////////////////////////////////////

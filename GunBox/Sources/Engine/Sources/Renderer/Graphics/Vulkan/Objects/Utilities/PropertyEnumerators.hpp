#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

// Project headers - Renderer/Graphics
#include "Renderer/Graphics/Vulkan/Objects/Instance.hpp"
#include "Renderer/Graphics/Vulkan/Objects/PhysicalDevice.hpp"

////////////////////////////////////////////////////////////////////////////////
// Function templates
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(Renderer::Graphics)

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

#include "PropertyEnumerators.inl"

////////////////////////////////////////////////////////////////////////////////

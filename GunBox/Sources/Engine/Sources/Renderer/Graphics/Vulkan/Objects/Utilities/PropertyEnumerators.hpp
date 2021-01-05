#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

// Project headers - Renderer/Graphics
#include "Renderer/Graphics/Vulkan/Objects/Instance.hpp"
#include "Renderer/Graphics/Vulkan/Objects/PhysicalDevice.hpp"

#include <type_traits>

////////////////////////////////////////////////////////////////////////////////
// Function templates
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(Renderer::Graphics::Vulkan::Objects::Utilities)

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

//template<typename T>
//auto
//EnumeratePhysicalDevices(Instance const& instance) -> std::vector<T>;

template<typename T>
inline auto
EnumeratePhysicalDevices(Instance const& instance)
  -> std::enable_if_t<std::is_same_v<T, VkPhysicalDevice>, std::vector<VkPhysicalDevice>>;

template<typename T>
inline auto
EnumeratePhysicalDevices(Instance const& instance)
  -> std::enable_if_t<std::is_same_v<T, PhysicalDevice>, std::vector<PhysicalDevice>>;

NAMESPACE_END(Renderer::Graphics::Vulkan::Objects::Utilities)

////////////////////////////////////////////////////////////////////////////////
// Inline method implementations
////////////////////////////////////////////////////////////////////////////////

#include "PropertyEnumerators.inl"

////////////////////////////////////////////////////////////////////////////////

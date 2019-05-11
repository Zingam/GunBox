#pragma once
////////////////////////////////////////////////////////////////////////////////
// Inline implementations
////////////////////////////////////////////////////////////////////////////////

// Project headers - Renderer
#include "Renderer/Graphics/Vulkan/Objects/Utilities/Utilities.hpp"

// C Standard Library
#include <cassert>
// C++ Standard Library
#include <type_traits>

NAMESPACE_BEGIN(Renderer::Graphics)

////////////////////////////////////////////////////////////////////////////////
// Function templates
////////////////////////////////////////////////////////////////////////////////

template<typename T>
inline std::vector<T>
EnumeratePhysicalDeviceQueueFamilies(PhysicalDevice const& physicalDevice)
{
  static_assert(
    std::is_same_v<T, VkQueueFamilyProperties> ||
      std::is_same_v<T, QueueFamily>,
    "Unsupported typename!");

  return std::vector<T>{};
}

template<>
inline std::vector<VkQueueFamilyProperties>
EnumeratePhysicalDeviceQueueFamilies<VkQueueFamilyProperties>(
  PhysicalDevice const& physicalDevice)
{
  assert(
    IsInstance(physicalDevice.Get()) && "Physical device is not initialized!");

  auto queueFamilyCount = 0U;
  vkGetPhysicalDeviceQueueFamilyProperties(
    physicalDevice.Get(), &queueFamilyCount, nullptr);
  if (0 < queueFamilyCount) {
    std::vector<VkQueueFamilyProperties> queueFamilies(queueFamilyCount);
    vkGetPhysicalDeviceQueueFamilyProperties(
      physicalDevice.Get(), &queueFamilyCount, queueFamilies.data());

    return queueFamilies;
  }

  return {};
}

template<>
inline std::vector<QueueFamily>
EnumeratePhysicalDeviceQueueFamilies(PhysicalDevice const& physicalDevice)

{
  assert(
    IsInstance(physicalDevice.Get()) && "Vulkan object is not initialized!");

  auto queueFamilyStructs =
    EnumeratePhysicalDeviceQueueFamilies<VkQueueFamilyProperties>(
      physicalDevice);
  std::vector<QueueFamily> queueFamilies;
  for (auto queueFamilyStruct : queueFamilyStructs) {
    queueFamilies.emplace_back(queueFamilyStruct);
  }

  return queueFamilies;
}

template<typename T>
inline std::vector<T>
EnumeratePhysicalDevices(Instance const& instance)
{
  static_assert(
    std::is_same_v<T, VkPhysicalDevice> || std::is_same_v<T, PhysicalDevice>,
    "Unsupported typename!");

  return std::vector<T>{};
}

template<>
inline auto
EnumeratePhysicalDevices<VkPhysicalDevice>(Instance const& instance)
  -> std::vector<VkPhysicalDevice>
{
  assert(
    IsInstance(instance.Get()) &&
    "Vulkan instance is not initialized!");

  std::uint32_t physicalDeviceCount = 0L;
  if (vkCallSuccess(vkEnumeratePhysicalDevices(
        instance.Get(), &physicalDeviceCount, nullptr))) {
    std::vector<VkPhysicalDevice> physicalDevices(physicalDeviceCount);
    if (vkCallSuccess(vkEnumeratePhysicalDevices(
          instance.Get(),
          &physicalDeviceCount,
          physicalDevices.data()))) {
      return physicalDevices;
    }
  }

  return {};
}

template<>
inline std::vector<PhysicalDevice>
EnumeratePhysicalDevices<PhysicalDevice>(Instance const& instance)

{
  auto physicalDeviceHandles =
    EnumeratePhysicalDevices<VkPhysicalDevice>(instance);
  std::vector<PhysicalDevice> physicalDevices;
  for (auto physicalDevice : physicalDeviceHandles) {
    physicalDevices.emplace_back(instance, physicalDevice);
  }

  return physicalDevices;
}

NAMESPACE_END(Renderer::Graphics)

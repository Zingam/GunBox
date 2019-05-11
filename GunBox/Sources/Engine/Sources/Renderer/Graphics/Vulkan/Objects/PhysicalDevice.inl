#pragma once
////////////////////////////////////////////////////////////////////////////////
// Inline implementations
////////////////////////////////////////////////////////////////////////////////

// C Standard Library
#include <cassert>
// C++ Standard Library
#include <type_traits>

NAMESPACE_BEGIN(Renderer::Graphics)

////////////////////////////////////////////////////////////////////////////////
// Function templates
////////////////////////////////////////////////////////////////////////////////

template<typename T>
inline auto
EnumeratePhysicalDeviceQueueFamilies(PhysicalDevice const& physicalDevice)
  -> std::vector<T>
{
  static_assert(
    std::is_same_v<T, VkQueueFamilyProperties> ||
      std::is_same_v<T, QueueFamily>,
    "Unsupported typename!");

  return std::vector<T>{};
}

template<>
inline auto
EnumeratePhysicalDeviceQueueFamilies<VkQueueFamilyProperties>(
  PhysicalDevice const& physicalDevice) -> std::vector<VkQueueFamilyProperties>
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
inline auto
EnumeratePhysicalDeviceQueueFamilies(PhysicalDevice const& physicalDevice)
  -> std::vector<QueueFamily>
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
auto
EnumeratePhysicalDevices(Instance const& instance) -> std::vector<T>
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
    IsInstance(instance.GetInstance()) &&
    "Vulkan instance is not initialized!");

  std::uint32_t physicalDeviceCount = 0L;
  if (vkCallSuccess(vkEnumeratePhysicalDevices(
        instance.GetInstance(), &physicalDeviceCount, nullptr))) {
    std::vector<VkPhysicalDevice> physicalDevices(physicalDeviceCount);
    if (vkCallSuccess(vkEnumeratePhysicalDevices(
          instance.GetInstance(),
          &physicalDeviceCount,
          physicalDevices.data()))) {
      return physicalDevices;
    }
  }

  return {};
}

template<>
inline auto
EnumeratePhysicalDevices<PhysicalDevice>(Instance const& instance)
  -> std::vector<PhysicalDevice>
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

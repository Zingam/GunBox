// Self
#include "PhysicalDevice.hpp"

// Project headers - Application
#include "Application/ModuleInfo.hpp"
// Project headers - Logger
#include "Logger/LogAPI.hpp"
// Project headers - Renderer
#include "Renderer/Graphics/Vulkan/Objects/Instance.hpp"
#include "Renderer/Graphics/Vulkan/Objects/Utilities/Utilities.hpp"
// Project headers - System
#include "System/HostPlatform.hpp"

// C Standard Library
#include <cassert>
#include <cstdint>

NAMESPACE_BEGIN(Renderer::Graphics)

////////////////////////////////////////////////////////////////////////////////
// Constructors & Destructors
////////////////////////////////////////////////////////////////////////////////

PhysicalDevice::PhysicalDevice(Instance const& instance)
  : instance{ instance }
{}

////////////////////////////////////////////////////////////////////////////////
// Free functions
////////////////////////////////////////////////////////////////////////////////

VkPhysicalDevice
PhysicalDevice::Get() const
{
  return this->physicalDevice;
}

////////////////////////////////////////////////////////////////////////////////
// Free functions
////////////////////////////////////////////////////////////////////////////////

std::vector<VkPhysicalDevice>
EnumeratePhysicalDevices(Instance const& instance)
{
  assert(!instance.GetInstance() && "Vulkan instance is not initialized!");

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

std::vector<VkQueueFamilyProperties>
GetPhysicalDeviceQueueProperties(PhysicalDevice const& physicalDevice)
{
  assert(!physicalDevice.Get() && "Physical device is not initialized!");

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

NAMESPACE_END(Renderer::Graphics)

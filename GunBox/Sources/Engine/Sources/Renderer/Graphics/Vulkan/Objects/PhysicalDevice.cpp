// Self
#include "PhysicalDevice.hpp"

// Project headers - Application
#include "Application/ModuleInfo.hpp"
// Project headers - Logger
#include "Logger/LogAPI.hpp"
// Project headers - Renderer
#include "Renderer/Graphics/Vulkan/Objects/Utilities/PropertyEnumerators.hpp"
// Project headers - System
#include "System/HostPlatform.hpp"

// C Standard Library
#include <cassert>
#include <cstdint>

NAMESPACE_BEGIN(Renderer::Graphics)

////////////////////////////////////////////////////////////////////////////////
// Constructors & Destructors
////////////////////////////////////////////////////////////////////////////////

PhysicalDevice::PhysicalDevice(
  Instance const& instance,
  VkPhysicalDevice physicalDevice)
  : instance{ instance }
  , physicalDevice{ physicalDevice }
{
  vkGetPhysicalDeviceProperties(physicalDevice, &properties);
  reLogI("  Physical device: ", properties.deviceName);
  reLogI("    name: ", properties.deviceName);
  reLogI("    type: ", properties.deviceType);

  queueFamilies = EnumeratePhysicalDeviceQueueFamilies<QueueFamily>(*this);
}

////////////////////////////////////////////////////////////////////////////////
// Free functions
////////////////////////////////////////////////////////////////////////////////

VkPhysicalDevice
PhysicalDevice::Get() const
{
  return this->physicalDevice;
}

NAMESPACE_END(Renderer::Graphics)

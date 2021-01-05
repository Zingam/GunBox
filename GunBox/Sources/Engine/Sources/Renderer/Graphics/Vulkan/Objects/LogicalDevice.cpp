// Self
#include "LogicalDevice.hpp"

#include "PhysicalDevice.hpp"

NAMESPACE_BEGIN(Renderer::Graphics)

LogicalDevice::LogicalDevice(
  PhysicalDevice const& physicalDevice,
  std::uint32_t const queueFamilyIndex)
  : physicalDevice{ physicalDevice }
{
  VkDeviceQueueCreateInfo queueCreateInfo{};
  queueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
  queueCreateInfo.pNext = nullptr;
  queueCreateInfo.flags = 0u;
  queueCreateInfo.queueFamilyIndex = queueFamilyIndex;
  queueCreateInfo.queueCount = 1u;
  queueCreateInfo.pQueuePriorities = nullptr;

  VkDeviceCreateInfo createInfo{};
  createInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
  createInfo.pNext = nullptr;
  createInfo.flags = 0u;
  createInfo.queueCreateInfoCount = 1u;
  createInfo.pQueueCreateInfos = &queueCreateInfo;
  createInfo.enabledLayerCount = 0u;
  createInfo.ppEnabledLayerNames = nullptr;
  createInfo.enabledExtensionCount = 0u;
  createInfo.ppEnabledExtensionNames = nullptr;
  createInfo.pEnabledFeatures = nullptr;

  vkCreateDevice(physicalDevice.Get(), &createInfo, nullptr, &handle); // !=
  //  VK_SUCCESS;
  vkGetDeviceQueue(handle, queueFamilyIndex, 0, &queue);
}

LogicalDevice::~LogicalDevice()
{
  vkDestroyDevice(handle, nullptr);
}

////////////////////////////////////////////////////////////////////////////////
// Factory functions
////////////////////////////////////////////////////////////////////////////////

std::unique_ptr<LogicalDevice>
CreateDevice(
  PhysicalDevice const& physicalDevice,
  std::uint32_t const queueFamilyIndex)
{
  return std::unique_ptr<LogicalDevice>();
}

NAMESPACE_END(Renderer::Graphics)

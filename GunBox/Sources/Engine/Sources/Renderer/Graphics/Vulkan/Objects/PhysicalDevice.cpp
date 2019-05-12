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
// C++ Standard Library
#include <memory>
#include <sstream>

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
  reLogI("    type: ", TypeAsString());

  queueFamilies = EnumeratePhysicalDeviceQueueFamilies<QueueFamily>(*this);
}

////////////////////////////////////////////////////////////////////////////////
// Properties
////////////////////////////////////////////////////////////////////////////////

std::vector<QueueFamily> const&
PhysicalDevice::QueueFamilies() const
{
  return queueFamilies;
}

PhysicalDevice::Type_t
PhysicalDevice::Type() const
{
  switch (properties.deviceType) {
    case VK_PHYSICAL_DEVICE_TYPE_OTHER:
      return Type_t::Other;
    case VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU:
      return Type_t::GPU_Integrated;
    case VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU:
      return Type_t::GPU_Discrete;
    case VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU:
      return Type_t::GPU_Virtual;
    case VK_PHYSICAL_DEVICE_TYPE_CPU:
      return Type_t::CPU;
    default: {
      assert(false && "Unknown physical device type");
      return Type_t::Unknown;
    }
  }
}

std::string
PhysicalDevice::TypeAsString() const
{
  using namespace std::string_literals;

  switch (properties.deviceType) {
    case VK_PHYSICAL_DEVICE_TYPE_OTHER:
      return "Other"s;
    case VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU:
      return "Integrated GPU"s;
    case VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU:
      return "Discrete GPU"s;
    case VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU:
      return "Virtual GPUs";
    case VK_PHYSICAL_DEVICE_TYPE_CPU:
      return "CPU"s;
    default: {
      assert(false && "Unknown physical device type");
      return "Unknown";
    }
  }
}

std::any
PhysicalDevice::FindComputeQueueFamily() const
{
  // Get all compute capable queue families
  std::vector<std::reference_wrapper<QueueFamily const>>
    computeCapableQueueFamilies;
  for (auto const& queueFamily : queueFamilies) {
    if (queueFamily.IsCapable(QueueFamily::Capability_t::Compute)) {
      computeCapableQueueFamilies.push_back(
        std::reference_wrapper<QueueFamily const>{ queueFamily });
    }
  }

  // Get a compute only capable queue family
  for (auto const& computeCapableQueueFamily : computeCapableQueueFamilies) {
    auto const& queueFamily = computeCapableQueueFamily.get();
    auto isComputeOnly =
      !queueFamily.IsCapable(QueueFamily::Capability_t::Graphics) &&
      !queueFamily.IsCapable(QueueFamily::Capability_t::Protected) &&
      !queueFamily.IsCapable(QueueFamily::Capability_t::SparseBinding) &&
      !queueFamily.IsCapable(QueueFamily::Capability_t::Transfer);
    if (isComputeOnly) {
      return (std::reference_wrapper<QueueFamily const>{ queueFamily });
    }
  }

  // Return the first compute capable queue family if no compute only capable
  // queue family has not been found
  if (!computeCapableQueueFamilies.empty()) {
    return computeCapableQueueFamilies[0];
  } else {

    return std::string{ "Unable to find a compute capable queue family" };
  }
}

std::any
PhysicalDevice::FindGraphicsQueueFamily() const
{
  return FindQueueFamily(QueueFamily::Capability_t::Graphics);
}

std::any
PhysicalDevice::FindQueueFamily(
  QueueFamily::CapabilityFlags queueCapabilityFlags) const
{
  for (auto const& queueFamily : queueFamilies) {
    if (queueFamily.IsCapable(queueCapabilityFlags)) {
      return std::reference_wrapper<QueueFamily const>{ queueFamily };
    }
  }

  std::stringstream ss{ "Unable to find queue family with: " };
  bool isEmpty = true;

  if (IsQueueFamilyCapabilityFlagSet(
        queueCapabilityFlags, QueueFamily::Capability_t::Compute)) {
    ss << "compute";
    isEmpty = false;
  } else if (IsQueueFamilyCapabilityFlagSet(
               queueCapabilityFlags, QueueFamily::Capability_t::Graphics)) {
    if (!isEmpty) {
      ss << ", ";
    }
    ss << "graphics";
  } else if (IsQueueFamilyCapabilityFlagSet(
               queueCapabilityFlags, QueueFamily::Capability_t::Protected)) {
    if (!isEmpty) {
      ss << ", ";
    }
    ss << "protected";
  } else if (IsQueueFamilyCapabilityFlagSet(
               queueCapabilityFlags,
               QueueFamily::Capability_t::SparseBinding)) {
    if (!isEmpty) {
      ss << ", ";
    }
    ss << "sparse binding";
  } else if (IsQueueFamilyCapabilityFlagSet(
               queueCapabilityFlags, QueueFamily::Capability_t::Transfer)) {
    if (!isEmpty) {
      ss << ", ";
    }
    ss << "transfer";
  } else {
    return std::string{ "Unknown queue family type" };
  }

  if (isEmpty) {
    ss << " capability";
  } else {
    ss << "capabilities";
  }

  return ss.str();
}

std::any
PhysicalDevice::FindQueueFamily(QueueFamily::Capability_t queueCapability) const
{
  return FindQueueFamily(
    static_cast<QueueFamily::CapabilityFlags>(queueCapability));
}

////////////////////////////////////////////////////////////////////////////////
// Free functions
////////////////////////////////////////////////////////////////////////////////

VkPhysicalDevice
PhysicalDevice::Get() const
{
  return this->physicalDevice;
}

auto
PhysicalDevice::Name() const -> std::string
{
  return { properties.deviceName };
}

NAMESPACE_END(Renderer::Graphics)

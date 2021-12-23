// Self
#include "PhysicalDevice.hpp"

// Project headers - Application
#include "Application/ModuleInfo.hpp"
// Project headers - Common
#include "Common/Macros/Logging.hpp"
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
#include <set>
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
  vkGetPhysicalDeviceProperties(this->physicalDevice, &properties);
  queueFamilies =
    Vulkan::Objects::Utilities::EnumeratePhysicalDeviceQueueFamilies<
      QueueFamily>(*this);
}

////////////////////////////////////////////////////////////////////////////////
// Properties
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

// Returns device type as a string
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

PhysicalDevice::QueueFamilyResult_t
PhysicalDevice::FindComputeQueueFamily() const
{
  // Find the first compute only capable queue family
  for (auto const& queueFamily : queueFamilies) {
    if (
      queueFamily.IsCapable(QueueFamily::Capability_t::Compute) &&
      !queueFamily.IsCapable(QueueFamily::Capability_t::Graphics)) {
      return std::reference_wrapper<QueueFamily const>{ queueFamily };
    }
  }

  // Graphics queues families always support compute operations
  return FindGraphicsQueueFamily();
}

PhysicalDevice::QueueFamilyResult_t
PhysicalDevice::FindGraphicsQueueFamily() const
{
  return FindQueueFamily(QueueFamily::Capability_t::Graphics);
}

PhysicalDevice::QueueFamilyResult_t
PhysicalDevice::FindTransferQueueFamily() const
{
  // Get the first transfer only capable queue
  for (auto const& queueFamily : queueFamilies) {
    if (
      queueFamily.IsCapable(QueueFamily::Capability_t::Transfer) &&
      !queueFamily.IsCapable(QueueFamily::Capability_t::Graphics) &&
      !queueFamily.IsCapable(QueueFamily::Capability_t::Compute)) {
      return std::reference_wrapper<QueueFamily const>{ queueFamily };
    }
  }

  // Graphics queue families always support tranfer operations
  return FindGraphicsQueueFamily();
}

PhysicalDevice::QueueFamilyResult_t
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

PhysicalDevice::QueueFamilyResult_t
PhysicalDevice::FindQueueFamily(QueueFamily::Capability_t queueCapability) const
{
  return FindQueueFamily(
    static_cast<QueueFamily::CapabilityFlags>(queueCapability));
}

////////////////////////////////////////////////////////////////////////////////
// Free functions
////////////////////////////////////////////////////////////////////////////////

std::vector<VkExtensionProperties>
EnumeratePhysicalDeviceExtensions(PhysicalDevice const& physicalDevice)
{
  auto physicalDeviceExtensionCount = 0u;
  #pragma warning(suppress: 26812) // Allow unscoped enum
  if (vkCallSuccess(vkEnumerateDeviceExtensionProperties(
        physicalDevice.Get(),
        nullptr,
        &physicalDeviceExtensionCount,
        nullptr))) {
    std::vector<VkExtensionProperties> physicalDeviceExtensions(
      physicalDeviceExtensionCount);
    if (vkCallSuccess(vkEnumerateDeviceExtensionProperties(
          physicalDevice.Get(),
          nullptr,
          &physicalDeviceExtensionCount,
          physicalDeviceExtensions.data()))) {

      return physicalDeviceExtensions;
    }
  }

  return {};
}

void
ListPhysicalDeviceExtensions(PhysicalDevice const& physicalDevice)
{
  using namespace std::string_literals;

  auto const physicalDeviceExtensions =
    EnumeratePhysicalDeviceExtensions(physicalDevice);
  // clang-format off
  ELogI("            + Available extensions: ("s, physicalDeviceExtensions.size(), ")"s);
  // clang-format on

  auto const compare =
    [](VkExtensionProperties const& lhs, VkExtensionProperties const& rhs) {
      return std::strcmp(lhs.extensionName, rhs.extensionName) < 1;
    };
  std::set<VkExtensionProperties, decltype(compare)> extensions{
    std::begin(physicalDeviceExtensions),
    std::end(physicalDeviceExtensions),
    compare
  };

  for ([[maybe_unused]] auto const& extension : extensions) {
    ELogI("                "s, extension.extensionName);
  }
}

void
ListQueueFamilies(PhysicalDevice const& physicalDevice)
{
  for (auto const& queueFamily : physicalDevice.QueueFamilies()) {
    PrintQueueFamilyInfo(queueFamily);
  }
}

void
PrintQueueFamilyInfo(QueueFamily const& queueFamily)
{
  using namespace std::string_literals;

  [[maybe_unused]] auto const& caps = queueFamily.Capabilities();

  // clang-format off
  ELogI("            + Queue family:"s);
  ELogI("                Index:           "s, queueFamily.Index());
  ELogI("                Queue count:     "s, queueFamily.QueueCount());
  ELogI("                Capabilities:"s);
  ELogI("                  Compute:       "s, std::boolalpha, caps.Compute);
  ELogI("                  Graphics:      "s, std::boolalpha, caps.Graphics);
  ELogI("                  Protected:     "s, std::boolalpha, caps.ProtectedMemory);
  ELogI("                  SparseBinding: "s, std::boolalpha, caps.SparseBinding);
  ELogI("                  Transfer:      "s, std::boolalpha, caps.Transfer);
  // clang-format on
}

NAMESPACE_END(Renderer::Graphics)

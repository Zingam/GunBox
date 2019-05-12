// Self
#include "QueueFamily.hpp"

// C Standard Library
#include <cassert>

NAMESPACE_BEGIN(Renderer::Graphics)

////////////////////////////////////////////////////////////////////////////////
// Constructors & Destructors
////////////////////////////////////////////////////////////////////////////////

QueueFamily::QueueFamily(VkQueueFamilyProperties const& queueFamily)
  : queueFamily{ queueFamily }
  , queueCount{ queueFamily.queueCount }
{
  capabilities.Compute =
    queueFamily.queueFlags & VkQueueFlagBits::VK_QUEUE_COMPUTE_BIT;
  capabilities.Graphics =
    queueFamily.queueFlags & VkQueueFlagBits::VK_QUEUE_GRAPHICS_BIT;
  capabilities.ProtectedMemory =
    queueFamily.queueFlags & VkQueueFlagBits::VK_QUEUE_PROTECTED_BIT;
  capabilities.SparseBinding =
    queueFamily.queueFlags & VkQueueFlagBits::VK_QUEUE_SPARSE_BINDING_BIT;
  capabilities.Transfer =
    queueFamily.queueFlags & VkQueueFlagBits::VK_QUEUE_TRANSFER_BIT;
}

////////////////////////////////////////////////////////////////////////////////
// Properties
////////////////////////////////////////////////////////////////////////////////

QueueFamily::Capabilities_t const&
QueueFamily::Capabilities() const
{
  return capabilities;
}

////////////////////////////////////////////////////////////////////////////////
// Methods
////////////////////////////////////////////////////////////////////////////////

bool
QueueFamily::IsCapable(CapabilityFlags capabilityFlags) const
{
  bool isCapable = true;
  bool isFlagSet = false;

  auto TestCapability = [&](Capability_t queueCapability) {
    if (IsQueueFamilyCapabilityFlagSet(capabilityFlags, queueCapability)) {
      isCapable &= IsCapable(capabilityFlags, queueCapability);
      isFlagSet = true;
    }
  };

  TestCapability(Capability_t::Compute);
  TestCapability(Capability_t::Graphics);
  TestCapability(Capability_t::Protected);
  TestCapability(Capability_t::SparseBinding);
  TestCapability(Capability_t::Transfer);

  return (isCapable && isFlagSet);
}

bool
QueueFamily::IsCapable(
  QueueFamily::CapabilityFlags capabilityFlags,
  QueueFamily::Capability_t queueCapability) const
{
  auto const flag =
    IsQueueFamilyCapabilityFlagSet(capabilityFlags, queueCapability);

  switch (queueCapability) {
    case QueueFamily::Capability_t::Compute:
      return (flag == capabilities.Compute);
    case QueueFamily::Capability_t::Graphics:
      return (flag == capabilities.Graphics);
    case QueueFamily::Capability_t::Protected:
      return (flag == capabilities.ProtectedMemory);
    case QueueFamily::Capability_t::SparseBinding:
      return (flag == capabilities.SparseBinding);
    case QueueFamily::Capability_t::Transfer:
      return (flag == capabilities.Transfer);
    default: {
      assert(false && "Unknown capablity flag!");
      return false;
    }
  }
}

bool
QueueFamily::IsCapable(QueueFamily::Capability_t queueCapability) const
{
  return IsCapable(static_cast<QueueFamily::CapabilityFlags>(queueCapability));
}

////////////////////////////////////////////////////////////////////////////////
// Free functions
////////////////////////////////////////////////////////////////////////////////

bool
IsQueueFamilyCapabilityFlagSet(
  QueueFamily::CapabilityFlags capabilityFlags,
  QueueFamily::Capability_t queueCapability)
{
  return static_cast<bool>(
    capabilityFlags &
    static_cast<QueueFamily::CapabilityFlags>(queueCapability));
}

NAMESPACE_END(Renderer::Graphics)

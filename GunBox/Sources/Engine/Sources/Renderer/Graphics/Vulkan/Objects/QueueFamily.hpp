#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

// Third party libraries
#include <glad/vulkan.h>

// C Standard Library
#include <cstdint>
// C++ Standard Library
#include <vector>

////////////////////////////////////////////////////////////////////////////////
// Class declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(Renderer::Graphics)

class QueueFamily
{
  // Types
public:
  struct Capabilities_t
  {
    bool Compute = false;
    bool Graphics = false;
    bool ProtectedMemory = false;
    bool SparseBinding = false;
    bool Transfer = false;
  };

  using CapabilityFlags = std::uint8_t;

  enum class Capability_t : CapabilityFlags
  {
    Compute = 0b0000'0001,
    Graphics = 0b0000010,
    Protected = 0b0000'0100,
    SparseBinding = 0b0000'1000,
    Transfer = 0b0001'0000,
  };

  // Constructors & Destructors
public:
  QueueFamily(VkQueueFamilyProperties const& queueFamily);

public:
  QueueFamily(QueueFamily const&) = delete;
  QueueFamily(QueueFamily&&) = default;

  // Properties
public:
  auto Capabilities() const -> Capabilities_t const&;

  // Methods
public:
  // clang-format off
  auto IsCapable(CapabilityFlags capabilityFlags) const
    -> bool;
  auto IsCapable(CapabilityFlags capabilityFlags, Capability_t queueCapability)
    const -> bool;
  auto IsCapable(Capability_t) const
    -> bool;
  // clang-format on

private:
  Capabilities_t capabilities{};
  std::uint32_t queueCount = 0;
  VkQueueFamilyProperties queueFamily{};
};

////////////////////////////////////////////////////////////////////////////////
// Free functions
////////////////////////////////////////////////////////////////////////////////

auto
IsQueueFamilyCapabilityFlagSet(
  QueueFamily::CapabilityFlags capabilityFlags,
  QueueFamily::Capability_t queueCapability) -> bool;

NAMESPACE_END(Renderer::Graphics)

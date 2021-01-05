#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

// Project headers - Renderer
#include "Renderer/Graphics/Vulkan/Vulkan.hpp"

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
  QueueFamily(VkQueueFamilyProperties const& queueFamily, std::uint32_t index);

public:
  QueueFamily(QueueFamily const&) = delete;
  QueueFamily(QueueFamily&&) = default;

  // Properties
public:
  auto Capabilities() const -> Capabilities_t const&;
  auto Index() const -> std::uint32_t;
  auto QueueCount() const -> std::uint32_t;

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
  std::uint32_t index = 0;
  std::uint32_t queueCount = 0;
  VkQueueFamilyProperties queueFamily{};
};

using QueueFamily_Ref_t = std::reference_wrapper<QueueFamily const>;

////////////////////////////////////////////////////////////////////////////////
// Free functions
////////////////////////////////////////////////////////////////////////////////

auto
IsQueueFamilyCapabilityFlagSet(
  QueueFamily::CapabilityFlags capabilityFlags,
  QueueFamily::Capability_t queueCapability) -> bool;

NAMESPACE_END(Renderer::Graphics)

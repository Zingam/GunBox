#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

// Project headers - Renderer
#include "Renderer/Graphics/Vulkan/Objects/QueueFamily.hpp"
#include "Renderer/Graphics/Vulkan/Vulkan.hpp"

// C++ Standard Library
#include <any>
#include <string>
#include <variant>
#include <vector>
#include <iostream>

////////////////////////////////////////////////////////////////////////////////
// Forward declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(Renderer::Graphics)

class Instance;

NAMESPACE_END(Renderer::Graphics)

////////////////////////////////////////////////////////////////////////////////
// Class declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(Renderer::Graphics)

class PhysicalDevice
{
  // Types
public:
  enum class Type_t
  {
    CPU,
    GPU_Discrete,
    GPU_Integrated,
    GPU_Virtual,
    Other,
    Unknown
  };

  using QueueFamilyResult_t = std::variant<QueueFamily_Ref_t, std::string>;

  // Constructors & Destructors
public:
  PhysicalDevice(
    Instance const& instance,
    VkPhysicalDevice const physicalDevice);
  ~PhysicalDevice() { };

public:
  PhysicalDevice(PhysicalDevice const&) = delete;
  PhysicalDevice(PhysicalDevice&&) = default;

  // Properties
public:
  auto Get() const -> VkPhysicalDevice;
  auto Name() const -> std::string;
  auto QueueFamilies() const -> std::vector<QueueFamily> const&;
  auto Type() const -> Type_t;
  auto TypeAsString() const -> std::string;

  // Methods
public:
  // clang-format off
  /// <summary>
  /// Searches for the first compute only capable queue family if available
  /// otherwise returns the first graphics capable queue family.
  /// </summary>
  auto FindComputeQueueFamily() const
    -> QueueFamilyResult_t;
  /// <summary>
  /// Searches for the first graphics capable queue family.
  /// </summary>
  auto FindGraphicsQueueFamily() const
    -> QueueFamilyResult_t;
  /// <summary>
  /// Searches for the first transfer only capable queue family if available
  /// otherwise returns the first graphics capable queue family.
  /// </summary>
  auto FindTransferQueueFamily() const
    -> QueueFamilyResult_t;
  /// <summary>
  /// Searches for the first queue family with the required capability.
  /// </summary>
  auto FindQueueFamily(QueueFamily::CapabilityFlags queueCapabilityFlags) const
    -> QueueFamilyResult_t;
  /// <summary>
  /// Searches for the first queue family with the required capability.
  /// </summary>
  auto FindQueueFamily(QueueFamily::Capability_t queueCapability) const
    -> QueueFamilyResult_t;
  // clang-format on

  // Private data members
private:
  Instance const& instance;
  VkPhysicalDevice const physicalDevice;
  VkPhysicalDeviceProperties properties;
  std::vector<QueueFamily> queueFamilies;
};

NAMESPACE_END(Renderer::Graphics)

////////////////////////////////////////////////////////////////////////////////
// Free functions
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(Renderer::Graphics)

// clang-format off
auto
EnumeratePhysicalDeviceExtensions(PhysicalDevice const& physicalDevice)
  -> std::vector<VkExtensionProperties>;

auto
ListPhysicalDeviceExtensions(PhysicalDevice const& physicalDevice)
  -> void;

auto
ListQueueFamilies(PhysicalDevice const& physicalDevice)
  -> void;

auto
PrintQueueFamilyInfo(QueueFamily const& queueFamily)
  -> void;
// clang-format on

NAMESPACE_END(Renderer::Graphics)

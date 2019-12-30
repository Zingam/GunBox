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
#include <vector>
#include <iostream>

////////////////////////////////////////////////////////////////////////////////
// Class declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(Renderer::Graphics)
class Instance;

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
  /// otherwise returns the first compute capable queue family.
  /// </summary>
  auto FindComputeQueueFamily() const
    -> std::any;
  /// <summary>
  /// Searches for the first graphics capable queue family.
  /// </summary>
  auto FindGraphicsQueueFamily() const
    -> std::any;
  auto FindQueueFamily(QueueFamily::CapabilityFlags queueCapabilityFlags) const
    -> std::any;
  auto FindQueueFamily(QueueFamily::Capability_t queueCapability) const
    -> std::any;
  // clang-format on

  // Private data members
private:
  Instance const& instance;
  VkPhysicalDevice const physicalDevice;
  VkPhysicalDeviceProperties properties;
  std::vector<QueueFamily> queueFamilies;
};

////////////////////////////////////////////////////////////////////////////////
// Free functions
////////////////////////////////////////////////////////////////////////////////

auto
ListQueueFamilies(PhysicalDevice const& physicalDevice) -> void;

auto
PrintQueueFamilyInfo(QueueFamily const& queueFamily) -> void;

NAMESPACE_END(Renderer::Graphics)

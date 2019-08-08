#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

// Project headers - Renderer
#include "Renderer/Graphics/Vulkan/Objects/PhysicalDevice.hpp"

// Third party libraries
#include <glad/vulkan.h>

// C++ Standard Library
#include <optional>
#include <string>
#include <vector>

////////////////////////////////////////////////////////////////////////////////
// Forward declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(Renderer::Graphics)

class GraphicsRenderer_Interface;

NAMESPACE_END(Renderer::Graphics)

////////////////////////////////////////////////////////////////////////////////
// Class declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(Renderer::Graphics)

class Instance
{
  // Constructors & Destructors
public:
  Instance(GraphicsRenderer_Interface const& graphicsRenderer);

public:
  Instance(Instance const&) = delete;
  Instance(Instance&&) = default;

  // Properties
public:
  auto Get() const -> VkInstance;
  auto PhysicalDevices() -> std::vector<PhysicalDevice>&;

  // Methods
public:
  auto EnumeratePhysicalDevices() -> void;
  /// <summary>
  /// Selects a suitable physical device of the requested type if possible.
  /// </summary>
  auto SelectPhysicalDevice(PhysicalDevice::Type_t physicalDeviceType) const
    -> PhysicalDevice const&;
  /// <summary>
  /// Selects a physical device of the required type if available.
  /// </summary>
  auto SelectPreferredPhysicalDevice(PhysicalDevice::Type_t physicalDeviceType)
    const -> std::optional<std::reference_wrapper<PhysicalDevice const>>;

private:
  auto Create() -> void;
  auto GetExtensionNamesToEnable() const -> std::vector<char const*>;
  auto GetLayerNamesToEnable() const -> std::vector<char const*>;
  auto GetRequiredLayerNames() const -> std::vector<char const*>;

  // Private data members
private:
  GraphicsRenderer_Interface const& graphicsRenderer;
  VkInstance instance = nullptr;
  std::vector<PhysicalDevice> physicalDevices;
  std::vector<VkLayerProperties> layers;
};

////////////////////////////////////////////////////////////////////////////////
// Free function declarations
////////////////////////////////////////////////////////////////////////////////

// clang-format off

auto
EnumerateInstanceExtensions()
  -> std::vector<VkExtensionProperties>;

auto
EnumerateInstanceExtensions(std::optional<std::string> const& layerName)
  -> std::vector<VkExtensionProperties>;

auto
EnumerateInstanceLayers()
  -> std::vector<VkLayerProperties>;

// clang-format on

NAMESPACE_END(Renderer::Graphics)

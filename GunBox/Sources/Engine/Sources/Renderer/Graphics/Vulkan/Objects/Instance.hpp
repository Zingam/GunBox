#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

// Project headers - Renderer
#include "Renderer/Graphics/Vulkan/Objects/PhysicalDevice.hpp"
#include "Renderer/Graphics/Vulkan/Vulkan.hpp"

// C++ Standard Library
#include <memory>
#include <optional>
#include <string>
#include <vector>

////////////////////////////////////////////////////////////////////////////////
// Type alias declarations
////////////////////////////////////////////////////////////////////////////////

template<typename T>
using optional_ref = std::optional<std::reference_wrapper<T>>;

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

  ~Instance();

  // Properties
public:
  /// <summary>
  /// Returns a handle to the Vulkan instance.
  /// </summary>
  auto Get() const -> VkInstance;
  /// <summary>
  /// Returns a collection of the enumerated physical devices on the system.
  /// </summary>
  auto PhysicalDevices() -> std::vector<PhysicalDevice>&;
  /// <summary>
  /// Returns the currently selected physical device.
  /// </summary>
  auto SelectedPhysicalDevice() const -> optional_ref<PhysicalDevice const>;

  // Methods
public:
  /// <summary>
  /// Enumerates the available physical devices on the system.
  /// </summary>
  auto EnumeratePhysicalDevices() -> void;
  /// <summary>
  /// Prints out information about the enumerated physical devices to the
  /// standard output.
  /// </summary>
  auto ListPhysicalDevices() -> void;
  /// <summary>
  /// Searches for a physical device of the requested type. If no suitable
  /// device is found the first available device is selected.
  /// </summary>
  auto SelectPhysicalDevice(PhysicalDevice::Type_t physicalDeviceType) -> void;
  /// <summary>
  /// Searches a physical device of the required type.
  /// </summary>
  auto FindPhysicalDevice(PhysicalDevice::Type_t physicalDeviceType) const
    -> optional_ref<PhysicalDevice const>;

private:
  auto Create() -> void;
  auto DebugMessangerCreate() -> void;
  auto DebugMessangerDestroy() -> void;
  auto GetExtensionNamesToEnable(bool isDebuggingEnabled) const
    -> std::vector<char const*>;
  auto GetLayerNamesToEnable() const -> std::vector<char const*>;
  auto GetRequiredLayerNames() const -> std::vector<char const*>;

  // Static methods
private:
  static VKAPI_ATTR auto VKAPI_CALL DebugMessangerCallback(
    VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
    VkDebugUtilsMessageTypeFlagsEXT messageTypes,
    const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
    void* pUserData) -> VkBool32;

  // Private data members
private:
  VkDebugUtilsMessengerEXT debugMessenger = nullptr;
  GraphicsRenderer_Interface const& graphicsRenderer;
  VkInstance instance = nullptr;
  bool isValidationEnabled = false;
  std::vector<PhysicalDevice> physicalDevices;
  std::vector<VkLayerProperties> layers;
  optional_ref<PhysicalDevice const> selectedPhysicalDevice;
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

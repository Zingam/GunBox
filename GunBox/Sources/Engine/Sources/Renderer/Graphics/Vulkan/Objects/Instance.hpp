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

private:
  auto Create() -> void;

  // Private data members
private:
  GraphicsRenderer_Interface const& graphicsRenderer;
  VkInstance instance = nullptr;
  std::vector<PhysicalDevice> physicalDevices;
};

////////////////////////////////////////////////////////////////////////////////
// Free function declarations
////////////////////////////////////////////////////////////////////////////////

// clang-format off

auto
EnumerateInstanceExtensions(std::string const& layerName)
  -> std::vector<VkExtensionProperties>;

auto
EnumerateInstanceLayers()
  -> std::vector<VkLayerProperties>;

// clang-format on

NAMESPACE_END(Renderer::Graphics)

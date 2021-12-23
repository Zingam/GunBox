// Self
#include "Surface.hpp"

// Project headers - Common
#include "Common/Macros/Logging.hpp"
// Project headers - Renderer
#include "Renderer/Graphics/Vulkan/Objects/Instance.hpp"
#include "Renderer/Graphics/Vulkan/Objects/Utilities/Utilities.hpp"
// Project headers - System
#include "System/GUI/Window.hpp"

// C Standard Libraries
#include <cassert>

NAMESPACE_BEGIN(Renderer::Graphics)

////////////////////////////////////////////////////////////////////////////////
// Class declarations
////////////////////////////////////////////////////////////////////////////////

Surface::Surface(
  System::Window const& window,
  Instance const& instance,
  VkSurfaceKHR handle)
  : handle{ handle }
  , instance{ instance }
  , window{ window }
{
  assert(IsInstance(handle) && "Vulkan surface is not initialized!");

  using namespace std::string_literals;

  ELogI(
    "  - Vulkan Surface: created for window \""s,
    window.Title(),
    "\", ID "s,
    window.Id());
}

Surface::~Surface()
{
  using namespace std::string_literals;

  ELogI("  - Vulkan Surface: destroyed"s);

  vkDestroySurfaceKHR(instance.Get(), handle, nullptr);
}

VkSurfaceKHR
Surface::Get() const
{
  return this->handle;
}

////////////////////////////////////////////////////////////////////////////////
// Free functions
////////////////////////////////////////////////////////////////////////////////

void
EnumerateSurfaceProperties(
  Surface& surface,
  PhysicalDevice const& physicalDevice)
{
  assert(
    IsInstance(vkGetPhysicalDeviceSurfaceSupportKHR) &&
    "vkGetPhysicalDeviceSurfaceSupportKHR function pointer is not loaded");
  assert(
    IsInstance(vkGetPhysicalDeviceSurfaceCapabilitiesKHR) &&
    "vkGetPhysicalDeviceSurfaceCapabilitiesKHR function pointer is not loaded");
  assert(
    IsInstance(vkGetPhysicalDeviceSurfaceFormatsKHR) &&
    "vkGetPhysicalDeviceSurfaceFormatsKHR function pointer is not loaded");
  assert(
    IsInstance(vkGetPhysicalDeviceSurfacePresentModesKHR) &&
    "vkGetPhysicalDeviceSurfacePresentModesKHR function pointer is not loaded");
  SurfaceInfo surfaceInfo;
  // Surface capabilities
  #pragma warning(suppress: 26812) // Allow unscoped enum
  vkGetPhysicalDeviceSurfaceCapabilitiesKHR(
    physicalDevice.Get(), surface.handle, &surfaceInfo.capabilities);

  // Surface formats
  if (std::uint32_t formatCount = 0u;
      vkCallSuccess(vkGetPhysicalDeviceSurfaceFormatsKHR(
        physicalDevice.Get(), surface.handle, &formatCount, nullptr))) {
    if (formatCount > 0) {
      surfaceInfo.formats.resize(formatCount);
      if (vkCallFail(vkGetPhysicalDeviceSurfaceFormatsKHR(
            physicalDevice.Get(),
            surface.handle,
            &formatCount,
            surfaceInfo.formats.data()))) {
        using namespace std::string_literals;

        ELogVE(
          "Failed to get the surface format properties for: "s,
          physicalDevice.Name());

        return;
      }
    }
  }

  // Surface present modes
  if (std::uint32_t presentModesCount = 0u;
      vkCallSuccess(vkGetPhysicalDeviceSurfacePresentModesKHR(
        physicalDevice.Get(), surface.handle, &presentModesCount, nullptr))) {
    if (presentModesCount > 0) {
      surfaceInfo.presentModes.resize(presentModesCount);
      #pragma warning(suppress: 26812) // Allow unscoped enum
      if (vkCallFail(vkGetPhysicalDeviceSurfacePresentModesKHR(
            physicalDevice.Get(),
            surface.handle,
            &presentModesCount,
            surfaceInfo.presentModes.data()))) {
        using namespace std::string_literals;

        ELogVE(
          "Failed to get the surface present modes for: "s,
          physicalDevice.Name());

        return;
      }
    }
  }
}

NAMESPACE_END(Renderer::Graphics)

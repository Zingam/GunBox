// Self
#include "GPUDevice_Vulkan_SDL2.hpp"

// Project headers - Logger
#include "Logger/LogAPI.hpp"
// Project headers - System
#include "System/GUI/Window.hpp"

// Third party libraries
#include <SDL_vulkan.h>

// C Standard Library
#include <cassert>
// C++ Standard Library
#include <vector>

////////////////////////////////////////////////////////////////////////////////
// Macros
////////////////////////////////////////////////////////////////////////////////

#define ret_SUCCESS(x) (0 == (x))
#define sdl_FAIL(x) (SDL_FALSE == (x))
#define sdl_SUCCESS(x) (SDL_TRUE == (x))

NAMESPACE_BEGIN(System::HostPlatformClasses)

////////////////////////////////////////////////////////////////////////////////
// Constructors & Destructors
////////////////////////////////////////////////////////////////////////////////

GPUDevice_Vulkan_SDL::GPUDevice_Vulkan_SDL() {}

////////////////////////////////////////////////////////////////////////////////
// Properties
////////////////////////////////////////////////////////////////////////////////

std::vector<char const*> const&
GPUDevice_Vulkan_SDL::DebugExtensionNames() const
{
  return debugExtensionNames;
}

void*
GPUDevice_Vulkan_SDL::InstanceProcAddress() const
{
  return SDL_Vulkan_GetVkGetInstanceProcAddr();
}

std::vector<char const*> const&
GPUDevice_Vulkan_SDL::InstanceExtensionNames() const
{
  return instanceExtensionNames;
}

std::vector<char const*> const&
GPUDevice_Vulkan_SDL::SurfaceCreationExtensionNames() const
{
  return surfaceCreationExtensionNames;
}

std::vector<char const*> const&
GPUDevice_Vulkan_SDL::ValidationLayerNames() const
{
  return validationLayerNames;
}

////////////////////////////////////////////////////////////////////////////////
// Methods
////////////////////////////////////////////////////////////////////////////////

void
GPUDevice_Vulkan_SDL::Finalize()
{}

bool
GPUDevice_Vulkan_SDL::Initialize(Window const& window)
{
  platformName = SDL_GetPlatform();

  if (ret_SUCCESS(SDL_Vulkan_LoadLibrary(nullptr))) {
    std::uint32_t extensionsCount = 0;

    if (sdl_SUCCESS(SDL_Vulkan_GetInstanceExtensions(
          window.Id(), &extensionsCount, nullptr))) {
      surfaceCreationExtensionNames.resize(extensionsCount);

      if (sdl_FAIL(SDL_Vulkan_GetInstanceExtensions(
        window.Id(), &extensionsCount, surfaceCreationExtensionNames.data()))) {
        errorStatus = "Unable to get Vulkan surface creation extensions";
        return false;
      }
    }
  }

  return true;
}

NAMESPACE_END(System::HostPlatformClasses)

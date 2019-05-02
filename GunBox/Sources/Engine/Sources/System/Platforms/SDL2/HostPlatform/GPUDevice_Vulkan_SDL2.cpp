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
#define sdl_SUCCESS(x) (SDL_TRUE == (x))

NAMESPACE_BEGIN(System::HostPlatformClasses)

////////////////////////////////////////////////////////////////////////////////
// Constructors & Destructors
////////////////////////////////////////////////////////////////////////////////

GPUDevice_Vulkan_SDL::GPUDevice_Vulkan_SDL() {}

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
    std::vector<char const*> extensions;
    if (sdl_SUCCESS(SDL_Vulkan_GetInstanceExtensions(
          window.Id(), &extensionsCount, nullptr))) {
      extensions.resize(extensionsCount);

      reLogI("Graphics Renderer: Vulkan");
      reLogI("  Instance extensions:")

      if (sdl_SUCCESS(SDL_Vulkan_GetInstanceExtensions(
            nullptr, &extensionsCount, extensions.data()))) {
        for (auto extension : extensions) {
          reLogI("    ", extension);
        }
      }
    }
  }

  return true;
}

NAMESPACE_END(System::HostPlatformClasses)

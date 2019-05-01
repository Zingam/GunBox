// Self
#include "VulkanDevice.hpp"

// Project headers - System
#include "System/GUI/Window.hpp"

// Third party libraries
#include <SDL_vulkan.h>

// C++ Standard Library
#include <iostream>
#include <vector>

#define ret_SUCCESS(x) (0 == (x))
#define sdl_SUCCESS(x) (SDL_TRUE == (x))

NAMESPACE_BEGIN(System::HostPlatformClasses)

bool
VulkanDevice::Initialize(Window const& window) const
{
  if (ret_SUCCESS(SDL_Vulkan_LoadLibrary(nullptr))) {
    std::uint32_t extensionsCount = 0;
    std::vector<char const*> extensions;
    if (sdl_SUCCESS(SDL_Vulkan_GetInstanceExtensions(
          window.Id(), &extensionsCount, nullptr))) {
      extensions.resize(extensionsCount);
      if (sdl_SUCCESS(SDL_Vulkan_GetInstanceExtensions(
            nullptr, &extensionsCount, extensions.data()))) {
        for (auto extension : extensions) {
          std::cout << extension << "\n";
        }
      }
    }
  }

  return true;
};

void
VulkanDevice::Finalize()
{}

NAMESPACE_END(System::HostPlatformClasses)

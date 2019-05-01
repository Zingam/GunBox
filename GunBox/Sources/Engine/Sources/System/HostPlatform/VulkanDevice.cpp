// Self
#include "VulkanDevice.hpp"

#include <SDL_vulkan.h>

#include <iostream>
#include <vector>

#define ret_SUCCESS(x) (0 == (x))
#define sdl_SUCCESS(x) (SDL_TRUE == (x))

NAMESPACE_BEGIN(System::HostPlatformClasses)

void
VulkanDevice::Initialize() const
{

  return;
  if (ret_SUCCESS(SDL_Vulkan_LoadLibrary(nullptr))) {
    std::uint32_t extensionsCount = 0;
    std::vector<char const*> extensions;
    if (sdl_SUCCESS(SDL_Vulkan_GetInstanceExtensions(
          nullptr, &extensionsCount, nullptr))) {
      extensions.resize(extensionsCount);
      if (sdl_SUCCESS(SDL_Vulkan_GetInstanceExtensions(
            nullptr, &extensionsCount, extensions.data()))) {
        for (auto extension : extensions) {
          std::cout << extension << "\n";
        }
      }
    }
  }
};

NAMESPACE_END(System::HostPlatformClasses)

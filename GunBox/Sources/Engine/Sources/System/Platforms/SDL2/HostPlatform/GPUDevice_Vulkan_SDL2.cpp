// Self
#include "GPUDevice_Vulkan_SDL2.hpp"

// Project headers - Renderer
#include "Renderer/Graphics/Vulkan/Objects/Instance.hpp"
#include "Renderer/Graphics/Vulkan/Objects/Surface.hpp"
// Project headers - System
#include "System/GUI/Window.hpp"

// Third party libraries
#include <SDL_vulkan.h>

// C Standard Library
#include <cassert>
// C++ Standard Library
#include <type_traits>
#include <vector>

////////////////////////////////////////////////////////////////////////////////
// Helper Function (file scope)
////////////////////////////////////////////////////////////////////////////////

// clang-format off

template<typename T>
auto
IsFail(T value)
  -> typename std::enable_if_t<std::is_same_v<SDL_bool, T>, bool>
{
  return (SDL_FALSE == value);
}

template<typename T, typename = std::enable_if<std::is_same_v<SDL_bool, T>>>
auto
IsSuccess(T value)
  -> typename std::enable_if_t<std::is_same_v<int, T>, bool>
{
  return (0 == value);
}

template<typename T, typename = std::enable_if<std::is_same_v<SDL_bool, T>>>
auto
IsSuccess(T value)
  -> typename std::enable_if_t<std::is_same_v<SDL_bool, T>, bool>
{
  return (SDL_TRUE == value);
}

// clang-format on

////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(System::HostPlatformClasses)

////////////////////////////////////////////////////////////////////////////////
// Constructors & Destructors
////////////////////////////////////////////////////////////////////////////////

GPUDevice_Vulkan_SDL::GPUDevice_Vulkan_SDL() = default;

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
  assert(
    IsFalse(this->platformName.empty()) &&
    "GPUDevice_Vulkan_SDL is not initialized");

  return SDL_Vulkan_GetVkGetInstanceProcAddr();
}

std::optional<Version>
GPUDevice_Vulkan_SDL::InstanceVersion() const
{
  assert(
    IsFalse(this->platformName.empty()) &&
    "GPUDevice_Vulkan_SDL is not initialized");
  assert(
    instanceVersion.has_value() && "GPUDevice_Vulkan_SDL is not initialized");

  return instanceVersion;
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

bool
GPUDevice_Vulkan_SDL::EnumerateInstanceExtensions()
{
  assert(
    IsFalse(this->platformName.empty()) &&
    "GPUDevice_Vulkan_SDL is not initialized");

  if (std::uint32_t extensionsCount = 0U; IsSuccess(
        SDL_Vulkan_GetInstanceExtensions(nullptr, &extensionsCount, nullptr))) {
    surfaceCreationExtensionNames.resize(extensionsCount);

    if (IsFail(SDL_Vulkan_GetInstanceExtensions(
          nullptr, &extensionsCount, surfaceCreationExtensionNames.data()))) {
      using namespace std::string_literals;

      errorStatus = "Unable to get Vulkan surface creation extensions"s;

      return false;
    }
  }

  return true;
}

void
GPUDevice_Vulkan_SDL::Finalize()
{}

std::unique_ptr<Renderer::Graphics::Surface>
GPUDevice_Vulkan_SDL::CreateSurface(
  Renderer::Graphics::Instance const& instance,
  System::Window const& window) const
{
  VkSurfaceKHR handle{};
  if (IsSuccess(
        SDL_Vulkan_CreateSurface(window.Id(), instance.Get(), &handle))) {
    return std::make_unique<Renderer::Graphics::Surface>(window, instance, handle);
  }

  return nullptr;
}

bool
GPUDevice_Vulkan_SDL::Initialize()
{
  assert(
    IsTrue(this->platformName.empty()) &&
    "GPUDevice_Vulkan_SDL is already initialized");

  this->platformName = SDL_GetPlatform();

  if (IsSuccess(SDL_Vulkan_LoadLibrary(nullptr))) {
    auto GetInstanceProcAddr = reinterpret_cast<PFN_vkGetInstanceProcAddr>(
      SDL_Vulkan_GetVkGetInstanceProcAddr());
    auto EnumerateInstanceVersion =
      reinterpret_cast<PFN_vkEnumerateInstanceVersion>(
        GetInstanceProcAddr(VK_NULL_HANDLE, "vkEnumerateInstanceVersion"));
    if (IsInstance(EnumerateInstanceVersion)) {
      std::uint32_t apiVersion = 0U;
      #pragma warning(suppress: 26812) // Allow unscoped enum
      if (VK_SUCCESS == EnumerateInstanceVersion(&apiVersion)) {
        this->instanceVersion.emplace(
          Version::Version_t{ VK_VERSION_MAJOR(apiVersion),
                              VK_VERSION_MINOR(apiVersion),
                              VK_VERSION_PATCH(apiVersion),
                              0U });
      } else {
        using namespace std::string_literals;

        errorStatus = "Failed to enumerate Vulkan instance version"s;

        return false;
      }
    } else {
      this->instanceVersion.emplace(Version::Version_t{ 1, 0, 0, 0 });
    }
  }

  return true;
}

NAMESPACE_END(System::HostPlatformClasses)

// Self
#include "GPUDevice_Vulkan.hpp"

// Project headers - Renderer
#include "Renderer/Graphics/Vulkan/Objects/Surface.hpp"

NAMESPACE_BEGIN(System::HostPlatformClasses)

////////////////////////////////////////////////////////////////////////////////
// Properties
////////////////////////////////////////////////////////////////////////////////

std::vector<char const*> const&
GPUDevice_Vulkan::DebugExtensionNames() const
{
  return o_ptr->DebugExtensionNames();
}

void*
GPUDevice_Vulkan::GetInstanceProcAddress() const
{
  return o_ptr->InstanceProcAddress();
}

std::vector<char const*> const&
GPUDevice_Vulkan::InstanceExtensionNames() const
{
  return o_ptr->InstanceExtensionNames();
}

std::vector<char const*> const&
GPUDevice_Vulkan::SurfaceCreationExtensionNames() const
{
  return o_ptr->SurfaceCreationExtensionNames();
}

std::vector<char const*> const&
GPUDevice_Vulkan::ValidationLayerNames() const
{
  return o_ptr->ValidationLayerNames();
}

////////////////////////////////////////////////////////////////////////////////
// Methods
////////////////////////////////////////////////////////////////////////////////

bool
GPUDevice_Vulkan::EnumerateInstanceExtensions()
{
  return o_ptr->EnumerateInstanceExtensions();
}

std::unique_ptr<Renderer::Graphics::Surface>
GPUDevice_Vulkan::CreateSurface(
  Renderer::Graphics::Instance const& instance,
  System::Window const& window) const
{
  return o_ptr->CreateSurface(instance, window);
}

bool
GPUDevice_Vulkan::Initialize()
{
  return o_ptr->Initialize();
}

std::optional<Version>
GPUDevice_Vulkan::InstanceVersion() const
{
  return o_ptr->InstanceVersion();
}

NAMESPACE_END(System::HostPlatformClasses)

#include "GPUDevice_Vulkan.hpp"
// Self
#include "GPUDevice_Vulkan.hpp"

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
GPUDevice_Vulkan::Initialize(Window const& window)
{
  return o_ptr->Initialize(window);
}

NAMESPACE_END(System::HostPlatformClasses)

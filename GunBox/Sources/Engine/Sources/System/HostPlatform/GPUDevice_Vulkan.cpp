#include "GPUDevice_Vulkan.hpp"
// Self
#include "GPUDevice_Vulkan.hpp"

NAMESPACE_BEGIN(System::HostPlatformClasses)

////////////////////////////////////////////////////////////////////////////////
// Properties
////////////////////////////////////////////////////////////////////////////////

void*
GPUDevice_Vulkan::InstanceProcAddress() const
{
  return o_ptr->InstanceProcAddress();
}

std::vector<char const*> const&
GPUDevice_Vulkan::SurfaceCreationExtensions() const
{
  return o_ptr->SurfaceCreationExtensions();
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

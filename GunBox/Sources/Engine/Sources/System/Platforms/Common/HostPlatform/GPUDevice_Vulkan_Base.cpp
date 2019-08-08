// Self
#include "GPUDevice_Vulkan_Base.hpp"

NAMESPACE_BEGIN(System::HostPlatformClasses)

GPUDevice_Vulkan_Base::GPUDevice_Vulkan_Base()
  : GPUDevice_Vulkan_Base_Common()
{
  validationLayerNames.push_back("VK_LAYER_KHRONOS_validation");
}

NAMESPACE_END(System::HostPlatformClasses)

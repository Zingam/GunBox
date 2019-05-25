// Self
#include "GPUDevice_Vulkan_Base_Common.hpp"

NAMESPACE_BEGIN(System::HostPlatformClasses)

////////////////////////////////////////////////////////////////////////////////
// Constructors & Destructors
////////////////////////////////////////////////////////////////////////////////

GPUDevice_Vulkan_Base_Common::GPUDevice_Vulkan_Base_Common()
  : validationLayerNames{
    "VK_LAYER_KHRONOS_validation",
    "VK_LAYER_RENDERDOC_Capture",
  }
{}

NAMESPACE_END(System::HostPlatformClasses)

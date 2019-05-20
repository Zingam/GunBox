// Self
#include "GPUDevice_Vulkan_Base_Android.hpp"

NAMESPACE_BEGIN(System::HostPlatformClasses)

////////////////////////////////////////////////////////////////////////////////
// Constructors & Destructors
////////////////////////////////////////////////////////////////////////////////

GPUDevice_Vulkan_Base_Android::GPUDevice_Vulkan_Base_Android()
  : validationLayerNames{
    "VK_LAYER_GOOGLE_threading",
    "VK_LAYER_GOOGLE_unique_objects",
    "VK_LAYER_LUNARG_core_validation",
    "VK_LAYER_LUNARG_object_tracker",
    "VK_LAYER_LUNARG_parameter_validation",
  }
{}

NAMESPACE_END(System::HostPlatformClasses)

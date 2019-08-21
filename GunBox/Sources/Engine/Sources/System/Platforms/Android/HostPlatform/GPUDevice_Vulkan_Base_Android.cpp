// Self
#include "GPUDevice_Vulkan_Base_Android.hpp"

NAMESPACE_BEGIN(System::HostPlatformClasses)

////////////////////////////////////////////////////////////////////////////////
// Constructors & Destructors
////////////////////////////////////////////////////////////////////////////////

GPUDevice_Vulkan_Base_Android::GPUDevice_Vulkan_Base_Android()
  : GPUDevice_Vulkan_Base_Common()
{
  validationLayerNames.push_back("VK_LAYER_GOOGLE_threading");
  validationLayerNames.push_back("VK_LAYER_GOOGLE_unique_objects");
  validationLayerNames.push_back("VK_LAYER_LUNARG_core_validation");
  validationLayerNames.push_back("VK_LAYER_LUNARG_object_tracker");
  validationLayerNames.push_back("VK_LAYER_LUNARG_parameter_validation");
}

NAMESPACE_END(System::HostPlatformClasses)

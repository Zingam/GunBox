// Self
#include "GPUDevice_Vulkan_Base_Common.hpp"

NAMESPACE_BEGIN(System::HostPlatformClasses)

////////////////////////////////////////////////////////////////////////////////
// Constructors & Destructors
////////////////////////////////////////////////////////////////////////////////

GPUDevice_Vulkan_Base_Common::GPUDevice_Vulkan_Base_Common()
  : debugExtensionNames{ "VK_EXT_debug_report", "VK_EXT_debug_utils" }
{}

NAMESPACE_END(System::HostPlatformClasses)

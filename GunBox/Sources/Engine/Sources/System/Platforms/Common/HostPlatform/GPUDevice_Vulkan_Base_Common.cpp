// Self
#include "GPUDevice_Vulkan_Base_Common.hpp"

// Project headers - Renderer
#include "Renderer/Graphics/Vulkan/Vulkan.hpp"

NAMESPACE_BEGIN(System::HostPlatformClasses)

////////////////////////////////////////////////////////////////////////////////
// Constructors & Destructors
////////////////////////////////////////////////////////////////////////////////

GPUDevice_Vulkan_Base_Common::GPUDevice_Vulkan_Base_Common()
  : debugExtensionNames{ VK_EXT_DEBUG_UTILS_EXTENSION_NAME }
{}

NAMESPACE_END(System::HostPlatformClasses)

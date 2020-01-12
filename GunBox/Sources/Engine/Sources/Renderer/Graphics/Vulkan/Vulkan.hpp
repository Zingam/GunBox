#pragma once
////////////////////////////////////////////////////////////////////////////////

// Third party libraries
#include <glad/vulkan.h>

////////////////////////////////////////////////////////////////////////////////

auto
LoadVulkanInstanceFunctionPointers(void* instanceProcAddr, VkInstance instance)
  -> bool;

////////////////////////////////////////////////////////////////////////////////
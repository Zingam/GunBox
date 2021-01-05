// Self
#include "Vulkan.hpp"

////////////////////////////////////////////////////////////////////////////////
// Functions
////////////////////////////////////////////////////////////////////////////////

bool
LoadVulkanGlobalFunctionPointers(void* instanceProcAddr)
{
  return (
    0 != gladLoadVulkanUserPtr(
           nullptr,
           reinterpret_cast<GLADuserptrloadfunc>(instanceProcAddr),
           nullptr));
}


bool
LoadVulkanInstanceFunctionPointers(void* instanceProcAddr, VkInstance instance)
{
  return (
    0 != gladLoadVulkanUserPtr(
           nullptr,
           reinterpret_cast<GLADuserptrloadfunc>(instanceProcAddr),
           instance));
}

////////////////////////////////////////////////////////////////////////////////

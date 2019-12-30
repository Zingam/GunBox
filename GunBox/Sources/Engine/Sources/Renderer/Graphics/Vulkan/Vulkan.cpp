// Self
#include "Vulkan.hpp"

////////////////////////////////////////////////////////////////////////////////

bool
LoadVulkanInstanceFunctionPointers(void* instanceProcAddr, VkInstance instance)
{
  return (
    0 != gladLoadVulkanUserPtr(
           nullptr,
           reinterpret_cast<GLADuserptrloadfunc>(instanceProcAddr),
           instance));
}


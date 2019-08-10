#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glad/vulkan.h>

#ifndef GLAD_IMPL_UTIL_C_
#define GLAD_IMPL_UTIL_C_

#ifdef _MSC_VER
#define GLAD_IMPL_UTIL_SSCANF sscanf_s
#else
#define GLAD_IMPL_UTIL_SSCANF sscanf
#endif

#endif /* GLAD_IMPL_UTIL_C_ */


int GLAD_VK_VERSION_1_0 = 0;
int GLAD_VK_VERSION_1_1 = 0;
int GLAD_VK_EXT_debug_report = 0;
int GLAD_VK_EXT_debug_utils = 0;
int GLAD_VK_KHR_swapchain = 0;



PFN_vkAcquireNextImage2KHR glad_vkAcquireNextImage2KHR = NULL;
PFN_vkAcquireNextImageKHR glad_vkAcquireNextImageKHR = NULL;
PFN_vkAllocateCommandBuffers glad_vkAllocateCommandBuffers = NULL;
PFN_vkAllocateDescriptorSets glad_vkAllocateDescriptorSets = NULL;
PFN_vkAllocateMemory glad_vkAllocateMemory = NULL;
PFN_vkBeginCommandBuffer glad_vkBeginCommandBuffer = NULL;
PFN_vkBindBufferMemory glad_vkBindBufferMemory = NULL;
PFN_vkBindBufferMemory2 glad_vkBindBufferMemory2 = NULL;
PFN_vkBindImageMemory glad_vkBindImageMemory = NULL;
PFN_vkBindImageMemory2 glad_vkBindImageMemory2 = NULL;
PFN_vkCmdBeginDebugUtilsLabelEXT glad_vkCmdBeginDebugUtilsLabelEXT = NULL;
PFN_vkCmdBeginQuery glad_vkCmdBeginQuery = NULL;
PFN_vkCmdBeginRenderPass glad_vkCmdBeginRenderPass = NULL;
PFN_vkCmdBindDescriptorSets glad_vkCmdBindDescriptorSets = NULL;
PFN_vkCmdBindIndexBuffer glad_vkCmdBindIndexBuffer = NULL;
PFN_vkCmdBindPipeline glad_vkCmdBindPipeline = NULL;
PFN_vkCmdBindVertexBuffers glad_vkCmdBindVertexBuffers = NULL;
PFN_vkCmdBlitImage glad_vkCmdBlitImage = NULL;
PFN_vkCmdClearAttachments glad_vkCmdClearAttachments = NULL;
PFN_vkCmdClearColorImage glad_vkCmdClearColorImage = NULL;
PFN_vkCmdClearDepthStencilImage glad_vkCmdClearDepthStencilImage = NULL;
PFN_vkCmdCopyBuffer glad_vkCmdCopyBuffer = NULL;
PFN_vkCmdCopyBufferToImage glad_vkCmdCopyBufferToImage = NULL;
PFN_vkCmdCopyImage glad_vkCmdCopyImage = NULL;
PFN_vkCmdCopyImageToBuffer glad_vkCmdCopyImageToBuffer = NULL;
PFN_vkCmdCopyQueryPoolResults glad_vkCmdCopyQueryPoolResults = NULL;
PFN_vkCmdDispatch glad_vkCmdDispatch = NULL;
PFN_vkCmdDispatchBase glad_vkCmdDispatchBase = NULL;
PFN_vkCmdDispatchIndirect glad_vkCmdDispatchIndirect = NULL;
PFN_vkCmdDraw glad_vkCmdDraw = NULL;
PFN_vkCmdDrawIndexed glad_vkCmdDrawIndexed = NULL;
PFN_vkCmdDrawIndexedIndirect glad_vkCmdDrawIndexedIndirect = NULL;
PFN_vkCmdDrawIndirect glad_vkCmdDrawIndirect = NULL;
PFN_vkCmdEndDebugUtilsLabelEXT glad_vkCmdEndDebugUtilsLabelEXT = NULL;
PFN_vkCmdEndQuery glad_vkCmdEndQuery = NULL;
PFN_vkCmdEndRenderPass glad_vkCmdEndRenderPass = NULL;
PFN_vkCmdExecuteCommands glad_vkCmdExecuteCommands = NULL;
PFN_vkCmdFillBuffer glad_vkCmdFillBuffer = NULL;
PFN_vkCmdInsertDebugUtilsLabelEXT glad_vkCmdInsertDebugUtilsLabelEXT = NULL;
PFN_vkCmdNextSubpass glad_vkCmdNextSubpass = NULL;
PFN_vkCmdPipelineBarrier glad_vkCmdPipelineBarrier = NULL;
PFN_vkCmdPushConstants glad_vkCmdPushConstants = NULL;
PFN_vkCmdResetEvent glad_vkCmdResetEvent = NULL;
PFN_vkCmdResetQueryPool glad_vkCmdResetQueryPool = NULL;
PFN_vkCmdResolveImage glad_vkCmdResolveImage = NULL;
PFN_vkCmdSetBlendConstants glad_vkCmdSetBlendConstants = NULL;
PFN_vkCmdSetDepthBias glad_vkCmdSetDepthBias = NULL;
PFN_vkCmdSetDepthBounds glad_vkCmdSetDepthBounds = NULL;
PFN_vkCmdSetDeviceMask glad_vkCmdSetDeviceMask = NULL;
PFN_vkCmdSetEvent glad_vkCmdSetEvent = NULL;
PFN_vkCmdSetLineWidth glad_vkCmdSetLineWidth = NULL;
PFN_vkCmdSetScissor glad_vkCmdSetScissor = NULL;
PFN_vkCmdSetStencilCompareMask glad_vkCmdSetStencilCompareMask = NULL;
PFN_vkCmdSetStencilReference glad_vkCmdSetStencilReference = NULL;
PFN_vkCmdSetStencilWriteMask glad_vkCmdSetStencilWriteMask = NULL;
PFN_vkCmdSetViewport glad_vkCmdSetViewport = NULL;
PFN_vkCmdUpdateBuffer glad_vkCmdUpdateBuffer = NULL;
PFN_vkCmdWaitEvents glad_vkCmdWaitEvents = NULL;
PFN_vkCmdWriteTimestamp glad_vkCmdWriteTimestamp = NULL;
PFN_vkCreateBuffer glad_vkCreateBuffer = NULL;
PFN_vkCreateBufferView glad_vkCreateBufferView = NULL;
PFN_vkCreateCommandPool glad_vkCreateCommandPool = NULL;
PFN_vkCreateComputePipelines glad_vkCreateComputePipelines = NULL;
PFN_vkCreateDebugReportCallbackEXT glad_vkCreateDebugReportCallbackEXT = NULL;
PFN_vkCreateDebugUtilsMessengerEXT glad_vkCreateDebugUtilsMessengerEXT = NULL;
PFN_vkCreateDescriptorPool glad_vkCreateDescriptorPool = NULL;
PFN_vkCreateDescriptorSetLayout glad_vkCreateDescriptorSetLayout = NULL;
PFN_vkCreateDescriptorUpdateTemplate glad_vkCreateDescriptorUpdateTemplate = NULL;
PFN_vkCreateDevice glad_vkCreateDevice = NULL;
PFN_vkCreateEvent glad_vkCreateEvent = NULL;
PFN_vkCreateFence glad_vkCreateFence = NULL;
PFN_vkCreateFramebuffer glad_vkCreateFramebuffer = NULL;
PFN_vkCreateGraphicsPipelines glad_vkCreateGraphicsPipelines = NULL;
PFN_vkCreateImage glad_vkCreateImage = NULL;
PFN_vkCreateImageView glad_vkCreateImageView = NULL;
PFN_vkCreateInstance glad_vkCreateInstance = NULL;
PFN_vkCreatePipelineCache glad_vkCreatePipelineCache = NULL;
PFN_vkCreatePipelineLayout glad_vkCreatePipelineLayout = NULL;
PFN_vkCreateQueryPool glad_vkCreateQueryPool = NULL;
PFN_vkCreateRenderPass glad_vkCreateRenderPass = NULL;
PFN_vkCreateSampler glad_vkCreateSampler = NULL;
PFN_vkCreateSamplerYcbcrConversion glad_vkCreateSamplerYcbcrConversion = NULL;
PFN_vkCreateSemaphore glad_vkCreateSemaphore = NULL;
PFN_vkCreateShaderModule glad_vkCreateShaderModule = NULL;
PFN_vkCreateSwapchainKHR glad_vkCreateSwapchainKHR = NULL;
PFN_vkDebugReportMessageEXT glad_vkDebugReportMessageEXT = NULL;
PFN_vkDestroyBuffer glad_vkDestroyBuffer = NULL;
PFN_vkDestroyBufferView glad_vkDestroyBufferView = NULL;
PFN_vkDestroyCommandPool glad_vkDestroyCommandPool = NULL;
PFN_vkDestroyDebugReportCallbackEXT glad_vkDestroyDebugReportCallbackEXT = NULL;
PFN_vkDestroyDebugUtilsMessengerEXT glad_vkDestroyDebugUtilsMessengerEXT = NULL;
PFN_vkDestroyDescriptorPool glad_vkDestroyDescriptorPool = NULL;
PFN_vkDestroyDescriptorSetLayout glad_vkDestroyDescriptorSetLayout = NULL;
PFN_vkDestroyDescriptorUpdateTemplate glad_vkDestroyDescriptorUpdateTemplate = NULL;
PFN_vkDestroyDevice glad_vkDestroyDevice = NULL;
PFN_vkDestroyEvent glad_vkDestroyEvent = NULL;
PFN_vkDestroyFence glad_vkDestroyFence = NULL;
PFN_vkDestroyFramebuffer glad_vkDestroyFramebuffer = NULL;
PFN_vkDestroyImage glad_vkDestroyImage = NULL;
PFN_vkDestroyImageView glad_vkDestroyImageView = NULL;
PFN_vkDestroyInstance glad_vkDestroyInstance = NULL;
PFN_vkDestroyPipeline glad_vkDestroyPipeline = NULL;
PFN_vkDestroyPipelineCache glad_vkDestroyPipelineCache = NULL;
PFN_vkDestroyPipelineLayout glad_vkDestroyPipelineLayout = NULL;
PFN_vkDestroyQueryPool glad_vkDestroyQueryPool = NULL;
PFN_vkDestroyRenderPass glad_vkDestroyRenderPass = NULL;
PFN_vkDestroySampler glad_vkDestroySampler = NULL;
PFN_vkDestroySamplerYcbcrConversion glad_vkDestroySamplerYcbcrConversion = NULL;
PFN_vkDestroySemaphore glad_vkDestroySemaphore = NULL;
PFN_vkDestroyShaderModule glad_vkDestroyShaderModule = NULL;
PFN_vkDestroySwapchainKHR glad_vkDestroySwapchainKHR = NULL;
PFN_vkDeviceWaitIdle glad_vkDeviceWaitIdle = NULL;
PFN_vkEndCommandBuffer glad_vkEndCommandBuffer = NULL;
PFN_vkEnumerateDeviceExtensionProperties glad_vkEnumerateDeviceExtensionProperties = NULL;
PFN_vkEnumerateDeviceLayerProperties glad_vkEnumerateDeviceLayerProperties = NULL;
PFN_vkEnumerateInstanceExtensionProperties glad_vkEnumerateInstanceExtensionProperties = NULL;
PFN_vkEnumerateInstanceLayerProperties glad_vkEnumerateInstanceLayerProperties = NULL;
PFN_vkEnumerateInstanceVersion glad_vkEnumerateInstanceVersion = NULL;
PFN_vkEnumeratePhysicalDeviceGroups glad_vkEnumeratePhysicalDeviceGroups = NULL;
PFN_vkEnumeratePhysicalDevices glad_vkEnumeratePhysicalDevices = NULL;
PFN_vkFlushMappedMemoryRanges glad_vkFlushMappedMemoryRanges = NULL;
PFN_vkFreeCommandBuffers glad_vkFreeCommandBuffers = NULL;
PFN_vkFreeDescriptorSets glad_vkFreeDescriptorSets = NULL;
PFN_vkFreeMemory glad_vkFreeMemory = NULL;
PFN_vkGetBufferMemoryRequirements glad_vkGetBufferMemoryRequirements = NULL;
PFN_vkGetBufferMemoryRequirements2 glad_vkGetBufferMemoryRequirements2 = NULL;
PFN_vkGetDescriptorSetLayoutSupport glad_vkGetDescriptorSetLayoutSupport = NULL;
PFN_vkGetDeviceGroupPeerMemoryFeatures glad_vkGetDeviceGroupPeerMemoryFeatures = NULL;
PFN_vkGetDeviceGroupPresentCapabilitiesKHR glad_vkGetDeviceGroupPresentCapabilitiesKHR = NULL;
PFN_vkGetDeviceGroupSurfacePresentModesKHR glad_vkGetDeviceGroupSurfacePresentModesKHR = NULL;
PFN_vkGetDeviceMemoryCommitment glad_vkGetDeviceMemoryCommitment = NULL;
PFN_vkGetDeviceProcAddr glad_vkGetDeviceProcAddr = NULL;
PFN_vkGetDeviceQueue glad_vkGetDeviceQueue = NULL;
PFN_vkGetDeviceQueue2 glad_vkGetDeviceQueue2 = NULL;
PFN_vkGetEventStatus glad_vkGetEventStatus = NULL;
PFN_vkGetFenceStatus glad_vkGetFenceStatus = NULL;
PFN_vkGetImageMemoryRequirements glad_vkGetImageMemoryRequirements = NULL;
PFN_vkGetImageMemoryRequirements2 glad_vkGetImageMemoryRequirements2 = NULL;
PFN_vkGetImageSparseMemoryRequirements glad_vkGetImageSparseMemoryRequirements = NULL;
PFN_vkGetImageSparseMemoryRequirements2 glad_vkGetImageSparseMemoryRequirements2 = NULL;
PFN_vkGetImageSubresourceLayout glad_vkGetImageSubresourceLayout = NULL;
PFN_vkGetInstanceProcAddr glad_vkGetInstanceProcAddr = NULL;
PFN_vkGetPhysicalDeviceExternalBufferProperties glad_vkGetPhysicalDeviceExternalBufferProperties = NULL;
PFN_vkGetPhysicalDeviceExternalFenceProperties glad_vkGetPhysicalDeviceExternalFenceProperties = NULL;
PFN_vkGetPhysicalDeviceExternalSemaphoreProperties glad_vkGetPhysicalDeviceExternalSemaphoreProperties = NULL;
PFN_vkGetPhysicalDeviceFeatures glad_vkGetPhysicalDeviceFeatures = NULL;
PFN_vkGetPhysicalDeviceFeatures2 glad_vkGetPhysicalDeviceFeatures2 = NULL;
PFN_vkGetPhysicalDeviceFormatProperties glad_vkGetPhysicalDeviceFormatProperties = NULL;
PFN_vkGetPhysicalDeviceFormatProperties2 glad_vkGetPhysicalDeviceFormatProperties2 = NULL;
PFN_vkGetPhysicalDeviceImageFormatProperties glad_vkGetPhysicalDeviceImageFormatProperties = NULL;
PFN_vkGetPhysicalDeviceImageFormatProperties2 glad_vkGetPhysicalDeviceImageFormatProperties2 = NULL;
PFN_vkGetPhysicalDeviceMemoryProperties glad_vkGetPhysicalDeviceMemoryProperties = NULL;
PFN_vkGetPhysicalDeviceMemoryProperties2 glad_vkGetPhysicalDeviceMemoryProperties2 = NULL;
PFN_vkGetPhysicalDevicePresentRectanglesKHR glad_vkGetPhysicalDevicePresentRectanglesKHR = NULL;
PFN_vkGetPhysicalDeviceProperties glad_vkGetPhysicalDeviceProperties = NULL;
PFN_vkGetPhysicalDeviceProperties2 glad_vkGetPhysicalDeviceProperties2 = NULL;
PFN_vkGetPhysicalDeviceQueueFamilyProperties glad_vkGetPhysicalDeviceQueueFamilyProperties = NULL;
PFN_vkGetPhysicalDeviceQueueFamilyProperties2 glad_vkGetPhysicalDeviceQueueFamilyProperties2 = NULL;
PFN_vkGetPhysicalDeviceSparseImageFormatProperties glad_vkGetPhysicalDeviceSparseImageFormatProperties = NULL;
PFN_vkGetPhysicalDeviceSparseImageFormatProperties2 glad_vkGetPhysicalDeviceSparseImageFormatProperties2 = NULL;
PFN_vkGetPipelineCacheData glad_vkGetPipelineCacheData = NULL;
PFN_vkGetQueryPoolResults glad_vkGetQueryPoolResults = NULL;
PFN_vkGetRenderAreaGranularity glad_vkGetRenderAreaGranularity = NULL;
PFN_vkGetSwapchainImagesKHR glad_vkGetSwapchainImagesKHR = NULL;
PFN_vkInvalidateMappedMemoryRanges glad_vkInvalidateMappedMemoryRanges = NULL;
PFN_vkMapMemory glad_vkMapMemory = NULL;
PFN_vkMergePipelineCaches glad_vkMergePipelineCaches = NULL;
PFN_vkQueueBeginDebugUtilsLabelEXT glad_vkQueueBeginDebugUtilsLabelEXT = NULL;
PFN_vkQueueBindSparse glad_vkQueueBindSparse = NULL;
PFN_vkQueueEndDebugUtilsLabelEXT glad_vkQueueEndDebugUtilsLabelEXT = NULL;
PFN_vkQueueInsertDebugUtilsLabelEXT glad_vkQueueInsertDebugUtilsLabelEXT = NULL;
PFN_vkQueuePresentKHR glad_vkQueuePresentKHR = NULL;
PFN_vkQueueSubmit glad_vkQueueSubmit = NULL;
PFN_vkQueueWaitIdle glad_vkQueueWaitIdle = NULL;
PFN_vkResetCommandBuffer glad_vkResetCommandBuffer = NULL;
PFN_vkResetCommandPool glad_vkResetCommandPool = NULL;
PFN_vkResetDescriptorPool glad_vkResetDescriptorPool = NULL;
PFN_vkResetEvent glad_vkResetEvent = NULL;
PFN_vkResetFences glad_vkResetFences = NULL;
PFN_vkSetDebugUtilsObjectNameEXT glad_vkSetDebugUtilsObjectNameEXT = NULL;
PFN_vkSetDebugUtilsObjectTagEXT glad_vkSetDebugUtilsObjectTagEXT = NULL;
PFN_vkSetEvent glad_vkSetEvent = NULL;
PFN_vkSubmitDebugUtilsMessageEXT glad_vkSubmitDebugUtilsMessageEXT = NULL;
PFN_vkTrimCommandPool glad_vkTrimCommandPool = NULL;
PFN_vkUnmapMemory glad_vkUnmapMemory = NULL;
PFN_vkUpdateDescriptorSetWithTemplate glad_vkUpdateDescriptorSetWithTemplate = NULL;
PFN_vkUpdateDescriptorSets glad_vkUpdateDescriptorSets = NULL;
PFN_vkWaitForFences glad_vkWaitForFences = NULL;


static void glad_vk_load_VK_VERSION_1_0( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_VERSION_1_0) return;
    vkAllocateCommandBuffers = (PFN_vkAllocateCommandBuffers) load(userptr, "vkAllocateCommandBuffers");
    vkAllocateDescriptorSets = (PFN_vkAllocateDescriptorSets) load(userptr, "vkAllocateDescriptorSets");
    vkAllocateMemory = (PFN_vkAllocateMemory) load(userptr, "vkAllocateMemory");
    vkBeginCommandBuffer = (PFN_vkBeginCommandBuffer) load(userptr, "vkBeginCommandBuffer");
    vkBindBufferMemory = (PFN_vkBindBufferMemory) load(userptr, "vkBindBufferMemory");
    vkBindImageMemory = (PFN_vkBindImageMemory) load(userptr, "vkBindImageMemory");
    vkCmdBeginQuery = (PFN_vkCmdBeginQuery) load(userptr, "vkCmdBeginQuery");
    vkCmdBeginRenderPass = (PFN_vkCmdBeginRenderPass) load(userptr, "vkCmdBeginRenderPass");
    vkCmdBindDescriptorSets = (PFN_vkCmdBindDescriptorSets) load(userptr, "vkCmdBindDescriptorSets");
    vkCmdBindIndexBuffer = (PFN_vkCmdBindIndexBuffer) load(userptr, "vkCmdBindIndexBuffer");
    vkCmdBindPipeline = (PFN_vkCmdBindPipeline) load(userptr, "vkCmdBindPipeline");
    vkCmdBindVertexBuffers = (PFN_vkCmdBindVertexBuffers) load(userptr, "vkCmdBindVertexBuffers");
    vkCmdBlitImage = (PFN_vkCmdBlitImage) load(userptr, "vkCmdBlitImage");
    vkCmdClearAttachments = (PFN_vkCmdClearAttachments) load(userptr, "vkCmdClearAttachments");
    vkCmdClearColorImage = (PFN_vkCmdClearColorImage) load(userptr, "vkCmdClearColorImage");
    vkCmdClearDepthStencilImage = (PFN_vkCmdClearDepthStencilImage) load(userptr, "vkCmdClearDepthStencilImage");
    vkCmdCopyBuffer = (PFN_vkCmdCopyBuffer) load(userptr, "vkCmdCopyBuffer");
    vkCmdCopyBufferToImage = (PFN_vkCmdCopyBufferToImage) load(userptr, "vkCmdCopyBufferToImage");
    vkCmdCopyImage = (PFN_vkCmdCopyImage) load(userptr, "vkCmdCopyImage");
    vkCmdCopyImageToBuffer = (PFN_vkCmdCopyImageToBuffer) load(userptr, "vkCmdCopyImageToBuffer");
    vkCmdCopyQueryPoolResults = (PFN_vkCmdCopyQueryPoolResults) load(userptr, "vkCmdCopyQueryPoolResults");
    vkCmdDispatch = (PFN_vkCmdDispatch) load(userptr, "vkCmdDispatch");
    vkCmdDispatchIndirect = (PFN_vkCmdDispatchIndirect) load(userptr, "vkCmdDispatchIndirect");
    vkCmdDraw = (PFN_vkCmdDraw) load(userptr, "vkCmdDraw");
    vkCmdDrawIndexed = (PFN_vkCmdDrawIndexed) load(userptr, "vkCmdDrawIndexed");
    vkCmdDrawIndexedIndirect = (PFN_vkCmdDrawIndexedIndirect) load(userptr, "vkCmdDrawIndexedIndirect");
    vkCmdDrawIndirect = (PFN_vkCmdDrawIndirect) load(userptr, "vkCmdDrawIndirect");
    vkCmdEndQuery = (PFN_vkCmdEndQuery) load(userptr, "vkCmdEndQuery");
    vkCmdEndRenderPass = (PFN_vkCmdEndRenderPass) load(userptr, "vkCmdEndRenderPass");
    vkCmdExecuteCommands = (PFN_vkCmdExecuteCommands) load(userptr, "vkCmdExecuteCommands");
    vkCmdFillBuffer = (PFN_vkCmdFillBuffer) load(userptr, "vkCmdFillBuffer");
    vkCmdNextSubpass = (PFN_vkCmdNextSubpass) load(userptr, "vkCmdNextSubpass");
    vkCmdPipelineBarrier = (PFN_vkCmdPipelineBarrier) load(userptr, "vkCmdPipelineBarrier");
    vkCmdPushConstants = (PFN_vkCmdPushConstants) load(userptr, "vkCmdPushConstants");
    vkCmdResetEvent = (PFN_vkCmdResetEvent) load(userptr, "vkCmdResetEvent");
    vkCmdResetQueryPool = (PFN_vkCmdResetQueryPool) load(userptr, "vkCmdResetQueryPool");
    vkCmdResolveImage = (PFN_vkCmdResolveImage) load(userptr, "vkCmdResolveImage");
    vkCmdSetBlendConstants = (PFN_vkCmdSetBlendConstants) load(userptr, "vkCmdSetBlendConstants");
    vkCmdSetDepthBias = (PFN_vkCmdSetDepthBias) load(userptr, "vkCmdSetDepthBias");
    vkCmdSetDepthBounds = (PFN_vkCmdSetDepthBounds) load(userptr, "vkCmdSetDepthBounds");
    vkCmdSetEvent = (PFN_vkCmdSetEvent) load(userptr, "vkCmdSetEvent");
    vkCmdSetLineWidth = (PFN_vkCmdSetLineWidth) load(userptr, "vkCmdSetLineWidth");
    vkCmdSetScissor = (PFN_vkCmdSetScissor) load(userptr, "vkCmdSetScissor");
    vkCmdSetStencilCompareMask = (PFN_vkCmdSetStencilCompareMask) load(userptr, "vkCmdSetStencilCompareMask");
    vkCmdSetStencilReference = (PFN_vkCmdSetStencilReference) load(userptr, "vkCmdSetStencilReference");
    vkCmdSetStencilWriteMask = (PFN_vkCmdSetStencilWriteMask) load(userptr, "vkCmdSetStencilWriteMask");
    vkCmdSetViewport = (PFN_vkCmdSetViewport) load(userptr, "vkCmdSetViewport");
    vkCmdUpdateBuffer = (PFN_vkCmdUpdateBuffer) load(userptr, "vkCmdUpdateBuffer");
    vkCmdWaitEvents = (PFN_vkCmdWaitEvents) load(userptr, "vkCmdWaitEvents");
    vkCmdWriteTimestamp = (PFN_vkCmdWriteTimestamp) load(userptr, "vkCmdWriteTimestamp");
    vkCreateBuffer = (PFN_vkCreateBuffer) load(userptr, "vkCreateBuffer");
    vkCreateBufferView = (PFN_vkCreateBufferView) load(userptr, "vkCreateBufferView");
    vkCreateCommandPool = (PFN_vkCreateCommandPool) load(userptr, "vkCreateCommandPool");
    vkCreateComputePipelines = (PFN_vkCreateComputePipelines) load(userptr, "vkCreateComputePipelines");
    vkCreateDescriptorPool = (PFN_vkCreateDescriptorPool) load(userptr, "vkCreateDescriptorPool");
    vkCreateDescriptorSetLayout = (PFN_vkCreateDescriptorSetLayout) load(userptr, "vkCreateDescriptorSetLayout");
    vkCreateDevice = (PFN_vkCreateDevice) load(userptr, "vkCreateDevice");
    vkCreateEvent = (PFN_vkCreateEvent) load(userptr, "vkCreateEvent");
    vkCreateFence = (PFN_vkCreateFence) load(userptr, "vkCreateFence");
    vkCreateFramebuffer = (PFN_vkCreateFramebuffer) load(userptr, "vkCreateFramebuffer");
    vkCreateGraphicsPipelines = (PFN_vkCreateGraphicsPipelines) load(userptr, "vkCreateGraphicsPipelines");
    vkCreateImage = (PFN_vkCreateImage) load(userptr, "vkCreateImage");
    vkCreateImageView = (PFN_vkCreateImageView) load(userptr, "vkCreateImageView");
    vkCreateInstance = (PFN_vkCreateInstance) load(userptr, "vkCreateInstance");
    vkCreatePipelineCache = (PFN_vkCreatePipelineCache) load(userptr, "vkCreatePipelineCache");
    vkCreatePipelineLayout = (PFN_vkCreatePipelineLayout) load(userptr, "vkCreatePipelineLayout");
    vkCreateQueryPool = (PFN_vkCreateQueryPool) load(userptr, "vkCreateQueryPool");
    vkCreateRenderPass = (PFN_vkCreateRenderPass) load(userptr, "vkCreateRenderPass");
    vkCreateSampler = (PFN_vkCreateSampler) load(userptr, "vkCreateSampler");
    vkCreateSemaphore = (PFN_vkCreateSemaphore) load(userptr, "vkCreateSemaphore");
    vkCreateShaderModule = (PFN_vkCreateShaderModule) load(userptr, "vkCreateShaderModule");
    vkDestroyBuffer = (PFN_vkDestroyBuffer) load(userptr, "vkDestroyBuffer");
    vkDestroyBufferView = (PFN_vkDestroyBufferView) load(userptr, "vkDestroyBufferView");
    vkDestroyCommandPool = (PFN_vkDestroyCommandPool) load(userptr, "vkDestroyCommandPool");
    vkDestroyDescriptorPool = (PFN_vkDestroyDescriptorPool) load(userptr, "vkDestroyDescriptorPool");
    vkDestroyDescriptorSetLayout = (PFN_vkDestroyDescriptorSetLayout) load(userptr, "vkDestroyDescriptorSetLayout");
    vkDestroyDevice = (PFN_vkDestroyDevice) load(userptr, "vkDestroyDevice");
    vkDestroyEvent = (PFN_vkDestroyEvent) load(userptr, "vkDestroyEvent");
    vkDestroyFence = (PFN_vkDestroyFence) load(userptr, "vkDestroyFence");
    vkDestroyFramebuffer = (PFN_vkDestroyFramebuffer) load(userptr, "vkDestroyFramebuffer");
    vkDestroyImage = (PFN_vkDestroyImage) load(userptr, "vkDestroyImage");
    vkDestroyImageView = (PFN_vkDestroyImageView) load(userptr, "vkDestroyImageView");
    vkDestroyInstance = (PFN_vkDestroyInstance) load(userptr, "vkDestroyInstance");
    vkDestroyPipeline = (PFN_vkDestroyPipeline) load(userptr, "vkDestroyPipeline");
    vkDestroyPipelineCache = (PFN_vkDestroyPipelineCache) load(userptr, "vkDestroyPipelineCache");
    vkDestroyPipelineLayout = (PFN_vkDestroyPipelineLayout) load(userptr, "vkDestroyPipelineLayout");
    vkDestroyQueryPool = (PFN_vkDestroyQueryPool) load(userptr, "vkDestroyQueryPool");
    vkDestroyRenderPass = (PFN_vkDestroyRenderPass) load(userptr, "vkDestroyRenderPass");
    vkDestroySampler = (PFN_vkDestroySampler) load(userptr, "vkDestroySampler");
    vkDestroySemaphore = (PFN_vkDestroySemaphore) load(userptr, "vkDestroySemaphore");
    vkDestroyShaderModule = (PFN_vkDestroyShaderModule) load(userptr, "vkDestroyShaderModule");
    vkDeviceWaitIdle = (PFN_vkDeviceWaitIdle) load(userptr, "vkDeviceWaitIdle");
    vkEndCommandBuffer = (PFN_vkEndCommandBuffer) load(userptr, "vkEndCommandBuffer");
    vkEnumerateDeviceExtensionProperties = (PFN_vkEnumerateDeviceExtensionProperties) load(userptr, "vkEnumerateDeviceExtensionProperties");
    vkEnumerateDeviceLayerProperties = (PFN_vkEnumerateDeviceLayerProperties) load(userptr, "vkEnumerateDeviceLayerProperties");
    vkEnumerateInstanceExtensionProperties = (PFN_vkEnumerateInstanceExtensionProperties) load(userptr, "vkEnumerateInstanceExtensionProperties");
    vkEnumerateInstanceLayerProperties = (PFN_vkEnumerateInstanceLayerProperties) load(userptr, "vkEnumerateInstanceLayerProperties");
    vkEnumeratePhysicalDevices = (PFN_vkEnumeratePhysicalDevices) load(userptr, "vkEnumeratePhysicalDevices");
    vkFlushMappedMemoryRanges = (PFN_vkFlushMappedMemoryRanges) load(userptr, "vkFlushMappedMemoryRanges");
    vkFreeCommandBuffers = (PFN_vkFreeCommandBuffers) load(userptr, "vkFreeCommandBuffers");
    vkFreeDescriptorSets = (PFN_vkFreeDescriptorSets) load(userptr, "vkFreeDescriptorSets");
    vkFreeMemory = (PFN_vkFreeMemory) load(userptr, "vkFreeMemory");
    vkGetBufferMemoryRequirements = (PFN_vkGetBufferMemoryRequirements) load(userptr, "vkGetBufferMemoryRequirements");
    vkGetDeviceMemoryCommitment = (PFN_vkGetDeviceMemoryCommitment) load(userptr, "vkGetDeviceMemoryCommitment");
    vkGetDeviceProcAddr = (PFN_vkGetDeviceProcAddr) load(userptr, "vkGetDeviceProcAddr");
    vkGetDeviceQueue = (PFN_vkGetDeviceQueue) load(userptr, "vkGetDeviceQueue");
    vkGetEventStatus = (PFN_vkGetEventStatus) load(userptr, "vkGetEventStatus");
    vkGetFenceStatus = (PFN_vkGetFenceStatus) load(userptr, "vkGetFenceStatus");
    vkGetImageMemoryRequirements = (PFN_vkGetImageMemoryRequirements) load(userptr, "vkGetImageMemoryRequirements");
    vkGetImageSparseMemoryRequirements = (PFN_vkGetImageSparseMemoryRequirements) load(userptr, "vkGetImageSparseMemoryRequirements");
    vkGetImageSubresourceLayout = (PFN_vkGetImageSubresourceLayout) load(userptr, "vkGetImageSubresourceLayout");
    vkGetInstanceProcAddr = (PFN_vkGetInstanceProcAddr) load(userptr, "vkGetInstanceProcAddr");
    vkGetPhysicalDeviceFeatures = (PFN_vkGetPhysicalDeviceFeatures) load(userptr, "vkGetPhysicalDeviceFeatures");
    vkGetPhysicalDeviceFormatProperties = (PFN_vkGetPhysicalDeviceFormatProperties) load(userptr, "vkGetPhysicalDeviceFormatProperties");
    vkGetPhysicalDeviceImageFormatProperties = (PFN_vkGetPhysicalDeviceImageFormatProperties) load(userptr, "vkGetPhysicalDeviceImageFormatProperties");
    vkGetPhysicalDeviceMemoryProperties = (PFN_vkGetPhysicalDeviceMemoryProperties) load(userptr, "vkGetPhysicalDeviceMemoryProperties");
    vkGetPhysicalDeviceProperties = (PFN_vkGetPhysicalDeviceProperties) load(userptr, "vkGetPhysicalDeviceProperties");
    vkGetPhysicalDeviceQueueFamilyProperties = (PFN_vkGetPhysicalDeviceQueueFamilyProperties) load(userptr, "vkGetPhysicalDeviceQueueFamilyProperties");
    vkGetPhysicalDeviceSparseImageFormatProperties = (PFN_vkGetPhysicalDeviceSparseImageFormatProperties) load(userptr, "vkGetPhysicalDeviceSparseImageFormatProperties");
    vkGetPipelineCacheData = (PFN_vkGetPipelineCacheData) load(userptr, "vkGetPipelineCacheData");
    vkGetQueryPoolResults = (PFN_vkGetQueryPoolResults) load(userptr, "vkGetQueryPoolResults");
    vkGetRenderAreaGranularity = (PFN_vkGetRenderAreaGranularity) load(userptr, "vkGetRenderAreaGranularity");
    vkInvalidateMappedMemoryRanges = (PFN_vkInvalidateMappedMemoryRanges) load(userptr, "vkInvalidateMappedMemoryRanges");
    vkMapMemory = (PFN_vkMapMemory) load(userptr, "vkMapMemory");
    vkMergePipelineCaches = (PFN_vkMergePipelineCaches) load(userptr, "vkMergePipelineCaches");
    vkQueueBindSparse = (PFN_vkQueueBindSparse) load(userptr, "vkQueueBindSparse");
    vkQueueSubmit = (PFN_vkQueueSubmit) load(userptr, "vkQueueSubmit");
    vkQueueWaitIdle = (PFN_vkQueueWaitIdle) load(userptr, "vkQueueWaitIdle");
    vkResetCommandBuffer = (PFN_vkResetCommandBuffer) load(userptr, "vkResetCommandBuffer");
    vkResetCommandPool = (PFN_vkResetCommandPool) load(userptr, "vkResetCommandPool");
    vkResetDescriptorPool = (PFN_vkResetDescriptorPool) load(userptr, "vkResetDescriptorPool");
    vkResetEvent = (PFN_vkResetEvent) load(userptr, "vkResetEvent");
    vkResetFences = (PFN_vkResetFences) load(userptr, "vkResetFences");
    vkSetEvent = (PFN_vkSetEvent) load(userptr, "vkSetEvent");
    vkUnmapMemory = (PFN_vkUnmapMemory) load(userptr, "vkUnmapMemory");
    vkUpdateDescriptorSets = (PFN_vkUpdateDescriptorSets) load(userptr, "vkUpdateDescriptorSets");
    vkWaitForFences = (PFN_vkWaitForFences) load(userptr, "vkWaitForFences");
}
static void glad_vk_load_VK_VERSION_1_1( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_VERSION_1_1) return;
    vkBindBufferMemory2 = (PFN_vkBindBufferMemory2) load(userptr, "vkBindBufferMemory2");
    vkBindImageMemory2 = (PFN_vkBindImageMemory2) load(userptr, "vkBindImageMemory2");
    vkCmdDispatchBase = (PFN_vkCmdDispatchBase) load(userptr, "vkCmdDispatchBase");
    vkCmdSetDeviceMask = (PFN_vkCmdSetDeviceMask) load(userptr, "vkCmdSetDeviceMask");
    vkCreateDescriptorUpdateTemplate = (PFN_vkCreateDescriptorUpdateTemplate) load(userptr, "vkCreateDescriptorUpdateTemplate");
    vkCreateSamplerYcbcrConversion = (PFN_vkCreateSamplerYcbcrConversion) load(userptr, "vkCreateSamplerYcbcrConversion");
    vkDestroyDescriptorUpdateTemplate = (PFN_vkDestroyDescriptorUpdateTemplate) load(userptr, "vkDestroyDescriptorUpdateTemplate");
    vkDestroySamplerYcbcrConversion = (PFN_vkDestroySamplerYcbcrConversion) load(userptr, "vkDestroySamplerYcbcrConversion");
    vkEnumerateInstanceVersion = (PFN_vkEnumerateInstanceVersion) load(userptr, "vkEnumerateInstanceVersion");
    vkEnumeratePhysicalDeviceGroups = (PFN_vkEnumeratePhysicalDeviceGroups) load(userptr, "vkEnumeratePhysicalDeviceGroups");
    vkGetBufferMemoryRequirements2 = (PFN_vkGetBufferMemoryRequirements2) load(userptr, "vkGetBufferMemoryRequirements2");
    vkGetDescriptorSetLayoutSupport = (PFN_vkGetDescriptorSetLayoutSupport) load(userptr, "vkGetDescriptorSetLayoutSupport");
    vkGetDeviceGroupPeerMemoryFeatures = (PFN_vkGetDeviceGroupPeerMemoryFeatures) load(userptr, "vkGetDeviceGroupPeerMemoryFeatures");
    vkGetDeviceQueue2 = (PFN_vkGetDeviceQueue2) load(userptr, "vkGetDeviceQueue2");
    vkGetImageMemoryRequirements2 = (PFN_vkGetImageMemoryRequirements2) load(userptr, "vkGetImageMemoryRequirements2");
    vkGetImageSparseMemoryRequirements2 = (PFN_vkGetImageSparseMemoryRequirements2) load(userptr, "vkGetImageSparseMemoryRequirements2");
    vkGetPhysicalDeviceExternalBufferProperties = (PFN_vkGetPhysicalDeviceExternalBufferProperties) load(userptr, "vkGetPhysicalDeviceExternalBufferProperties");
    vkGetPhysicalDeviceExternalFenceProperties = (PFN_vkGetPhysicalDeviceExternalFenceProperties) load(userptr, "vkGetPhysicalDeviceExternalFenceProperties");
    vkGetPhysicalDeviceExternalSemaphoreProperties = (PFN_vkGetPhysicalDeviceExternalSemaphoreProperties) load(userptr, "vkGetPhysicalDeviceExternalSemaphoreProperties");
    vkGetPhysicalDeviceFeatures2 = (PFN_vkGetPhysicalDeviceFeatures2) load(userptr, "vkGetPhysicalDeviceFeatures2");
    vkGetPhysicalDeviceFormatProperties2 = (PFN_vkGetPhysicalDeviceFormatProperties2) load(userptr, "vkGetPhysicalDeviceFormatProperties2");
    vkGetPhysicalDeviceImageFormatProperties2 = (PFN_vkGetPhysicalDeviceImageFormatProperties2) load(userptr, "vkGetPhysicalDeviceImageFormatProperties2");
    vkGetPhysicalDeviceMemoryProperties2 = (PFN_vkGetPhysicalDeviceMemoryProperties2) load(userptr, "vkGetPhysicalDeviceMemoryProperties2");
    vkGetPhysicalDeviceProperties2 = (PFN_vkGetPhysicalDeviceProperties2) load(userptr, "vkGetPhysicalDeviceProperties2");
    vkGetPhysicalDeviceQueueFamilyProperties2 = (PFN_vkGetPhysicalDeviceQueueFamilyProperties2) load(userptr, "vkGetPhysicalDeviceQueueFamilyProperties2");
    vkGetPhysicalDeviceSparseImageFormatProperties2 = (PFN_vkGetPhysicalDeviceSparseImageFormatProperties2) load(userptr, "vkGetPhysicalDeviceSparseImageFormatProperties2");
    vkTrimCommandPool = (PFN_vkTrimCommandPool) load(userptr, "vkTrimCommandPool");
    vkUpdateDescriptorSetWithTemplate = (PFN_vkUpdateDescriptorSetWithTemplate) load(userptr, "vkUpdateDescriptorSetWithTemplate");
}
static void glad_vk_load_VK_EXT_debug_report( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_EXT_debug_report) return;
    vkCreateDebugReportCallbackEXT = (PFN_vkCreateDebugReportCallbackEXT) load(userptr, "vkCreateDebugReportCallbackEXT");
    vkDebugReportMessageEXT = (PFN_vkDebugReportMessageEXT) load(userptr, "vkDebugReportMessageEXT");
    vkDestroyDebugReportCallbackEXT = (PFN_vkDestroyDebugReportCallbackEXT) load(userptr, "vkDestroyDebugReportCallbackEXT");
}
static void glad_vk_load_VK_EXT_debug_utils( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_EXT_debug_utils) return;
    vkCmdBeginDebugUtilsLabelEXT = (PFN_vkCmdBeginDebugUtilsLabelEXT) load(userptr, "vkCmdBeginDebugUtilsLabelEXT");
    vkCmdEndDebugUtilsLabelEXT = (PFN_vkCmdEndDebugUtilsLabelEXT) load(userptr, "vkCmdEndDebugUtilsLabelEXT");
    vkCmdInsertDebugUtilsLabelEXT = (PFN_vkCmdInsertDebugUtilsLabelEXT) load(userptr, "vkCmdInsertDebugUtilsLabelEXT");
    vkCreateDebugUtilsMessengerEXT = (PFN_vkCreateDebugUtilsMessengerEXT) load(userptr, "vkCreateDebugUtilsMessengerEXT");
    vkDestroyDebugUtilsMessengerEXT = (PFN_vkDestroyDebugUtilsMessengerEXT) load(userptr, "vkDestroyDebugUtilsMessengerEXT");
    vkQueueBeginDebugUtilsLabelEXT = (PFN_vkQueueBeginDebugUtilsLabelEXT) load(userptr, "vkQueueBeginDebugUtilsLabelEXT");
    vkQueueEndDebugUtilsLabelEXT = (PFN_vkQueueEndDebugUtilsLabelEXT) load(userptr, "vkQueueEndDebugUtilsLabelEXT");
    vkQueueInsertDebugUtilsLabelEXT = (PFN_vkQueueInsertDebugUtilsLabelEXT) load(userptr, "vkQueueInsertDebugUtilsLabelEXT");
    vkSetDebugUtilsObjectNameEXT = (PFN_vkSetDebugUtilsObjectNameEXT) load(userptr, "vkSetDebugUtilsObjectNameEXT");
    vkSetDebugUtilsObjectTagEXT = (PFN_vkSetDebugUtilsObjectTagEXT) load(userptr, "vkSetDebugUtilsObjectTagEXT");
    vkSubmitDebugUtilsMessageEXT = (PFN_vkSubmitDebugUtilsMessageEXT) load(userptr, "vkSubmitDebugUtilsMessageEXT");
}
static void glad_vk_load_VK_KHR_swapchain( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_swapchain) return;
    vkAcquireNextImage2KHR = (PFN_vkAcquireNextImage2KHR) load(userptr, "vkAcquireNextImage2KHR");
    vkAcquireNextImageKHR = (PFN_vkAcquireNextImageKHR) load(userptr, "vkAcquireNextImageKHR");
    vkCreateSwapchainKHR = (PFN_vkCreateSwapchainKHR) load(userptr, "vkCreateSwapchainKHR");
    vkDestroySwapchainKHR = (PFN_vkDestroySwapchainKHR) load(userptr, "vkDestroySwapchainKHR");
    vkGetDeviceGroupPresentCapabilitiesKHR = (PFN_vkGetDeviceGroupPresentCapabilitiesKHR) load(userptr, "vkGetDeviceGroupPresentCapabilitiesKHR");
    vkGetDeviceGroupSurfacePresentModesKHR = (PFN_vkGetDeviceGroupSurfacePresentModesKHR) load(userptr, "vkGetDeviceGroupSurfacePresentModesKHR");
    vkGetPhysicalDevicePresentRectanglesKHR = (PFN_vkGetPhysicalDevicePresentRectanglesKHR) load(userptr, "vkGetPhysicalDevicePresentRectanglesKHR");
    vkGetSwapchainImagesKHR = (PFN_vkGetSwapchainImagesKHR) load(userptr, "vkGetSwapchainImagesKHR");
    vkQueuePresentKHR = (PFN_vkQueuePresentKHR) load(userptr, "vkQueuePresentKHR");
}



static int glad_vk_get_extensions( VkPhysicalDevice physical_device, uint32_t *out_extension_count, char ***out_extensions) {
    uint32_t i;
    uint32_t instance_extension_count = 0;
    uint32_t device_extension_count = 0;
    uint32_t max_extension_count;
    uint32_t total_extension_count;
    char **extensions;
    VkExtensionProperties *ext_properties;
    VkResult result;

    if (vkEnumerateInstanceExtensionProperties == NULL || (physical_device != NULL && vkEnumerateDeviceExtensionProperties == NULL)) {
        return 0;
    }

    result = vkEnumerateInstanceExtensionProperties(NULL, &instance_extension_count, NULL);
    if (result != VK_SUCCESS) {
        return 0;
    }

    if (physical_device != NULL) {
        result = vkEnumerateDeviceExtensionProperties(physical_device, NULL, &device_extension_count, NULL);
        if (result != VK_SUCCESS) {
            return 0;
        }
    }

    total_extension_count = instance_extension_count + device_extension_count;
    max_extension_count = instance_extension_count > device_extension_count
        ? instance_extension_count : device_extension_count;

    ext_properties = (VkExtensionProperties*) malloc(max_extension_count * sizeof(VkExtensionProperties));
    if (ext_properties == NULL) {
        return 0;
    }

    result = vkEnumerateInstanceExtensionProperties(NULL, &instance_extension_count, ext_properties);
    if (result != VK_SUCCESS) {
        free((void*) ext_properties);
        return 0;
    }

    extensions = (char**) calloc(total_extension_count, sizeof(char*));
    if (extensions == NULL) {
        free((void*) ext_properties);
        return 0;
    }

    for (i = 0; i < instance_extension_count; ++i) {
        VkExtensionProperties ext = ext_properties[i];

        size_t extension_name_length = strlen(ext.extensionName) + 1;
        extensions[i] = (char*) malloc(extension_name_length * sizeof(char));
        memcpy(extensions[i], ext.extensionName, extension_name_length * sizeof(char));
    }

    if (physical_device != NULL) {
        result = vkEnumerateDeviceExtensionProperties(physical_device, NULL, &device_extension_count, ext_properties);
        if (result != VK_SUCCESS) {
            for (i = 0; i < instance_extension_count; ++i) {
                free((void*) extensions[i]);
            }
            free(extensions);
            return 0;
        }

        for (i = 0; i < device_extension_count; ++i) {
            VkExtensionProperties ext = ext_properties[i];

            size_t extension_name_length = strlen(ext.extensionName) + 1;
            extensions[instance_extension_count + i] = (char*) malloc(extension_name_length * sizeof(char));
            memcpy(extensions[instance_extension_count + i], ext.extensionName, extension_name_length * sizeof(char));
        }
    }

    free((void*) ext_properties);

    *out_extension_count = total_extension_count;
    *out_extensions = extensions;

    return 1;
}

static void glad_vk_free_extensions(uint32_t extension_count, char **extensions) {
    uint32_t i;

    for(i = 0; i < extension_count ; ++i) {
        free((void*) (extensions[i]));
    }

    free((void*) extensions);
}

static int glad_vk_has_extension(const char *name, uint32_t extension_count, char **extensions) {
    uint32_t i;

    for (i = 0; i < extension_count; ++i) {
        if(strcmp(name, extensions[i]) == 0) {
            return 1;
        }
    }

    return 0;
}

static GLADapiproc glad_vk_get_proc_from_userptr(void *userptr, const char* name) {
    return (GLAD_GNUC_EXTENSION (GLADapiproc (*)(const char *name)) userptr)(name);
}

static int glad_vk_find_extensions_vulkan( VkPhysicalDevice physical_device) {
    uint32_t extension_count = 0;
    char **extensions = NULL;
    if (!glad_vk_get_extensions(physical_device, &extension_count, &extensions)) return 0;

    GLAD_VK_EXT_debug_report = glad_vk_has_extension("VK_EXT_debug_report", extension_count, extensions);
    GLAD_VK_EXT_debug_utils = glad_vk_has_extension("VK_EXT_debug_utils", extension_count, extensions);
    GLAD_VK_KHR_swapchain = glad_vk_has_extension("VK_KHR_swapchain", extension_count, extensions);

    glad_vk_free_extensions(extension_count, extensions);

    return 1;
}

static int glad_vk_find_core_vulkan( VkPhysicalDevice physical_device) {
    int major = 1;
    int minor = 0;

#ifdef VK_VERSION_1_1
    if (vkEnumerateInstanceVersion  != NULL) {
        uint32_t version;
        VkResult result;

        result = vkEnumerateInstanceVersion(&version);
        if (result == VK_SUCCESS) {
            major = (int) VK_VERSION_MAJOR(version);
            minor = (int) VK_VERSION_MINOR(version);
        }
    }
#endif

    if (physical_device != NULL && vkGetPhysicalDeviceProperties  != NULL) {
        VkPhysicalDeviceProperties properties;
        vkGetPhysicalDeviceProperties(physical_device, &properties);

        major = (int) VK_VERSION_MAJOR(properties.apiVersion);
        minor = (int) VK_VERSION_MINOR(properties.apiVersion);
    }

    GLAD_VK_VERSION_1_0 = (major == 1 && minor >= 0) || major > 1;
    GLAD_VK_VERSION_1_1 = (major == 1 && minor >= 1) || major > 1;

    return GLAD_MAKE_VERSION(major, minor);
}

int gladLoadVulkanUserPtr( VkPhysicalDevice physical_device, GLADuserptrloadfunc load, void *userptr) {
    int version;

#ifdef VK_VERSION_1_1
    vkEnumerateInstanceVersion  = (PFN_vkEnumerateInstanceVersion) load(userptr, "vkEnumerateInstanceVersion");
#endif
    version = glad_vk_find_core_vulkan( physical_device);
    if (!version) {
        return 0;
    }

    glad_vk_load_VK_VERSION_1_0(load, userptr);
    glad_vk_load_VK_VERSION_1_1(load, userptr);

    if (!glad_vk_find_extensions_vulkan( physical_device)) return 0;
    glad_vk_load_VK_EXT_debug_report(load, userptr);
    glad_vk_load_VK_EXT_debug_utils(load, userptr);
    glad_vk_load_VK_KHR_swapchain(load, userptr);


    return version;
}


int gladLoadVulkan( VkPhysicalDevice physical_device, GLADloadfunc load) {
    return gladLoadVulkanUserPtr( physical_device, glad_vk_get_proc_from_userptr, GLAD_GNUC_EXTENSION (void*) load);
}





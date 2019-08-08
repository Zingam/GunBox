#pragma once

#if defined(__ANDROID__)
#  include "System/Platforms/Android/HostPlatform/GPUDevice_Vulkan_Base_Android.hpp"
#elif defined(_WINDOWS) || defined(__linux__)
#  include "System/Platforms/Common/HostPlatform/GPUDevice_Vulkan_Base.hpp"
#else
#  error Unsupported platform ...
#endif

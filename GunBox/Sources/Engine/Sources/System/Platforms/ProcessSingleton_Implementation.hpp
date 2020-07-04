#pragma once

#if defined(__ANDROID__)
#  include "System/Platforms/Android/HostPlatform/ProcessSingleton_Android.hpp"
#elif defined(__linux__)
#  include "System/Platforms/Linux/HostPlatform/ProcessSingleton_Linux.hpp"
#elif defined(_WINDOWS)
#  include "System/Platforms/Windows/HostPlatform/ProcessSingleton_Windows.hpp"
#else
#  error Unsupported platform ...
#endif

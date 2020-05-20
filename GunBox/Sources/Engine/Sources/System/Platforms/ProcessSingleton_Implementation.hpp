#pragma once

#if defined(__linux__)
#  include "System/Platforms/Linux/HostPlatform/ProcessSingleton_Linux.hpp"
#elif defined(_WINDOWS)
#  include "System/Platforms/Windows/HostPlatform/ProcessSingleton_Windows.hpp"
#else
#  error Unsupported platform ...
#endif

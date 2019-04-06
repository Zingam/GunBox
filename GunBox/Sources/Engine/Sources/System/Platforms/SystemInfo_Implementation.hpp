#pragma once

#if defined(__linux__)
#  include "System/Platforms/Linux/HostPlatform/SystemInfo_Linux.hpp"
#elif defined(_WINDOWS)
#  include "System/Platforms/Windows/HostPlatform/SystemInfo_Windows.hpp"
#else
#  error Unsupported platform
#endif

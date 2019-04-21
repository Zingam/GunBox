#pragma once

#if defined(__linux__)
#  include "System/Platforms/Linux/HostPlatform/SystemConsole_Linux.hpp"
#elif defined(_WINDOWS)
#  include "System/Platforms/Windows/HostPlatform/SystemConsole_Windows.hpp"
#else
#  error Unsupported platform ...
#endif

#pragma once

#if defined(__linux__)
#  include "Linux/HostPlatform_Linux.hpp"
#elif defined(_WINDOWS)
#  include "Windows/HostPlatform_Windows.hpp"
#else
#  error Unsupported platform
#endif

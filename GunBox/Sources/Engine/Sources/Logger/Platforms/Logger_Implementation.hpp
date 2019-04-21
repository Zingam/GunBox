#pragma once

#if defined(__ANDROID__)
#  include "Logger/Platforms/Android/Logger_Android.hpp"
#elif defined(__linux__)
#  include "Logger/Platforms/Linux/Logger_Linux.hpp"
#elif defined(_WINDOWS)
#  include "Logger/Platforms/Windows/Logger_Windows.hpp"
#else
#  error Unsupported platform ...
#endif

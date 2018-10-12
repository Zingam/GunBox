#pragma once

// Project headers - System
#include "System/Platforms/SDL2/SDL2_ErrorChecking.hpp"

#if !defined(LogError)
#  define LogError SDL_LogError
#else
#  error LogError is already defined...
#endif

#if !defined(LogInfo)
#  define LogInfo SDL_Log
#else
#  error LogError is already defined...
#endif

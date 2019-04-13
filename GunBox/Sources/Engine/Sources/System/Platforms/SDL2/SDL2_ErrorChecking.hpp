#pragma once
////////////////////////////////////////////////////////////////////////////////

// Third party libraries
#include <SDL_log.h>

////////////////////////////////////////////////////////////////////////////////
// Macro definitions
////////////////////////////////////////////////////////////////////////////////

#if !defined(SDL_IfFailed)
#  define SDL_IfFailed(function_call) if (0 > function_call)
#else
#  error SDL_IfFailed is already defined
#endif

#if !defined(SDL_LogError)
#  define SDL_LogError(...)                                                    \
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, __VA_ARGS__)
#else
#  error SDL_LogError is already defined
#endif

#pragma once
////////////////////////////////////////////////////////////////////////////////

// Project headers - Logger
#include "Logger/LogAPI.hpp"

////////////////////////////////////////////////////////////////////////////////
// Macro definitions
////////////////////////////////////////////////////////////////////////////////

#if !defined(ELogE)
// Engine library logging macro
#  define ELogE(...) reLogE("[Engine] ! ", __VA_ARGS__)
#else
#  error ELogE is already defined...
#endif

#if !defined(ELogI)
// Engine library logging macro
#  define ELogI(...) reLogI("[Engine] > ", __VA_ARGS__)
#else
#  error ELogI is already defined...
#endif

#if !defined(ELogVE)
// Engine library logging macro
#  define ELogVE(...) reLogE("[Engine] ! [Vulkan]: ", __VA_ARGS__)
#else
#  error ELogVE is already defined...
#endif

#if !defined(ELogVI)
// Engine library logging macro
#  define ELogVI(...) reLogI("[Engine] > [Vulkan]: ", __VA_ARGS__)
#else
#  error ELogVI is already defined...
#endif

#if !defined(ELogVL)
// Engine library logging macro
#  define ELogVL(...) reLogV("[Vulkan] - [Layer] :    ", __VA_ARGS__)
#else
#  error ELogVL is already defined...
#endif

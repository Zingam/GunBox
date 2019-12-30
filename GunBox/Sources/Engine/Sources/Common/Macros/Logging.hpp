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

#if !defined(ELogV)
// Engine library logging macro
#  define ELogV(...) reLogV("[Vulkan] ! ", __VA_ARGS__)
#else
#  error ELogV is already defined...
#endif

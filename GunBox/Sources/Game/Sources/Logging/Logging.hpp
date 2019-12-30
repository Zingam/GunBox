#pragma once
////////////////////////////////////////////////////////////////////////////////

// Project headers - Logger
#include "Logger/LogAPI.hpp"

////////////////////////////////////////////////////////////////////////////////
// Macro definitions
////////////////////////////////////////////////////////////////////////////////

#if !defined(GLogE)
// Game application logging macro
#  define GLogE(...) reLogE("[Game]   > ", __VA_ARGS__)
#else
#  error GLogE is already defined...
#endif

#if !defined(GLogI)
// Game application logging macro
#  define GLogI(...) reLogI("[Game]   > ", __VA_ARGS__)
#else
#  error GLogI is already defined...
#endif

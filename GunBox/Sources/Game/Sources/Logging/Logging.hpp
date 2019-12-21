#pragma once
////////////////////////////////////////////////////////////////////////////////

// Project headers - Logger
#include "Logger/LogAPI.hpp"

////////////////////////////////////////////////////////////////////////////////
// Macro definitions
////////////////////////////////////////////////////////////////////////////////

#if !defined(ELogE)
// Game application logging macro
#  define GLogE(...) reLogE("[Game]   > ", __VA_ARGS__)
#else
#  error ELogE is already defined...
#endif

#if !defined(ELogI)
// Game application logging macro
#  define GLogI(...) reLogI("[Game]   > ", __VA_ARGS__)
#else
#  error ELogI is already defined...
#endif

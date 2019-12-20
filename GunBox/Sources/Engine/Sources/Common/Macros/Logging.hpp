#pragma once
////////////////////////////////////////////////////////////////////////////////

// Project headers - Logger
#include "Logger/LogAPI.hpp"

////////////////////////////////////////////////////////////////////////////////
// Macro definitions
////////////////////////////////////////////////////////////////////////////////

#if !defined(ELogE)
#  define ELogE(...) reLogE("Engine: ", __VA_ARGS__)
#else
#  error ELogE is already defined...
#endif

#if !defined(ELogI)
#  define ELogI(...) reLogI("Engine: ", __VA_ARGS__)
#else
#  error ELogI is already defined...
#endif

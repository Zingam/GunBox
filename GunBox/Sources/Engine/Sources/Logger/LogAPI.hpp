#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

// Project headers
#include "Internal/Logger.hpp"

////////////////////////////////////////////////////////////////////////////////
// Macro definitions
////////////////////////////////////////////////////////////////////////////////

#if !defined(reLogE)
#  if defined(_DEBUG)
#    define reLogE(...) Logger::Log(Logger::LogLevel_t::Error, __VA_ARGS__);
#  else
#    define reLogE(...)
#  endif
#else
#  error reLogE is already defined...
#endif

#if !defined(reLogI)
#  if defined(_DEBUG)
#    define reLogI(...) Logger::Log(Logger::LogLevel_t::Info, __VA_ARGS__);
#  else
#    define reLogI(...)
#  endif
#else
#  error reLogI is already defined...
#endif

#if !defined(reLogW)
#  if defined(_DEBUG)
#    define reLogW(...) Logger::Log(Logger::LogLevel_t::Warning, __VA_ARGS__);
#  else
#    define reLogW(...)
#  endif
#else
#  error reLogW is already defined...
#endif

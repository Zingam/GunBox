#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

// Project headers
#include "Logger.hpp"

////////////////////////////////////////////////////////////////////////////////
// Macro definitions
////////////////////////////////////////////////////////////////////////////////

#if !defined(reLogE)
#  if defined(_DEBUG)
#    define reLogE(message) Logger::Log(message, Logger::LogLevel::Error);
#  else
#    define reLogE(message)
#  endif
#else
#  error reLogE is already defined...
#endif

#if !defined(reLogI)
#  if defined(_DEBUG)
#    define reLogI(message) Logger::Log(message, Logger::LogLevel::Info);
#  else
#    define reLogI(message)
#  endif
#else
#  error reLogI is already defined...
#endif

#if !defined(reLogW)
#  if defined(_DEBUG)
#    define reLogW(message) Logger::Log(message, Logger::LogLevel::Warning);
#  else
#    define reLogW(message)
#  endif
#else
#  error reLogW is already defined...
#endif

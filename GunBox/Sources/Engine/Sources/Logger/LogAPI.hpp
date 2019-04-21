#pragma once

////////////////////////////////////////////////////////////////////////////////
// Defines
////////////////////////////////////////////////////////////////////////////////

#if defined(_DEBUG)
#  define LoggingLevel_Verbose
#endif

////////////////////////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////////////////////////

#if defined(LoggingLevel_Verbose)
// Project headers
#  include "Internal/Logger.hpp"
#endif

////////////////////////////////////////////////////////////////////////////////
// Macro definitions
////////////////////////////////////////////////////////////////////////////////

#if !defined(reLogInitialize)
#  if defined(LoggingLevel_Verbose)
#    define reLogInitialize(logTag) Logger::Logger::CreateInstance(logTag);
#  else
#    define reLogInitialize(...)
#  endif
#else
#  error reLogInitialize is already defined...
#endif

#if !defined(reLogE)
#  if defined(LoggingLevel_Verbose)
#    define reLogE(...) Logger::Log(Logger::LogLevel_t::Error, __VA_ARGS__);
#  else
#    define reLogE(...)
#  endif
#else
#  error reLogE is already defined...
#endif

#if !defined(reLogI)
#  if defined(LoggingLevel_Verbose)
#    define reLogI(...) Logger::Log(Logger::LogLevel_t::Info, __VA_ARGS__);
#  else
#    define reLogI(...)
#  endif
#else
#  error reLogI is already defined...
#endif

#if !defined(reLogW)
#  if defined(LoggingLevel_Verbose)
#    define reLogW(...) Logger::Log(Logger::LogLevel_t::Warning, __VA_ARGS__);
#  else
#    define reLogW(...)
#  endif
#else
#  error reLogW is already defined...
#endif

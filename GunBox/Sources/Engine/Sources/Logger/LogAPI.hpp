#pragma once

////////////////////////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////////////////////////

#if defined(LOGGING_LEVEL_VERBOSE) || defined(LOGGING_LEVEL_INFO) ||           \
  defined(LOGGING_LEVEL_NONE)
// Project headers
#  include "Internal/Logger.hpp"
#endif

////////////////////////////////////////////////////////////////////////////////
// Macro definitions
////////////////////////////////////////////////////////////////////////////////

#if !defined(reLogInitialize)
#  if defined(LOGGING_LEVEL_VERBOSE) || defined(LOGGING_LEVEL_INFO) ||         \
    defined(LOGGING_LEVEL_NONE)
#    define reLogInitialize(logTag) Logger::Logger::CreateInstance(logTag)
#  else
#    define reLogInitialize(...)
#  endif
#else
#  error reLogInitialize is already defined...
#endif

#if !defined(reLog)
#  if defined(LOGGING_LEVEL_VERBOSE) || defined(LOGGING_LEVEL_NONE)
#    define reLog(...) Logger::Log(Logger::LogLevel_t::None, __VA_ARGS__)
#  else
#    define reLog(...)
#  endif
#else
#  error reLogE is already defined...
#endif

#if !defined(reLogE)
#  if defined(LOGGING_LEVEL_VERBOSE)
#    define reLogE(...) Logger::Log(Logger::LogLevel_t::Error, __VA_ARGS__)
#  else
#    define reLogE(...)
#  endif
#else
#  error reLogE is already defined...
#endif

#if !defined(reLogI)
#  if defined(LOGGING_LEVEL_VERBOSE) || defined(LOGGING_LEVEL_INFO)
#    define reLogI(...) Logger::Log(Logger::LogLevel_t::Info, __VA_ARGS__)
#  else
#    define reLogI(...)
#  endif
#else
#  error reLogI is already defined...
#endif

#if !defined(reLogW)
#  if defined(LOGGING_LEVEL_VERBOSE)
#    define reLogW(...) Logger::Log(Logger::LogLevel_t::Warning, __VA_ARGS__)
#  else
#    define reLogW(...)
#  endif
#else
#  error reLogW is already defined...
#endif

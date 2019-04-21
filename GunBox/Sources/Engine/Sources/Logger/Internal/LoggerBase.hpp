#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

// Project headers - Logger
#include "LoggerTypes.hpp"

// C++ Standard Library
#include <map>
#include <sstream>

////////////////////////////////////////////////////////////////////////////////
// Class declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(Logger)

class LoggerBase
{
public:
  // Constructors & Destructors
  LoggerBase();

  // Properties
public:
  auto GetLogStream() -> std::stringstream&;
  auto SetLogLevel(LogLevel_t logLevel) -> void;
  auto SetLogTag(std::string const& logTag) -> void;

  // Methods
protected:
  auto ClearLog() -> void;
  auto DoLog() -> void;
  auto SetLogPrefix() -> void;

protected:
  LogLevel_t logLevel = LogLevel_t::None;
  const std::map<LogLevel_t, std::string> logLevels;
  std::string logTag;
  std::stringstream ss;
};

NAMESPACE_END(Logger)

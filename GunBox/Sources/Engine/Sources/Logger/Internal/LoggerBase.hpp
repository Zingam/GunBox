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
  auto LogStream() -> std::stringstream&;
  auto LogLevel(LogLevel_t logLevel) -> void;
  auto LogTag(std::string const& logTag) -> void;

private:
  auto MaxLogLevelLength() -> std::size_t;

  // Methods
protected:
  auto ClearLog() -> void;
  auto DoLog() -> void;
  auto SetLogPrefix() -> void;

protected:
  LogLevel_t logLevel = LogLevel_t::None;
  std::map<LogLevel_t, std::string> const logLevels;
  std::string logTag;
  std::stringstream ss;

private:
  std::string const bulletPrefix{ "< " };
  std::string const exclamationPrefix{ "! " };
  std::size_t const totalPrefixWidth;
};

NAMESPACE_END(Logger)

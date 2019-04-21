#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

// Project headers
#include "Logger/Internal/LoggerBase.hpp"

////////////////////////////////////////////////////////////////////////////////
// Class declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(Logger)

using Logger_Implementation = class Logger_Windows : public LoggerBase
{
  // Properties
public:
  auto SetLogLevel(LogLevel_t logLevel) -> void;

  // Methods
public:
  auto WriteLog() -> void;
};

NAMESPACE_END(Logger)

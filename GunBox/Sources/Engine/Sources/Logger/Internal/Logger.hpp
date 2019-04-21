#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

// Project headers - Logger
#include "Logger/Internal/LoggerTypes.hpp"
#include "Logger/Platforms/Logger_Implementation.hpp"

// Project headers - Common
#include "Common/implementedBy.hpp"

// C++ Standard Library
#include <map>
#include <memory>
#include <sstream>

////////////////////////////////////////////////////////////////////////////////
// Class declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(Logger)

class Logger : public implementedBy<Logger_Implementation>
{
public:
  Logger();

  // Properties
public:
  auto GetLogStringStream() const -> std::stringstream&;
  auto SetLogLevel(LogLevel_t logLevel) -> void;

  // Methods
public:
  auto WriteLog() const -> void;

private:
  const std::map<LogLevel_t, std::string> logLevels;
};

////////////////////////////////////////////////////////////////////////////////
// Functions
////////////////////////////////////////////////////////////////////////////////

inline auto
GetLoggerInstance() -> Logger&
{
  static std::unique_ptr<Logger> logger;
  if (nullptr == logger) {
    logger = std::make_unique<Logger>();
  }

  return *logger;
}

////////////////////////////////////////////////////////////////////////////////
// Function templates
////////////////////////////////////////////////////////////////////////////////

template<typename... Args>
auto
Log(LogLevel_t logLevel, Args const&... args) -> void
{
  auto& logger = GetLoggerInstance();

  logger.SetLogLevel(logLevel);

  auto& ss = logger.GetLogStringStream();
  (ss << ... << args) << "\n";

  GetLoggerInstance().WriteLog();
}

NAMESPACE_END(Logger)

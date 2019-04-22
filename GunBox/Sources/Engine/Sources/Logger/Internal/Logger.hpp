#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

// Project headers - Logger
#include "Logger/Internal/LoggerTypes.hpp"
#include "Logger/Platforms/Logger_Implementation.hpp"

// Project headers - Common
#include "Common/implementedBy.hpp"

// C Standard Library
#include <cassert>

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
  Logger(std::string const& logtag);

  // Properties
public:
  auto GetLogStringStream() const -> std::stringstream&;
  auto SetLogLevel(LogLevel_t logLevel) -> void;

  // Methods
public:
  auto WriteLog() const -> void;

  // Static methods
public:
  static auto GetInstance() -> Logger&;
  static auto CreateInstance(std::string const& logtag) -> void;

private:
  static std::unique_ptr<Logger> logger;
};

////////////////////////////////////////////////////////////////////////////////
// Function templates
////////////////////////////////////////////////////////////////////////////////

template<typename... Args>
auto
Log(LogLevel_t logLevel, Args const&... args) -> void;

NAMESPACE_END(Logger)

////////////////////////////////////////////////////////////////////////////////
// Inline method & function template implementations
////////////////////////////////////////////////////////////////////////////////

#include "Logger.inl"

////////////////////////////////////////////////////////////////////////////////
#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

// C++ Standard Library
#include <string>

////////////////////////////////////////////////////////////////////////////////
// Class declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(Logger)

enum class LogLevel
{
  Error,
  Info,
  Warning
};

auto
Log(std::string const& message, LogLevel logLevel) -> void;

NAMESPACE_END(Logger)
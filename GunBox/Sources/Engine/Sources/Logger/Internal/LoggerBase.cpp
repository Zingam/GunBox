// Self
#include "LoggerBase.hpp"

// C++ Standard Library
#include <iostream>
#include <string>

NAMESPACE_BEGIN(Logger)

////////////////////////////////////////////////////////////////////////////////
// Constructors & Destructors
////////////////////////////////////////////////////////////////////////////////

LoggerBase::LoggerBase()
  : logLevels{ { LogLevel_t::Error, "Error" },
               { LogLevel_t::Info, "Info" },
               { LogLevel_t::None, "" },
               { LogLevel_t::Warning, "Warning" } }
{}

////////////////////////////////////////////////////////////////////////////////
// Properties
////////////////////////////////////////////////////////////////////////////////

std::stringstream&
LoggerBase::GetLogStream()
{
  return ss;
}

void
LoggerBase::SetLogLevel(LogLevel_t logLevel)
{
  this->logLevel = logLevel;
}

void
LoggerBase::SetLogTag(std::string const& logTag)
{
  this->logTag = logTag;
}

////////////////////////////////////////////////////////////////////////////////
// Methods
////////////////////////////////////////////////////////////////////////////////

void
LoggerBase::ClearLog()
{
  using namespace std::string_literals;

  ss.str(""s);
  ss.clear();
}

void
LoggerBase::DoLog()
{
  // Output to the system console
  std::cout << ss.str();
}

void
LoggerBase::SetLogPrefix()
{
  if (LogLevel_t::None != logLevel) {
    ss << "-- " << logLevels.at(logLevel) << ": ";
  }
}

NAMESPACE_END(Logger)

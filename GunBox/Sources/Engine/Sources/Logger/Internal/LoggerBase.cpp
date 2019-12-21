// Self
#include "LoggerBase.hpp"

// C++ Standard Library
#include <algorithm>
#include <iostream>
#include <string>

using namespace std::string_literals;

NAMESPACE_BEGIN(Logger)

////////////////////////////////////////////////////////////////////////////////
// Constructors & Destructors
////////////////////////////////////////////////////////////////////////////////

LoggerBase::LoggerBase()
  : logLevels{ { LogLevel_t::Error, "Error"s },
               { LogLevel_t::Info, "Info"s },
               { LogLevel_t::None, ""s },
               { LogLevel_t::Warning, "Warning"s } }
  , totalPrefixWidth{ bulletPrefix.size() + MaxLogLevelLength() }
{
  ss.setf(std::ios::left, std::ios::adjustfield);
}

////////////////////////////////////////////////////////////////////////////////
// Properties
////////////////////////////////////////////////////////////////////////////////

std::stringstream&
LoggerBase::LogStream()
{
  return ss;
}

void
LoggerBase::LogLevel(LogLevel_t logLevel)
{
  this->logLevel = logLevel;
}

void
LoggerBase::LogTag(std::string const& logTag)
{
  this->logTag = logTag;
}

std::size_t
LoggerBase::MaxLogLevelLength()
{
  std::size_t maxSize = 0;

  for (auto const& item : logLevels) {
    maxSize = std::max(item.second.size(), maxSize);
  }

  return maxSize;
}

////////////////////////////////////////////////////////////////////////////////
// Methods
////////////////////////////////////////////////////////////////////////////////

void
LoggerBase::ClearLog()
{
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
    ss.width(totalPrefixWidth);
    ss << bulletPrefix + logLevels.at(logLevel) << " - ";
  }
}

NAMESPACE_END(Logger)

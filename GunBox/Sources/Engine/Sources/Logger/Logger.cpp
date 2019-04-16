// Self
#include "Logger.hpp"

// System headers
#if defined(WIN32)
#  include <Windows.h>
#endif

// C Standard Library
#include <cstdio>

// C++ Standard Library
#include <map>
#include <sstream>

NAMESPACE_BEGIN(Logger)

////////////////////////////////////////////////////////////////////////////////
// Static data
////////////////////////////////////////////////////////////////////////////////

static std::map<LogLevel, std::string> logLevels{ { LogLevel::Error, "Error" },
                                                  { LogLevel::Info, "Info" },
                                                  { LogLevel::Warning,
                                                    "Warning" } };

////////////////////////////////////////////////////////////////////////////////
// Functions
////////////////////////////////////////////////////////////////////////////////

void
Log(std::string const& message, LogLevel logLevel)
{
  std::stringstream ss;
  ss << "-- " << logLevels.at(logLevel) << ": " << message << "\n";

  // Output in the system console
  printf("%s", ss.str().c_str());

  // Output in the debug window
#if defined(WIN32)
  OutputDebugString(ss.str().c_str());
#endif
}

NAMESPACE_END(Logger)

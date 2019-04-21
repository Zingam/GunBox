// Self
#include "Logger.hpp"

// System headers
#if defined(WIN32)
#  include <Windows.h>
#endif

// C Standard Library
#include <cstdio>

NAMESPACE_BEGIN(Logger)

////////////////////////////////////////////////////////////////////////////////
// Static data
////////////////////////////////////////////////////////////////////////////////

// clang-format off
std::map<LogLevel_t, std::string> logLevels{
  { LogLevel_t::Error, "Error" },
  { LogLevel_t::Info, "Info" },
  { LogLevel_t::Warning, "Warning" }
};
// clang-format on

std::stringstream&
Logger::GetLogStringStream() const
{
  return o_ptr->GetLogStream();
}

void
Logger::WriteLog() const
{
  o_ptr->WriteLog();
}

////////////////////////////////////////////////////////////////////////////////
// Functions
////////////////////////////////////////////////////////////////////////////////

void
WriteLog(std::stringstream const& ss)
{
  // Output in the system console
  printf("%s", ss.str().c_str());

  // Output in the debug window
#if defined(WIN32)
  OutputDebugString(ss.str().c_str());
#endif
}

NAMESPACE_END(Logger)

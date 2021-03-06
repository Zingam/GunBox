// Self
#include "Logger_Windows.hpp"

// System headers
#include <Windows.h>

NAMESPACE_BEGIN(Logger)

////////////////////////////////////////////////////////////////////////////////
// Properties
////////////////////////////////////////////////////////////////////////////////

void
Logger_Windows::LogLevel(LogLevel_t logLevel)
{
  LoggerBase::LogLevel(logLevel);
  LoggerBase::SetLogPrefix();
}

////////////////////////////////////////////////////////////////////////////////
// Methods
////////////////////////////////////////////////////////////////////////////////

void
Logger_Windows::WriteLog()
{
  // Output to the debug window
  OutputDebugString(ss.str().c_str());

  // Output to the system console
  DoLog();

  // Finish
  ClearLog();
};

NAMESPACE_END(Logger)

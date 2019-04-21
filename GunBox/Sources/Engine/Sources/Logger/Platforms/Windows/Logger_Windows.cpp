// Self
#include "Logger_Windows.hpp"

// System headers
#include <Windows.h>

NAMESPACE_BEGIN(Logger)

void
Logger_Windows::WriteLog()
{
  // Output in the debug window
  OutputDebugString(ss.str().c_str());

  // Output in the system console
  DoLog();

  // Finish
  ClearLog();
};

NAMESPACE_END(Logger)

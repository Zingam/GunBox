// Self
#include "Logger_Linux.hpp"

// C Standard Library
#include <cstdio>

NAMESPACE_BEGIN(Logger)

void
Logger_Windows::WriteLog() const
{
  // Output in the system console
  DoLog();

  // Finish
  ClearLog();
}

NAMESPACE_END(Logger)

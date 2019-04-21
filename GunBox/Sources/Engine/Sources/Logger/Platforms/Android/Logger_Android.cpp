// Self
#include "Logger_Android.hpp"

// System headers
#include <log.h>

NAMESPACE_BEGIN(Logger)

void
Logger_Android::WriteLog() const
{
  // Finish
  ClearLog();
}

NAMESPACE_END(Logger)

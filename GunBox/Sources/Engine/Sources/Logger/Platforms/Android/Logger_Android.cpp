// Self
#include "Logger_Android.hpp"

// System headers
#include <android/log.h>

NAMESPACE_BEGIN(Logger)

////////////////////////////////////////////////////////////////////////////////
// Properties
////////////////////////////////////////////////////////////////////////////////

auto
Logger_Android::SetLogLevel(LogLevel_t logLevel) -> void
{
  LoggerBase::SetLogLevel(logLevel);
}

////////////////////////////////////////////////////////////////////////////////
// Methods
////////////////////////////////////////////////////////////////////////////////

void
Logger_Android::WriteLog()
{
  auto logPriority = ANDROID_LOG_ERROR;

  switch (logLevel) {
    case LogLevel_t::Error: {
      logPriority = ANDROID_LOG_ERROR;
      break;
    }
    case LogLevel_t::Info: {
      logPriority = ANDROID_LOG_INFO;
      break;
    }
    case LogLevel_t::None: {
      logPriority = ANDROID_LOG_VERBOSE;
      break;
    }
    case LogLevel_t::Warning: {
      logPriority = ANDROID_LOG_WARN;
      break;
    }
  }

  // Output to the debug window
  __android_log_write(logPriority, logTag.c_str(), ss.str().c_str());

  // Finish
  ClearLog();
}

NAMESPACE_END(Logger)

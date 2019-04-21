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
  auto logError = ANDROID_LOG_ERROR;

  switch (logLevel) {
    case LogLevel_t::Error: {
      logError = ANDROID_LOG_ERROR;
      break;
    }
    case LogLevel_t::Info: {
      logError = ANDROID_LOG_INFO;
      break;
    }
    case LogLevel_t::None: {
      break;
    }
    case LogLevel_t::Warning: {
      logError = ANDROID_LOG_WARN;
      break;
    }
  }

  // Output to the debug window
  if (LogLevel_t::None != logLevel) {
    __android_log_write(logError, logTag.c_str(), ss.str().c_str());
  }

  // Finish
  ClearLog();
}

NAMESPACE_END(Logger)

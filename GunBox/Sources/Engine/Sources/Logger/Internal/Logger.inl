#pragma once

////////////////////////////////////////////////////////////////////////////////
// Inline method implementations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(Logger)

inline Logger&
Logger::GetInstance()
{
  assert((nullptr != Logger::logger) && "Logger is not yet instanciated!");

  return *Logger::logger;
}

inline void
Logger::CreateInstance(std::string const& logTag)
{
  assert((nullptr == Logger::logger) && "Logger is already instanciated!");

  Logger::logger = std::make_unique<Logger>(logTag);
}

////////////////////////////////////////////////////////////////////////////////
// Function template implementations
////////////////////////////////////////////////////////////////////////////////

template<typename... Args>
void
Log(LogLevel_t logLevel, Args const&... args)
{
  auto& logger = Logger::GetInstance();

  logger.SetLogLevel(logLevel);

  auto& ss = logger.GetLogStringStream();
  (ss << ... << args) << "\n";

  logger.WriteLog();
}

NAMESPACE_END(Logger)

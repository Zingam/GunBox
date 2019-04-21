// Self
#include "LoggerBase.hpp"

// C Standard Library
#include <iostream>
#include <string>

NAMESPACE_BEGIN(Logger)

std::stringstream&
LoggerBase::GetLogStream()
{
  return ss;
}

void
LoggerBase::ClearLog()
{
  using namespace std::string_literals;

  ss.str(""s);
  ss.clear();
}

void
LoggerBase::DoLog()
{
  // Output in the system console
  std::cout << ss.str();
}

NAMESPACE_END(Logger)

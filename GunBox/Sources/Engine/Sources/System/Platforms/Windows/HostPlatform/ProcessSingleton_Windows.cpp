// Self
#include "ProcessSingleton_Windows.hpp"

// System headers
#include <Windows.h>

// C Standard Library
#include <cassert>
#include <cstring>

NAMESPACE_BEGIN(System::HostPlatformClasses)

// Properties
bool
ProcessSingleton_Windows::Initialized()
{
  return isInitalized;
}

bool
ProcessSingleton_Windows::Running()
{
  return isRunning;
}

// Methods
void
ProcessSingleton_Windows::Initialize(std::string const& applicationGUID)
{
  assert(!isInitalized && "ProcessSingleton is already initialized");

  // Create a kernel object
  CreateMutex(
    // Default security attributes
    nullptr,
    // Initially not owned
    FALSE,
    // Named mutext
    applicationGUID.c_str());

  isRunning = (::GetLastError() == ERROR_ALREADY_EXISTS) ||
              (::GetLastError() == ERROR_ACCESS_DENIED);

  isInitalized = true;
}

void
ProcessSingleton_Windows::Finalize()
{
  isInitalized = false;
}

NAMESPACE_END(System::HostPlatformClasses)

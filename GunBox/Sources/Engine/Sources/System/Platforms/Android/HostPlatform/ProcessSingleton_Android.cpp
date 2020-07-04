// Self
#include "ProcessSingleton_Android.hpp"

NAMESPACE_BEGIN(System::HostPlatformClasses)

// Properties
bool
ProcessSingleton_Android::Initialized()
{
  return isInitalized;
}

bool
ProcessSingleton_Android::Running()
{
  return isRunning;
}

// Methods
void
ProcessSingleton_Android::Initialize(std::string const& applicationGUID)
{
}

void
ProcessSingleton_Android::Finalize()
{
}

NAMESPACE_END(System::HostPlatformClasses)

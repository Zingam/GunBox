// Self
#include "ProcessSingleton.hpp"

NAMESPACE_BEGIN(System::HostPlatformClasses)

bool
System::HostPlatformClasses::ProcessSingleton::Initialized()
{
  return o_ptr->Initialized();
}

bool
System::HostPlatformClasses::ProcessSingleton::Running()
{
  return o_ptr->Running();
}


void
ProcessSingleton::Initialize(std::string const& applicationGUID)
{
  return o_ptr->Initialize(applicationGUID);
}

NAMESPACE_END(System::HostPlatformClasses)

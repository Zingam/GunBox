// Self
#include "SystemInfo_Windows.hpp"

NAMESPACE_BEGIN(System::HostPlatformClasses)

CompilerInfo const&
SystemInfo_Windows::CompilerInformation() const
{
  return this->compilerInfo;
}

NAMESPACE_END(System::HostPlatformClasses)

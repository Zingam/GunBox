// Self
#include "SystemInfo_Linux.hpp"

NAMESPACE_BEGIN(System::HostPlatformClasses)

CompilerInfo const&
SystemInfo_Linux::CompilerInformation() const
{
  return this->compilerInfo;
}

NAMESPACE_END(System::HostPlatformClasses)

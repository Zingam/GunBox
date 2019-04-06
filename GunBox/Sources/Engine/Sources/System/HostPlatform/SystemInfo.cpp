// Self
#include "SystemInfo.hpp"

NAMESPACE_BEGIN(System::HostPlatformClasses)

CompilerInfo const&
SystemInfo::CompilerInfo() const
{
  return o_ptr->CompilerInformation();
}

NAMESPACE_END(System::HostPlatformClasses)

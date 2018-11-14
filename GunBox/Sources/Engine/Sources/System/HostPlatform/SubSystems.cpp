// Self
#include "SubSystems.hpp"

NAMESPACE_BEGIN(System::HostPlatformClasses)

bool
SubSystems::Initialize()
{
  return o_ptr->Initialize();
}

void
SubSystems::Finalize()
{
  o_ptr->Finalize();
}

NAMESPACE_END(System::HostPlatformClasses)

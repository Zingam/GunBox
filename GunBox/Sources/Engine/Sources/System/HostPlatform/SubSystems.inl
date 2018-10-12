#pragma once

////////////////////////////////////////////////////////////////////////////////
// Inline method implementations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(System::HostPlatformClasses)

inline bool
SubSystems::Initialize()
{
  return o_ptr->Initialize();
}

inline void
SubSystems::Finalize()
{
  o_ptr->Finalize();
}

NAMESPACE_END(System::HostPlatformClasses)

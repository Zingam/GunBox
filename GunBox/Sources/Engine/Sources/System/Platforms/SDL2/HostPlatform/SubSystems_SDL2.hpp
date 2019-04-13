#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(System::HostPlatformClasses)

using SubSystems_Implementation = class SubSystems_SDL
{
public:
  auto Initialize() -> bool;
  auto Finalize() -> void;
};

NAMESPACE_END(System::HostPlatformClasses)

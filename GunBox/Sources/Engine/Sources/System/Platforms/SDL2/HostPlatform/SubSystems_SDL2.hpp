#pragma once

// BASE MACROS header
#include "Common/Macros/Base.hpp"

NAMESPACE_BEGIN(System::HostPlatformClasses)

using SubSystems_Implementation = class SubSystems_SDL
{
public:
  auto Initialize() -> bool;
  auto Finalize() -> void;
};

NAMESPACE_END(System::HostPlatformClasses)

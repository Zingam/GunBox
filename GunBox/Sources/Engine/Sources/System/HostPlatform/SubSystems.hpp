#pragma once

// BASE MACROS header
#include "Common/Macros/Base.hpp"

// Project headers - Common
#include "Common/implementedBy.hpp"
// Project headers - System
#include "System/Platforms/SubSystems_Implementation.hpp"

NAMESPACE_BEGIN(System::HostPlatformClasses)

class SubSystems : public implementedBy<SubSystems_Implementation>
{
  // Methods
public:
  auto Initialize() -> bool;
  auto Finalize() -> void;
};

NAMESPACE_END(System)

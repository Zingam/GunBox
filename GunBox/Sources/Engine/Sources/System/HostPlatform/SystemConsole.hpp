#pragma once

// BASE MACROS header
#include "Common/Macros/Base.hpp"

// Project headers - Common
#include "Common/implementedBy.hpp"
// Project headers - System
#include "System/Platforms/SystemConsole_Implementation.hpp"

NAMESPACE_BEGIN(System::HostPlatformClasses)

class SystemConsole : public implementedBy<SystemConsole_Implementation>
{
  // Methods
public:
  auto Hide() -> void;
  auto Show() -> void;
};

NAMESPACE_END(System::HostPlatformClasses)

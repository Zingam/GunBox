#pragma once

// Project headers - Common
#include "Common/Macros/Base.hpp"
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

////////////////////////////////////////////////////////////////////////////////
// Inline method implementations
////////////////////////////////////////////////////////////////////////////////

#include "SystemConsole.inl"

////////////////////////////////////////////////////////////////////////////////

#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

// Project headers - System
#include "System/Platforms/SystemConsole_Implementation.hpp"

// Project headers - Common
#include "Common/implementedBy.hpp"

////////////////////////////////////////////////////////////////////////////////
// Class declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(System::HostPlatformClasses)

class SystemConsole : public implementedBy<SystemConsole_Implementation>
{
  // Methods
public:
  auto EnableInput() const -> void;
  auto Hide() const -> void;
  auto Pause() const -> void;
  auto Show() const -> void;
};

NAMESPACE_END(System::HostPlatformClasses)

#pragma once

// Project headers - Common
#include "Common/Macros/Base.hpp"
#include "Common/implementedBy.hpp"

// Project headers - System
#include "Platforms/HostPlatform_Implementation.hpp"

NAMESPACE_START(System)

class HostPlatform : public implementedBy<HostPlatform_Implementation>
{
  // Methods
public:
  auto HideSystemConsole() -> void;
  auto ShowSystemConsole() -> void;
};

NAMESPACE_END(System)

////////////////////////////////////////////////////////////////////////////////
// Inline method implementations
////////////////////////////////////////////////////////////////////////////////

#include "HostPlatform.inl"

////////////////////////////////////////////////////////////////////////////////

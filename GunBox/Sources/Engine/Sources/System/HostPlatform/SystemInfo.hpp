#pragma once

// BASE MACROS header
#include "Common/Macros/Base.hpp"

// Project headers - Common
#include "Common/implementedBy.hpp"
// Project headers - System
#include "System/Platforms/SystemInfo_Implementation.hpp"

NAMESPACE_BEGIN(System::HostPlatformClasses)

class SystemInfo : public implementedBy<SystemInfo_Implementation>
{
  // Properties
public:
  auto CompilerInfo() const -> CompilerInfo const&;
};

NAMESPACE_END(System)

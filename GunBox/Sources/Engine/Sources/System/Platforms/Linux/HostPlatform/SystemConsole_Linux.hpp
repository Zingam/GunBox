#pragma once

// BASE MACROS header
#include "Common/Macros/Base.hpp"

NAMESPACE_BEGIN(System::HostPlatformClasses)

using SystemConsole_Implementation = class SystemConsole_Linux
{
public:
  auto Hide() -> void;
  auto Show() -> void;
};

NAMESPACE_END(System::HostPlatformClasses)

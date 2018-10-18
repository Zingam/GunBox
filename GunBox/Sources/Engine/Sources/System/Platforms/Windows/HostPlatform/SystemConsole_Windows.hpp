#pragma once

// Project headers - BASE
#include "Common/Macros/Base.hpp"

NAMESPACE_BEGIN(System::HostPlatformClasses)

using SystemConsole_Implementation = class SystemConsole_Windows
{
public:
  auto Hide() -> void;
  auto Show() -> void;
};

NAMESPACE_END(System::HostPlafroms)

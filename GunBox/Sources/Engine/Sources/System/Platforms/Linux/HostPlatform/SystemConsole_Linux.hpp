#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(System::HostPlatformClasses)

using SystemConsole_Implementation = class SystemConsole_Linux
{
public:
  auto Hide() -> void;
  auto Show() -> void;
};

NAMESPACE_END(System::HostPlatformClasses)

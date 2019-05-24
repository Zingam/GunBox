#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(System::HostPlatformClasses)

using SystemConsole_Implementation = class SystemConsole_Linux
{
public:
  auto EnableInput() -> void;
  auto Hide() -> void;
  auto Pause() const -> void;
  auto Show() -> void;
};

NAMESPACE_END(System::HostPlatformClasses)

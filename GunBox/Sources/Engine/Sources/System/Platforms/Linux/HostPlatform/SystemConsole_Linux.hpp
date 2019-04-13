#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(System::HostPlatformClasses)

using SystemConsole_Implementation = class SystemConsole_Linux
{
public:
  auto Hide() const -> void;
  auto Pause() const -> void;
  auto Show() const -> void;
};

NAMESPACE_END(System::HostPlatformClasses)

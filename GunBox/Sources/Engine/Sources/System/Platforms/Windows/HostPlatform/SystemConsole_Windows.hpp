#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(System::HostPlatformClasses)

using SystemConsole_Implementation = class SystemConsole_Windows
{
public:
  auto Hide() const -> void;
  auto Pause() const -> void;
  auto Show() const -> void;
};

NAMESPACE_END(System::HostPlafroms)

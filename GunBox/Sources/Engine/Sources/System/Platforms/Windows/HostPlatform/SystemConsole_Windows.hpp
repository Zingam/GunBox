#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Class declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(System::HostPlatformClasses)

using SystemConsole_Implementation = class SystemConsole_Windows
{
public:
  auto EnableInput() -> void;
  auto Hide() -> void;
  auto Pause() const -> void;
  auto Show() -> void;

private:
  bool isInputEnabled = false;
  bool isShown = false;
};

NAMESPACE_END(System::HostPlafroms)

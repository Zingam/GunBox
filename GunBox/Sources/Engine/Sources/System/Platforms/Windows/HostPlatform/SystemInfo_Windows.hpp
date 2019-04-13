#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

// Project headers - System/Platforms
#include "System/Platforms/Common/CompilerInfo.hpp"

NAMESPACE_BEGIN(System::HostPlatformClasses)

using SystemInfo_Implementation = class SystemInfo_Windows
{
public:
  auto CompilerInformation() const -> CompilerInfo const&;

private:
  CompilerInfo compilerInfo;
};

NAMESPACE_END(System::HostPlafroms)

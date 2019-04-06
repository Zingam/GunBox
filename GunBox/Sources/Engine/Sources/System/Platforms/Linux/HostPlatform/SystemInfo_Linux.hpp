#pragma once

// BASE MACROS header
#include "Common/Macros/Base.hpp"

// Project headers - System/Platforms
#include "System/Platforms/Common/CompilerInfo.hpp"

NAMESPACE_BEGIN(System::HostPlatformClasses)

using SystemInfo_Implementation = class SystemInfo_Linux
{
public:
  auto CompilerInformation() const -> CompilerInfo const&;

private:
  CompilerInfo compilerInfo;
};

NAMESPACE_END(System::HostPlafroms)

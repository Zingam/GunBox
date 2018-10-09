#pragma once

// Project headers - Common
#include "Common/Macros/Base.hpp"

NAMESPACE_BEGIN(System)

using HostPlatform_Implementation = class HostPlatform_Windows
{
public:
  auto HideSystemConsole() -> void;
  auto ShowSystemConsole() -> void;
};

NAMESPACE_END(System)

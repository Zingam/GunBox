#pragma once

// Project headers - Common
#include "Common/Macros/Base.hpp"

NAMESPACE_START(System)

using HostPlatform_Implementation = class HostPlatform_Linux
{
public:
  auto HideSystemConsole() -> void;
  auto ShowSystemConsole() -> void;
};

NAMESPACE_END(System)
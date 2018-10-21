#pragma once

// Project headers - BASE
#include "Common/Macros/Base.hpp"

NAMESPACE_BEGIN(System)

class SystemEventCallbacks
{
public:
  SystemEventCallbacks() = default;

  virtual ~SystemEventCallbacks() = 0;

  // Pure virtual methods
public:
  // clang-format off
  virtual auto Quit()
    -> void = 0;
  // clang-format on
};

NAMESPACE_END(System)

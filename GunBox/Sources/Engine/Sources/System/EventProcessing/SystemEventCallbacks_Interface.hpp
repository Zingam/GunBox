#pragma once

// BASE MACROS header
#include "Common/Macros/Base.hpp"

NAMESPACE_BEGIN(System::EventProcessing)

class SystemEventCallbacks
{
public:
  virtual ~SystemEventCallbacks() = 0;

  // Pure virtual methods
public:
  // clang-format off
  virtual auto Quit()
    -> void = 0;
  // clang-format on
};

NAMESPACE_END(System::EventProcessing)

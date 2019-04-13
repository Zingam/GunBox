#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(System::EventProcessing)

class SystemEventCallbacks_Interface
{
public:
  virtual ~SystemEventCallbacks_Interface() = 0;

  // Pure virtual methods
public:
  // clang-format off
  virtual auto Quit()
    -> void = 0;
  // clang-format on
};

NAMESPACE_END(System::EventProcessing)

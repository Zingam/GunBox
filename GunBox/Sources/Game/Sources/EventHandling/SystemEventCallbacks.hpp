#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

// Engine headers - System
#include "System/EventProcessing/SystemEventCallbacks_Interface.hpp"

NAMESPACE_BEGIN(GunBox)

class SystemEventCallbacks final
  : public System::EventProcessing::SystemEventCallbacks_Interface
{
public:
  ~SystemEventCallbacks() final;

  // Virtual methods
public:
  // clang-format off
  auto Quit()
    -> void final;
  // clang-format on
};

NAMESPACE_END(GunBox)

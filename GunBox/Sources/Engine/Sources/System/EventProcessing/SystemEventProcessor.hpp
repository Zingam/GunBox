#pragma once

// BASE MACROS header
#include "Common/Macros/Base.hpp"

// Project headers - Common
#include "Common/SimpleDelegate.hpp"
// Project headers - System
#include "System/EventProcessing/SystemEventCallbacks_Interface.hpp"

// C++ Standard Library
#include <memory>

NAMESPACE_BEGIN(System::EventProcessing)

class SystemEventProcessor
{
public:
  auto InitializeCallbacks(
    std::shared_ptr<SystemEventCallbacks_Interface> const systemEventCallbacks) -> void;

  auto InitializeCallbacks(SystemEventCallbacks_Interface& systemEventCallbacks)
    -> void;

  // Callbacks
private:
  // clang-format off
  std::unique_ptr<SimpleDelegate<SystemEventCallbacks_Interface,
    decltype(&SystemEventCallbacks_Interface::Quit)>>
    cbQuit_UPtr;
  // clang-format on

private:
  friend class SystemEventProcessorAccessor;
};

NAMESPACE_END(System::EventProcessing)

#pragma once

// Project headers - BASE
#include "Common/Macros/Base.hpp"

// Project headers - Common
#include "Common/SimpleDelegate.hpp"
// Project headers - System
#include "System/EventProcessing/SystemEventCallbacks.hpp"

// C++ Standard Library
#include <memory>

NAMESPACE_BEGIN(System::EventProcessing)

class SystemEventProcessor
{
public:
  ~SystemEventProcessor();

public:
  auto InitializeCallbacks(
    std::shared_ptr<SystemEventCallbacks> const systemEventCallbacks) -> void;

  auto InitializeCallbacks(SystemEventCallbacks& systemEventCallbacks)
    -> void;

  // Callbacks
private:
  // clang-format off
  std::unique_ptr<SimpleDelegate<SystemEventCallbacks,
    decltype(&SystemEventCallbacks::Quit)>>
    cbQuit_UPtr;
  // clang-format on

private:
  friend class SystemEventProcessorAccessor;
};

NAMESPACE_END(System::EventProcessing)

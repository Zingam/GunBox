#pragma once

// Project headers - BASE
#include "Common/Macros/Base.hpp"

// Project headers - Common
#include "Common/SimpleDelegate.hpp"
// Project headers - System
#include "System/EventProcessing/SystemEventCallbacks.hpp"

// C++ Standard Library
#include <memory>

NAMESPACE_BEGIN(System)

class SystemEventProcessor
{
public:
  ~SystemEventProcessor();

public:
  auto SetSystemEventCallbacksObject(
    std::shared_ptr<SystemEventCallbacks> const systemEventCallbacks) -> void;

  auto SetSystemEventCallbacksObject(SystemEventCallbacks& systemEventCallbacks)
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

NAMESPACE_END(System)

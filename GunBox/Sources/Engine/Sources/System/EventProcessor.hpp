#pragma once

// Project headers - Common
#include "Common/Macros/Base.hpp"

// Project headers - System
#include "System/EventHandlers/EventHandler.hpp"

// C++ Standard Library
#include <memory>
#include <vector>

NAMESPACE_BEGIN(System)

class EventProcessor
{
public:
  auto ProcessEvents() -> void;
  template<typename EventHandler, typename... Args>
  auto RegisterEventHandler(Args&&... args) -> void;

private:
  std::vector<std::unique_ptr<System::EventHandlers::EventHandler>>
    eventHandlers;
};

NAMESPACE_END(System)

////////////////////////////////////////////////////////////////////////////////
// Inline method implementations
////////////////////////////////////////////////////////////////////////////////

#include "EventProcessor.inl"

////////////////////////////////////////////////////////////////////////////////

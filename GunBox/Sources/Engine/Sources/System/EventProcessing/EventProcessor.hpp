#pragma once

// Project headers - BASE
#include "Common/Macros/Base.hpp"

// Project headers - System
#include "System/EventProcessing/EventHandlers/EventHandler.hpp"

// C++ Standard Library
#include <memory>
#include <vector>

NAMESPACE_BEGIN(System)

class EventProcessor
{
  // Methods
public:
  auto ProcessEvents() -> void;

  // Method templates
public:
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

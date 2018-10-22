#pragma once

// Project headers - BASE
#include "Common/Macros/Base.hpp"

// Project headers - System
#include "System/EventProcessing/EventHandlers/EventHandler.hpp"
#include "System/EventProcessing/InputEventProcessor.hpp"
#include "System/EventProcessing/SystemEventProcessor.hpp"

// C++ Standard Library
#include <memory>
#include <vector>

NAMESPACE_BEGIN(System)

class EventProcessor
{
public:
  EventProcessor();

  // Methods
public:
  auto ProcessEvents() const -> void;

  // Method templates
public:
  template<typename EventHandler, typename... Args>
  auto RegisterEventHandler(Args&&... args) -> void;

private:
  auto InitializeInputEventHandlers() -> void;
  auto InitializeSystemEventHandlers() -> void;

private:
  std::vector<std::unique_ptr<System::EventHandlers::EventHandler>>
    eventHandlers;
  InputEventProcessor inputEventProcessor;
  SystemEventProcessor systemEventProcessor;
};

NAMESPACE_END(System)

////////////////////////////////////////////////////////////////////////////////
// Inline method implementations
////////////////////////////////////////////////////////////////////////////////

#include "EventProcessor.inl"

////////////////////////////////////////////////////////////////////////////////

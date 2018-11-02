#pragma once

// BASE MACROS header
#include "Common/Macros/Base.hpp"

// Project headers - System
#include "System/EventProcessing/EventHandlers/EventHandler.hpp"
#include "System/EventProcessing/InputEventProcessor.hpp"
#include "System/EventProcessing/SystemEventProcessor.hpp"

// C++ Standard Library
#include <memory>
#include <vector>

////////////////////////////////////////////////////////////////////////////////
// Forward declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(System::EventProcessing)

class InputEventCallbacks_Interface;
class SystemEventCallbacks_Interface;

NAMESPACE_END(System::EventProcessing)

////////////////////////////////////////////////////////////////////////////////
// Class declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(System)

class EventProcessor
{
public:
  EventProcessor();

  // Methods
public:
  // clang-format off
  auto InitializeCallbacks(
    System::EventProcessing::InputEventCallbacks_Interface& inputEventCallbacks)
    -> void;

  auto InitializeCallbacks(
    System::EventProcessing::SystemEventCallbacks_Interface& systemEventCallbacks)
    -> void;

  auto ProcessEvents() const -> void;
  // clang-format on

  // Properties
public:
  System::EventProcessing::InputEventProcessor& InputEventProcessor();
  System::EventProcessing::SystemEventProcessor& SystemEventProcessor();

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
  System::EventProcessing::InputEventProcessor inputEventProcessor;
  System::EventProcessing::SystemEventProcessor systemEventProcessor;
};

NAMESPACE_END(System)

////////////////////////////////////////////////////////////////////////////////
// Inline method implementations
////////////////////////////////////////////////////////////////////////////////

#include "EventProcessor.inl"

////////////////////////////////////////////////////////////////////////////////

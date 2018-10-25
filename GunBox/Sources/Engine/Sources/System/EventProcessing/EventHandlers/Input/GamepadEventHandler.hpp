#pragma once

// BASE MACROS header
#include "Common/Macros/Base.hpp"

// Project headers - System
#include "System/EventProcessing/EventHandlers/EventHandler.hpp"

////////////////////////////////////////////////////////////////////////////////
// Forward declarations
////////////////////////////////////////////////////////////////////////////////

union SDL_Event;

NAMESPACE_BEGIN(System::EventProcessing)

class InputEventProcessor;

NAMESPACE_END(System::EventProcessing)

////////////////////////////////////////////////////////////////////////////////
// Class declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(System::EventHandlers)

class GamepadEventHandler : public EventHandler
{
public:
  GamepadEventHandler(
    System::EventProcessing::InputEventProcessor& inputProcessor);

  ~GamepadEventHandler() final;

public:
  auto Process(SDL_Event const& event) -> bool final;

private:
  System::EventProcessing::InputEventProcessor& inputProcessor;
};

NAMESPACE_END(System::EventHandlers)

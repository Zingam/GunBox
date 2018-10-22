#pragma once

// Project headers - BASE
#include "Common/Macros/Base.hpp"

// Project headers - System
#include "System/EventProcessing/EventHandlers/EventHandler.hpp"

////////////////////////////////////////////////////////////////////////////////
// Forward declarations
////////////////////////////////////////////////////////////////////////////////

union SDL_Event;

NAMESPACE_BEGIN(System)

class InputEventProcessor;

NAMESPACE_END(System)

////////////////////////////////////////////////////////////////////////////////
// Class declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(System::EventHandlers)

class KeyboardEventHandler : public EventHandler
{
public:
  KeyboardEventHandler(InputEventProcessor& inputProcessor);

  ~KeyboardEventHandler() final;

public:
  auto Process(SDL_Event const& event) -> bool final;

private:
  InputEventProcessor& inputProcessor;
};

NAMESPACE_END(System::EventHandlers)

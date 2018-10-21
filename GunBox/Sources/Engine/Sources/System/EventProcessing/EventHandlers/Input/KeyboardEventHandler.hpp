#pragma once

// Project headers - BASE
#include "Common/Macros/Base.hpp"

// Project headers - System
#include "System/EventProcessing/EventHandlers/EventHandler.hpp"
#include "System/EventProcessing/InputProcessor.hpp"

////////////////////////////////////////////////////////////////////////////////
// Forward declarations
////////////////////////////////////////////////////////////////////////////////

union SDL_Event;

////////////////////////////////////////////////////////////////////////////////
// Class declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(System::EventHandlers::IO)

class KeyboardEventHandler : public EventHandler
{
public:
  KeyboardEventHandler(InputProcessor& inputProcessor);

  ~KeyboardEventHandler() final;

public:
  auto Process(SDL_Event const& event) -> bool final;

private:
  InputProcessor& inputProcessor;
};

NAMESPACE_END(System::EventHandlers::IO)

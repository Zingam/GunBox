#pragma once

// Project headers - Common
#include "Common/Macros/Base.hpp"

// Project headers - System
#include "System/EventHandlers/EventHandler.hpp"
#include "System/InputProcessor.hpp"

union SDL_Event;

NAMESPACE_BEGIN(System::EventHandlers::IO)

class KeyboardEventHandler : public EventHandler
{
public:
  KeyboardEventHandler(InputProcessor& inputProcessor);

public:
  auto Process(SDL_Event const& event) -> bool final;

private:
  InputProcessor& inputProcessor;
};

NAMESPACE_END(System::EventHandlers::IO)

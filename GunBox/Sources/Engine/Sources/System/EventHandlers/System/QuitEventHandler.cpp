// Self
#include "QuitEventHandler.hpp"

#include "SDL_events.h"

NAMESPACE_BEGIN(System::EventHandlers::System)

Quit::~Quit() {}

bool
Quit::Process(SDL_Event const& event)
{
  switch (event.type) {
    case SDL_QUIT: {
      return true;
    }
    default: {
      return false;
    }
  }
}

NAMESPACE_END(System::EventHandlers::System)

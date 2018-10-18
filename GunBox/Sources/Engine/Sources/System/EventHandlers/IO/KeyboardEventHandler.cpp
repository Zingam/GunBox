// Self
#include "KeyboardEventHandler.hpp"

// Third party
#include <SDL_events.h>

NAMESPACE_BEGIN(System::EventHandlers::IO)

KeyboardEventHandler::KeyboardEventHandler(InputProcessor& inputProcessor)
  : inputProcessor{ inputProcessor }
{}

bool
KeyboardEventHandler::Process(SDL_Event const& event)
{
  auto key = event.key;
  // Events are ordered in the most likely frequency occurence
  switch (event.type) {
    case SDL_KEYDOWN: {
      key.keysym;
      return true;
    }
    case SDL_KEYUP: {
      key.keysym;
      return true;
    }
    default: {
      return false;
    }
  }
}

NAMESPACE_END(System::EventHandlers::IO)

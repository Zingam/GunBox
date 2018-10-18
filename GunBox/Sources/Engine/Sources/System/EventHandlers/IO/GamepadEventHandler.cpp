// Self
#include "GamepadEventHandler.hpp"

// Third party
#include <SDL_events.h>
#include <SDL_gamecontroller.h>

NAMESPACE_BEGIN(System::EventHandlers::IO)

GamepadEventHandler::GamepadEventHandler(InputProcessor& inputProcessor)
  : inputProcessor{ inputProcessor }
{}

bool
GamepadEventHandler::Process(SDL_Event const& event)
{
  // Events are ordered in the most likely frequency occurence
  switch (event.type) {
    case SDL_CONTROLLERAXISMOTION: {
      event.caxis;
      return true;
    }
    case SDL_CONTROLLERBUTTONDOWN: {
      event.cbutton;
      return true;
    }
    case SDL_CONTROLLERBUTTONUP: {
      event.cbutton;
      return true;
    }
    case SDL_CONTROLLERDEVICEADDED: {
      inputProcessor.AddGamepad(event.cdevice.which);
      return true;
    }
    case SDL_CONTROLLERDEVICEREMOVED: {
      inputProcessor.RemoveGamepad(event.cdevice.which);
      return true;
    }
    default: {
      return false;
    }
  }
}

NAMESPACE_END(System::EventHandlers::IO)

// Self
#include "ControllerDeviceAdded.hpp"

// Third party
#include <SDL_events.h>

NAMESPACE_START(System::EventHandlers::Controller)

DeviceAdded::DeviceAdded(InputProcessor& inputProcessor)
  : inputProcessor{ inputProcessor }
{}

bool
DeviceAdded::Process(SDL_Event const& event)
{
  if (SDL_CONTROLLERDEVICEADDED != event.type) {
    return false;
  }
 
  inputProcessor.AddGameController(event.cdevice.which);
  return false;
}

NAMESPACE_END(System::EventHandlers::Controller)

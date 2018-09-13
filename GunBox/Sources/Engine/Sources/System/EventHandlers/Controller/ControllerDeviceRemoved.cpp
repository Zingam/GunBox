// Self
#include "ControllerDeviceRemoved.hpp"

#include <SDL_events.h>

NAMESPACE_START(System::EventHandlers::Controller)

DeviceRemoved::DeviceRemoved(InputProcessor& inputProcessor)
  : inputProcessor{ inputProcessor }
{}

bool
DeviceRemoved::Process(SDL_Event const& event)
{
  if (SDL_CONTROLLERDEVICEREMOVED != event.type) {
    return false;
  }

  inputProcessor.RemoveGameController(event.cdevice.which);

  return true;
}

NAMESPACE_END(System::EventHandlers::Controller)

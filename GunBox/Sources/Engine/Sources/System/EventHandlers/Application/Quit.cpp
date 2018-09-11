// Self
#include "Quit.hpp"

#include "SDL_events.h"

NAMESPACE_START(System::EventHandlers::Application)

Quit::~Quit()
{
}

bool
Quit::Process(void* event)
{
  if (SDL_QUIT != reinterpret_cast<SDL_Event*>(event)->type)
  {
    return false;
  }

  return true;
}


NAMESPACE_END(System::EventHandlers::Application)

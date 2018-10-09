// Self
#include "Quit.hpp"

#include "SDL_events.h"

NAMESPACE_BEGIN(System::EventHandlers::Application)

Quit::~Quit()
{
}

bool
Quit::Process(SDL_Event const& event)
{
  if (SDL_QUIT != event.type)
  {
    return false;
  }

  return true;
}


NAMESPACE_END(System::EventHandlers::Application)

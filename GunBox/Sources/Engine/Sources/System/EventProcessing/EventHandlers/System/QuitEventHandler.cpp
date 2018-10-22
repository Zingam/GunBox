// Self
#include "QuitEventHandler.hpp"

// Project headers - System
#include "System/EventProcessing/SystemEventProcessorAccessor.hpp"

// Third party
#include "SDL_events.h"

NAMESPACE_BEGIN(System::EventHandlers)

QuitEventHandler::QuitEventHandler(SystemEventProcessor& systemEventProcessor)
  : systemEventProcessor{ systemEventProcessor }
{}

QuitEventHandler::~QuitEventHandler() {}

bool
QuitEventHandler::Process(SDL_Event const& event)
{
  switch (event.type) {
    case SDL_QUIT: {
      SystemEventProcessorAccessor::Quit(systemEventProcessor);
      return true;
    }
    default: {
      return false;
    }
  }
}

NAMESPACE_END(System::EventHandlers)

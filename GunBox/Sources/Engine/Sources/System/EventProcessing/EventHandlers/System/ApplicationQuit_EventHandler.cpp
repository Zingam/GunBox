// Self
#include "ApplicationQuit_EventHandler.hpp"

// Project headers - System
#include "System/EventProcessing/SystemEventProcessorAccessor.hpp"

// Third party
#include "SDL_events.h"

NAMESPACE_BEGIN(System::EventHandlers)

ApplicationQuit_EventHandler::ApplicationQuit_EventHandler(
  System::EventProcessing::SystemEventProcessor& systemEventProcessor)
  : systemEventProcessor{ systemEventProcessor }
{}

ApplicationQuit_EventHandler::~ApplicationQuit_EventHandler() = default;

bool
ApplicationQuit_EventHandler::Process(SDL_Event const& event)
{
  switch (event.type) {
    case SDL_QUIT: {
      System::EventProcessing::SystemEventProcessorAccessor::
        ApplicationQuit(systemEventProcessor);
      return true;
    }
    default: {
      return false;
    }
  }
}

NAMESPACE_END(System::EventHandlers)

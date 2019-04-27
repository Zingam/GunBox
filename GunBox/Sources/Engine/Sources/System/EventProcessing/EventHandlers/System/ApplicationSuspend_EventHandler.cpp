// Self
#include "ApplicationSuspend_EventHandler.hpp"

// Project headers - System
#include "System/EventProcessing/SystemEventProcessorAccessor.hpp"

// Third party
#include "SDL_events.h"

NAMESPACE_BEGIN(System::EventHandlers)

ApplicationSuspend_EventHandler::ApplicationSuspend_EventHandler(
  System::EventProcessing::SystemEventProcessor& systemEventProcessor)
  : systemEventProcessor{ systemEventProcessor }
{}

ApplicationSuspend_EventHandler::~ApplicationSuspend_EventHandler() = default;

bool
ApplicationSuspend_EventHandler::Process(SDL_Event const& event)
{
  switch (event.type) {
    case SDL_APP_WILLENTERBACKGROUND: {
      System::EventProcessing::SystemEventProcessorAccessor::ApplicationSuspend(
        systemEventProcessor);
      return true;
    }
    default: {
      return false;
    }
  }
}

NAMESPACE_END(System::EventHandlers)

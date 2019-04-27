// Self
#include "ApplicationResume_EventHandler.hpp"

// Project headers - System
#include "System/EventProcessing/SystemEventProcessorAccessor.hpp"

// Third party
#include "SDL_events.h"

NAMESPACE_BEGIN(System::EventHandlers)

ApplicationResume_EventHandler::ApplicationResume_EventHandler(
  System::EventProcessing::SystemEventProcessor& systemEventProcessor)
  : systemEventProcessor{ systemEventProcessor }
{}

ApplicationResume_EventHandler::~ApplicationResume_EventHandler() = default;

bool
ApplicationResume_EventHandler::Process(SDL_Event const& event)
{
  switch (event.type) {
    case SDL_APP_WILLENTERFOREGROUND: {
      System::EventProcessing::SystemEventProcessorAccessor::ApplicationResume(
        systemEventProcessor);
      return true;
    }
    default: {
      return false;
    }
  }
}

NAMESPACE_END(System::EventHandlers)

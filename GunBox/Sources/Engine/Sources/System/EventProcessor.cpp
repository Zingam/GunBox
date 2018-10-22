// Self
#include "EventProcessor.hpp"

// Project hedears - System
#include "System/EventProcessing/EventHandlers/EventHandler.hpp"

// Third party headers
#include <SDL_events.h>

#include "System/EventProcessing/EventHandlers/Input/GamepadEventHandler.hpp"
#include "System/EventProcessing/EventHandlers/Input/KeyboardEventHandler.hpp"
#include "System/EventProcessing/EventHandlers/System/QuitEventHandler.hpp"

NAMESPACE_BEGIN(System)

EventProcessor::EventProcessor()
{
  // Initialized in order of occurrence frequency
  InitializeInputEventHandlers();
  InitializeSystemEventHandlers();
}

void
EventProcessor::InitializeInputEventHandlers()
{
  // Initialized in order of occurrence frequency
  RegisterEventHandler<System::EventHandlers::GamepadEventHandler>(
    inputProcessor);
  RegisterEventHandler<System::EventHandlers::KeyboardEventHandler>(
    inputProcessor);
}

void
EventProcessor::InitializeSystemEventHandlers()
{
  // Initialized in order of occurrence frequency
  RegisterEventHandler<System::EventHandlers::QuitEventHandler>(
    systemEventProcessor);
}

void
EventProcessor::ProcessEvents() const
{
  SDL_Event event;
  // Handle events on queue
  while (SDL_PollEvent(&event) != 0) {
    {
      for (auto& eventHandler : eventHandlers) {
        auto isProcessed = eventHandler->Process(event);
        if (isProcessed) {
          break;
        }
      }
    }
  };
}

NAMESPACE_END(System)

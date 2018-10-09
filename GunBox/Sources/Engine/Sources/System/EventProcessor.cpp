// Self
#include "EventProcessor.hpp"

// Project hedears - System
#include "System/EventHandlers/EventHandler.hpp"

// Third party headers
#include <SDL_events.h>

NAMESPACE_BEGIN(System)

void
EventProcessor::ProcessEvents()
{
  SDL_Event event;
  // Handle events on queue
  while (SDL_PollEvent(&event) != 0) {
    {
      for (auto& eventHandler : eventHandlers) {
        auto isProcessed =
          eventHandler->Process(event);
        if (isProcessed) {
          break;
        }
      }
    }
  };
}

NAMESPACE_END(System)

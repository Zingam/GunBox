// Self
#include "EventProcessor.hpp"

// Project hedears - System
#include "System/EventProcessing/EventHandlers/EventHandler.hpp"
#include "System/EventProcessing/EventHandlers/Input/GamepadEventHandler.hpp"
#include "System/EventProcessing/EventHandlers/Input/KeyboardEventHandler.hpp"
#include "System/EventProcessing/EventHandlers/System/ApplicationResume_EventHandler.hpp"
#include "System/EventProcessing/EventHandlers/System/ApplicationSuspend_EventHandler.hpp"
#include "System/EventProcessing/EventHandlers/System/ApplicationQuit_EventHandler.hpp"

// Third party headers
#include <SDL_events.h>

NAMESPACE_BEGIN(System)

////////////////////////////////////////////////////////////////////////////////
// Constructors & Destructors
////////////////////////////////////////////////////////////////////////////////

EventProcessor::EventProcessor()
{
  // Initialized in order of occurrence frequency
  InitializeInputEventHandlers();
  InitializeSystemEventHandlers();
}

////////////////////////////////////////////////////////////////////////////////
// Methods
////////////////////////////////////////////////////////////////////////////////

void
EventProcessor::InitializeCallbacks(
  System::EventProcessing::InputEventCallbacks_Interface& inputEventCallbacks)
{
  InputEventProcessor().InitializeCallbacks(inputEventCallbacks);
}

void
EventProcessor::InitializeCallbacks(
  System::EventProcessing::SystemEventCallbacks_Interface& systemEventCallbacks)
{
  SystemEventProcessor().InitializeCallbacks(systemEventCallbacks);
}

void
EventProcessor::InitializeInputEventHandlers()
{
  // Initialized in order of occurrence frequency
  RegisterEventHandler<System::EventHandlers::GamepadEventHandler>(
    inputEventProcessor);
  RegisterEventHandler<System::EventHandlers::KeyboardEventHandler>(
    inputEventProcessor);
}

void
EventProcessor::InitializeSystemEventHandlers()
{
  // Initialized in order of occurrence frequency
  RegisterEventHandler<System::EventHandlers::ApplicationResume_EventHandler>(
    systemEventProcessor);
  RegisterEventHandler<System::EventHandlers::ApplicationSuspend_EventHandler>(
    systemEventProcessor);
  RegisterEventHandler<System::EventHandlers::ApplicationQuit_EventHandler>(
    systemEventProcessor);
}

void
EventProcessor::ProcessEvents()
{
  // Handle events on queue
  SDL_Event event;
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

  // After all events have been processed, update the input device states
  inputEventProcessor.ProcessInputDeviceStates();
}

NAMESPACE_END(System)

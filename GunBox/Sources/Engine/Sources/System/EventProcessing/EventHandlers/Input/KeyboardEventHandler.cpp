// Self
#include "KeyboardEventHandler.hpp"

// Project headers - System
#include "System/DeviceTypes/IO/KeyboardTypes.hpp"
#include "System/EventProcessing/InputEventProcessorAccessor.hpp"
#include "System/Platforms/SDL2/Keyboard_SDL2.hpp"

// Third party
#include <SDL_events.h>

NAMESPACE_BEGIN(System::EventHandlers)

KeyboardEventHandler::KeyboardEventHandler(
  System::EventProcessing::InputEventProcessor& inputProcessor)
  : inputProcessor{ inputProcessor }
{}

KeyboardEventHandler::~KeyboardEventHandler() {}

bool
KeyboardEventHandler::Process(SDL_Event const& event)
{
  // Events are ordered in the most likely frequency occurence
  switch (event.type) {
    case SDL_KEYDOWN: {
      auto key = System::Platforms::Keyboard::ConvertToKey(event.key);
      System::EventProcessing::InputEventProcessorAccessor::KeyboardKeyDown(
        inputProcessor, key);
      return true;
    }
    case SDL_KEYUP: {
      auto key = System::Platforms::Keyboard::ConvertToKey(event.key);
      System::EventProcessing::InputEventProcessorAccessor::KeyboardKeyDown(
        inputProcessor, key);
      return true;
    }
    default: {
      return false;
    }
  }
}

NAMESPACE_END(System::EventHandlers)

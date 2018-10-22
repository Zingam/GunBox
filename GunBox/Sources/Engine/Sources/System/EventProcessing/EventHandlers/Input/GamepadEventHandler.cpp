// Self
#include "GamepadEventHandler.hpp"

// Project headers - System
#include "System/DeviceTypes/IO/GamepadTypes.hpp"
#include "System/EventProcessing/InputEventProcessorAccessor.hpp"
#include "System/Platforms/SDL2/Gamepad_SDL2.hpp"

// Third party
#include <SDL_events.h>
#include <SDL_gamecontroller.h>

NAMESPACE_BEGIN(System::EventHandlers)

GamepadEventHandler::GamepadEventHandler(
  System::EventProcessing::InputEventProcessor& inputProcessor)
  : inputProcessor{ inputProcessor }
{}

GamepadEventHandler::~GamepadEventHandler() {}

bool
GamepadEventHandler::Process(SDL_Event const& event)
{
  using namespace System::DeviceTypes::IO;

  // Remap the SDL2 values to Engine values
  auto id = static_cast<GamepadId_t>(event.caxis.which);

  // Events are ordered in the most likely frequency occurence
  switch (event.type) {
    case SDL_CONTROLLERAXISMOTION: {
      // Remap the SDL2 values to Engine values
      auto axis = GamepadAxis_t::StickLeftX;
      switch (event.caxis.axis) {
        case SDL_CONTROLLER_AXIS_LEFTX: {
          axis = GamepadAxis_t::StickLeftX;
          break;
        }
        case SDL_CONTROLLER_AXIS_LEFTY: {
          axis = GamepadAxis_t::StickLeftY;
          break;
        }
        case SDL_CONTROLLER_AXIS_RIGHTX: {
          axis = GamepadAxis_t::StickRightX;
          break;
        }
        case SDL_CONTROLLER_AXIS_RIGHTY: {
          axis = GamepadAxis_t::StickRightY;
          break;
        }
        case SDL_CONTROLLER_AXIS_TRIGGERLEFT: {
          axis = GamepadAxis_t::TriggerLeft;
          break;
        }
        case SDL_CONTROLLER_AXIS_TRIGGERRIGHT: {
          axis = GamepadAxis_t::TriggerRight;
          break;
        }
      }
      // Normalize the axis value
      auto value = static_cast<float>(event.caxis.value / 32767);

      System::EventProcessing::InputEventProcessorAccessor::GamepadAxisMotion(
        inputProcessor, id, axis, value);
      return true;
    }
    case SDL_CONTROLLERBUTTONDOWN: {
      auto button =
        System::Platforms::Gamepad::ConvertGamepadButton(event.cbutton);
      System::EventProcessing::InputEventProcessorAccessor::GamepadButtonDown(
        inputProcessor, id, button);
      return true;
    }
    case SDL_CONTROLLERBUTTONUP: {
      auto button =
        System::Platforms::Gamepad::ConvertGamepadButton(event.cbutton);
      System::EventProcessing::InputEventProcessorAccessor::GamepadButtonUp(
        inputProcessor, id, button);
      return true;
    }
    case SDL_CONTROLLERDEVICEADDED: {
      System::EventProcessing::InputEventProcessorAccessor::GamepadDeviceAdd(
        inputProcessor, id);
      return true;
    }
    case SDL_CONTROLLERDEVICEREMOVED: {
      System::EventProcessing::InputEventProcessorAccessor::GamepadDeviceRemove(
        inputProcessor, id);
      return true;
    }
    default: {
      return false;
    }
  }
}

NAMESPACE_END(System::EventHandlers)

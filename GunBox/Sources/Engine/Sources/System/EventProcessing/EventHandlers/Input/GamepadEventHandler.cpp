// Self
#include "GamepadEventHandler.hpp"

// Project headers - System
#include "System/DeviceTypes/IO/GamepadTypes.hpp"
#include "System/EventProcessing/InputEventProcessorAccessor.hpp"
#include "System/Platforms/SDL2/Gamepad_SDL2.hpp"

// Third party
#include <SDL_events.h>
#include <SDL_gamecontroller.h>

// C Standard Library
#include <cmath>
#include <iostream>

NAMESPACE_BEGIN(System::EventHandlers)

GamepadEventHandler::GamepadEventHandler(
  System::EventProcessing::InputEventProcessor& inputProcessor)
  : inputProcessor{ inputProcessor }
{}

GamepadEventHandler::~GamepadEventHandler() {}

bool
GamepadEventHandler::Process(SDL_Event const& event)
{
  // Remap the SDL2 values to Engine values
  using namespace System::DeviceTypes::IO;
 
  // Events are ordered in the most likely frequency occurence
  switch (event.type) {
    case SDL_CONTROLLERAXISMOTION: {
      auto value = static_cast<double>(event.caxis.value / 32767.0);
      // Handle deadzone
      constexpr auto deadZone = 3276 / 32767.0;
      if (deadZone > std::abs(value)) {
        return true;
      }
      // Remap the SDL2 values to Engine values
      // Normalize the axis value
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

      auto id = static_cast<GamepadId_t>(event.caxis.which);
      System::EventProcessing::InputEventProcessorAccessor::GamepadAxisMotion(
        inputProcessor, id, axis, value);
      return true;
    }
    case SDL_CONTROLLERBUTTONDOWN: {
      auto id = event.cbutton.which;
      auto button =
        System::Platforms::Gamepad::ConvertGamepadButton(event.cbutton);
      System::EventProcessing::InputEventProcessorAccessor::GamepadButtonDown(
        inputProcessor, id, button);
      return true;
    }
    case SDL_CONTROLLERBUTTONUP: {
      auto id = event.cbutton.which;
      auto button =
        System::Platforms::Gamepad::ConvertGamepadButton(event.cbutton);
      System::EventProcessing::InputEventProcessorAccessor::GamepadButtonUp(
        inputProcessor, id, button);
      return true;
    }
    case SDL_CONTROLLERDEVICEADDED: {
      auto id = event.cdevice.which;
      System::EventProcessing::InputEventProcessorAccessor::GamepadDeviceAdd(
        inputProcessor, id);
      return true;
    }
    case SDL_CONTROLLERDEVICEREMOVED: {
      auto id = event.cdevice.which;
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

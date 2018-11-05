// Self
#include "InputEventProcessor.hpp"

// BASE MACROS header
#include "Common/Macros/Logging.hpp"

// Third party
#include <SDL_gamecontroller.h>

// C Standard Library
#include <cassert>

NAMESPACE_BEGIN(System::EventProcessing)

InputEventProcessor ::~InputEventProcessor() {}

auto
InputEventProcessor::InitializeCallbacks(
  std::shared_ptr<InputEventCallbacks_Interface> const inputCallbacks) -> void
{
  InitializeCallbacks(*inputCallbacks);
}

auto
InputEventProcessor::InitializeCallbacks(
  InputEventCallbacks_Interface& inputCallbacks) -> void
{
  cbGamepadAxisMotion_UPtr = make_unique_delegate(
    inputCallbacks, &InputEventCallbacks_Interface::GamepadAxisMotion);
  cbGamepadDeviceAdd_UPtr = make_unique_delegate(
    inputCallbacks, &InputEventCallbacks_Interface::GamepadDeviceAdd);
  cbGamepadDeviceRemove_UPtr = make_unique_delegate(
    inputCallbacks, &InputEventCallbacks_Interface::GamepadDeviceRemove);
  cbGamepadButtonDown_UPtr = make_unique_delegate(
    inputCallbacks, &InputEventCallbacks_Interface::GamepadButtonDown);
  cbGamepadButtonUp_UPtr = make_unique_delegate(
    inputCallbacks, &InputEventCallbacks_Interface::GamepadButtonUp);
  cbKeyboardKeyDown_UPtr = make_unique_delegate(
    inputCallbacks, &InputEventCallbacks_Interface::KeyboardKeyDown);
  cbKeyboardKeyUp_UPtr = make_unique_delegate(
    inputCallbacks, &InputEventCallbacks_Interface::KeyboardKeyUp);
}

void
InputEventProcessor::AddGamepad(
  System::DeviceTypes::IO::GamepadId_t const deviceIndex)
{
  // The 'cdevice.which' when a device is added is an index to be used with
  // SDL_GameControllerOpen. Subsequent events return an instance ID.
  auto gameController = SDL_GameControllerOpen(deviceIndex);
  if (gameController == nullptr) {
    LogError("Unable to open gamepad: %s", SDL_GetError());
  } else {
    // Get the instance ID of this controller.
    auto gamepadId =
      SDL_JoystickInstanceID(SDL_GameControllerGetJoystick(gameController));
    gamepads[gamepadId] = gameController;
  }
}

void
InputEventProcessor::RemoveGamepad(
  System::DeviceTypes::IO::GamepadId_t const gamepadId)
{
  auto gameController = gamepads.find(gamepadId);
  assert(
    gameController != gamepads.cend() &&
    "Controller instance ID was not found");
  if (gameController != gamepads.cend()) {
    SDL_GameControllerClose(gameController->second);
    gamepads.erase(gameController);
  }
}

NAMESPACE_END(System::EventProcessing)

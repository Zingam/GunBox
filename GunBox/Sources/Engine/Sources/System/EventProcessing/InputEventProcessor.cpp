// Self
#include "InputEventProcessor.hpp"

// BASE MACROS header
#include "Common/Macros/Logging.hpp"

// Project headers - System
#include "System/EventProcessing/InputDeviceStates/GamepadStateAccessor.hpp"
#include "System/EventProcessing/InputDeviceStates/KeyboardStateAccessor.hpp"
#include "System/Platforms/SDL2/Gamepad_SDL2.hpp"
#include "System/Platforms/SDL2/Keyboard_SDL2.hpp"

// Third party
#include <SDL_gamecontroller.h>
#include <SDL_keyboard.h>

// C Standard Library
#include <algorithm>
#include <cassert>

NAMESPACE_BEGIN(System::EventProcessing)

////////////////////////////////////////////////////////////////////////////////
// Properties
////////////////////////////////////////////////////////////////////////////////

std::vector<System::DeviceTypes::Input::GamepadId_t> const&
InputEventProcessor::GamepadIds() const
{
  return gamepadIds;
}

////////////////////////////////////////////////////////////////////////////////
// Public methods
////////////////////////////////////////////////////////////////////////////////

void
InputEventProcessor::InitializeCallbacks(
  std::shared_ptr<InputEventCallbacks_Interface> const inputCallbacks)
{
  InitializeCallbacks(*inputCallbacks);
}

void
InputEventProcessor::InitializeCallbacks(
  InputEventCallbacks_Interface& inputCallbacks)
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
InputEventProcessor::ProcessInputDeviceStates()
{
  ProcessKeyboardDeviceStates();
  ProcessGamepadDeviceStates();
}

////////////////////////////////////////////////////////////////////////////////
// Private methods
////////////////////////////////////////////////////////////////////////////////

void
InputEventProcessor::Gamepad_Add(
  System::DeviceTypes::Input::GamepadId_t const deviceIndex)
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
    gamepads[gamepadId] = { gameController, {} };

    RecreateGamepadIds();
  }
}

void
InputEventProcessor::Gamepad_Remove(
  System::DeviceTypes::Input::GamepadId_t const gamepadId)
{
  auto gamepad = gamepads.find(gamepadId);

  assert(gamepad != gamepads.cend() && "Controller instance ID was not found");

  if (gamepad != gamepads.cend()) {
    auto gamepad_Ptr = static_cast<SDL_GameController*>(gamepad->second.first);
    SDL_GameControllerClose(gamepad_Ptr);
    gamepads.erase(gamepad);

    RecreateGamepadIds();
  }
}

auto
InputEventProcessor::ProcessKeyboardDeviceStates() -> void
{
  // Process keyboard state
  auto keyCount = 0;
  auto const keyStates = SDL_GetKeyboardState(&keyCount);
  for (auto scanCodeIndex = 0; scanCodeIndex < keyCount; ++scanCodeIndex) {
    using namespace System::Platforms::Keyboard;
    auto scanCode = ConvertScanCode(static_cast<SDL_Scancode>(scanCodeIndex));
    // Value of 1 is a key pressed state, 0 for a key not pressed state
    auto keyState = (1 == keyStates[scanCodeIndex])
                      ? KeyboardState::KeyState_t::Pressed
                      : KeyboardState::KeyState_t::Released;
    KeyboardStateAccessor::SetKeyboardState(keyboardState, scanCode, keyState);
  }
}

auto
InputEventProcessor::ProcessGamepadDeviceStates() -> void
{
  // Process gamepad state
  for (auto& gamepad : gamepads) {
    auto gamepad_Ptr = static_cast<SDL_GameController*>(gamepad.second.first);
    auto& gamepadState_Ref = gamepad.second.second;

    auto Gamepad_GetAxisValue = [](
                                  GamepadState& gamepadState,
                                  SDL_GameController* gamepad,
                                  SDL_GameControllerAxis axis) {
      // The state is a value ranging from -32768 to 32767. Triggers, however,
      // range from 0 to 32767 (they never return a negative value). Use
      // SDL_GetError() to get more information in case of an error.
      auto axisValue = SDL_GameControllerGetAxis(gamepad, axis);
      auto currentAxis = System::Platforms::Gamepad::ConvertGamepadAxis(axis);
      GamepadStateAccessor::SetAxisState(gamepadState, currentAxis, axisValue);
    };

    Gamepad_GetAxisValue(
      gamepadState_Ref, gamepad_Ptr, SDL_CONTROLLER_AXIS_LEFTX);
    Gamepad_GetAxisValue(
      gamepadState_Ref, gamepad_Ptr, SDL_CONTROLLER_AXIS_LEFTY);
    Gamepad_GetAxisValue(
      gamepadState_Ref, gamepad_Ptr, SDL_CONTROLLER_AXIS_RIGHTX);
    Gamepad_GetAxisValue(
      gamepadState_Ref, gamepad_Ptr, SDL_CONTROLLER_AXIS_RIGHTY);
    Gamepad_GetAxisValue(
      gamepadState_Ref, gamepad_Ptr, SDL_CONTROLLER_AXIS_TRIGGERLEFT);
    Gamepad_GetAxisValue(
      gamepadState_Ref, gamepad_Ptr, SDL_CONTROLLER_AXIS_TRIGGERRIGHT);

    auto Gamepad_GetButtonState = [](
                                    GamepadState& gamepadState,
                                    SDL_GameController* gamepad,
                                    SDL_GameControllerButton button) {
      auto gamepadButton =
        System::Platforms::Gamepad::ConvertGamepadButton(button);
      // Value of 1 is a button pressed state, 0 for a button not pressed state,
      // otherwise there is an error. Use SDL_GetError() to get more information
      // in case of an error.
      auto buttonState = (1 == SDL_GameControllerGetButton(gamepad, button))
                           ? GamepadState::ButtonState_t::Pressed
                           : GamepadState::ButtonState_t::Released;
      GamepadStateAccessor::SetButtonState(
        gamepadState, gamepadButton, buttonState);
    };

    Gamepad_GetButtonState(
      gamepadState_Ref, gamepad_Ptr, SDL_CONTROLLER_BUTTON_A);
    Gamepad_GetButtonState(
      gamepadState_Ref, gamepad_Ptr, SDL_CONTROLLER_BUTTON_B);
    Gamepad_GetButtonState(
      gamepadState_Ref, gamepad_Ptr, SDL_CONTROLLER_BUTTON_X);
    Gamepad_GetButtonState(
      gamepadState_Ref, gamepad_Ptr, SDL_CONTROLLER_BUTTON_Y);
    Gamepad_GetButtonState(
      gamepadState_Ref, gamepad_Ptr, SDL_CONTROLLER_BUTTON_BACK);
    Gamepad_GetButtonState(
      gamepadState_Ref, gamepad_Ptr, SDL_CONTROLLER_BUTTON_GUIDE);
    Gamepad_GetButtonState(
      gamepadState_Ref, gamepad_Ptr, SDL_CONTROLLER_BUTTON_START);
    Gamepad_GetButtonState(
      gamepadState_Ref, gamepad_Ptr, SDL_CONTROLLER_BUTTON_LEFTSTICK);
    Gamepad_GetButtonState(
      gamepadState_Ref, gamepad_Ptr, SDL_CONTROLLER_BUTTON_RIGHTSTICK);
    Gamepad_GetButtonState(
      gamepadState_Ref, gamepad_Ptr, SDL_CONTROLLER_BUTTON_LEFTSHOULDER);
    Gamepad_GetButtonState(
      gamepadState_Ref, gamepad_Ptr, SDL_CONTROLLER_BUTTON_RIGHTSHOULDER);
    Gamepad_GetButtonState(
      gamepadState_Ref, gamepad_Ptr, SDL_CONTROLLER_BUTTON_DPAD_UP);
    Gamepad_GetButtonState(
      gamepadState_Ref, gamepad_Ptr, SDL_CONTROLLER_BUTTON_DPAD_DOWN);
    Gamepad_GetButtonState(
      gamepadState_Ref, gamepad_Ptr, SDL_CONTROLLER_BUTTON_DPAD_LEFT);
    Gamepad_GetButtonState(
      gamepadState_Ref, gamepad_Ptr, SDL_CONTROLLER_BUTTON_DPAD_RIGHT);
  }
}

auto
InputEventProcessor::RecreateGamepadIds() -> void
{
  // Recreate the gamepadIds vector
  gamepadIds.clear();
  for (auto& gamepad : gamepads) {
    using System::DeviceTypes::Input::GamepadId_t;
    auto gamepadId = static_cast<GamepadId_t>(gamepad.first);
    gamepadIds.push_back(gamepadId);
  }
}

NAMESPACE_END(System::EventProcessing)

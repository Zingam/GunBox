// Self
#include "InputProcessor.hpp"

// Project headers - Base
#include "Common/Macros/Logging.hpp"

// Third party
#include <SDL_gamecontroller.h>

NAMESPACE_BEGIN(System)

InputProcessor ::~InputProcessor()
{
  for (auto& gameController : gamepads) {
    SDL_GameControllerClose(gameController.second);
  }
}

auto
InputProcessor::SetInputCallbacksObject(
  std::shared_ptr<InputCallbacks> const inputCallbacks) -> void
{
  SetInputCallbacksObject(*inputCallbacks);
}

auto
InputProcessor::SetInputCallbacksObject(InputCallbacks& inputCallbacks) -> void
{
  cbGamepadAxisMotion_UPtr =
    make_unique_delegate(inputCallbacks, &InputCallbacks::GamepadAxisMotion);
  cbGamepadDeviceAdd_UPtr =
    make_unique_delegate(inputCallbacks, &InputCallbacks::GamepadDeviceAdd);
  cbGamepadDeviceRemove_UPtr =
    make_unique_delegate(inputCallbacks, &InputCallbacks::GamepadDeviceRemove);
  cbGamepadButtonDown_UPtr =
    make_unique_delegate(inputCallbacks, &InputCallbacks::GamepadButtonDown);
  cbGamepadButtonUp_UPtr =
    make_unique_delegate(inputCallbacks, &InputCallbacks::GamepadButtonUp);
  cbKeyboardKeyDown_UPtr =
    make_unique_delegate(inputCallbacks, &InputCallbacks::KeyboardKeyDown);
  cbKeyboardKeyUp_UPtr =
    make_unique_delegate(inputCallbacks, &InputCallbacks::KeyboardKeyUp);
}

void
InputProcessor::AddGamepad(System::DeviceTypes::IO::GamepadId_t const gamepadId)
{
  auto gameController = SDL_GameControllerOpen(gamepadId);
  if (gameController == nullptr) {
    LogError("Unable to open gamepad: %s", SDL_GetError());
  } else {
    gamepads[gamepadId] = gameController;
  }
}

void
InputProcessor::RemoveGamepad(
  System::DeviceTypes::IO::GamepadId_t const gameControllerId)
{
  auto gameController = gamepads.find(gameControllerId);
  SDL_GameControllerClose(gameController->second);
  gamepads.erase(gameController);
}

NAMESPACE_END(System)

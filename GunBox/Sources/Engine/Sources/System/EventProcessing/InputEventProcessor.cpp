// Self
#include "InputEventProcessor.hpp"

// BASE MACROS header
#include "Common/Macros/Logging.hpp"

// Third party
#include <SDL_gamecontroller.h>

NAMESPACE_BEGIN(System::EventProcessing)

InputEventProcessor ::~InputEventProcessor()
{
  for (auto& gameController : gamepads) {
    SDL_GameControllerClose(gameController.second);
  }
}

auto
InputEventProcessor::InitializeCallbacks(
  std::shared_ptr<InputEventCallbacks> const inputCallbacks) -> void
{
  InitializeCallbacks(*inputCallbacks);
}

auto
InputEventProcessor::InitializeCallbacks(InputEventCallbacks& inputCallbacks) -> void
{
  cbGamepadAxisMotion_UPtr =
    make_unique_delegate(inputCallbacks, &InputEventCallbacks::GamepadAxisMotion);
  cbGamepadDeviceAdd_UPtr =
    make_unique_delegate(inputCallbacks, &InputEventCallbacks::GamepadDeviceAdd);
  cbGamepadDeviceRemove_UPtr =
    make_unique_delegate(inputCallbacks, &InputEventCallbacks::GamepadDeviceRemove);
  cbGamepadButtonDown_UPtr =
    make_unique_delegate(inputCallbacks, &InputEventCallbacks::GamepadButtonDown);
  cbGamepadButtonUp_UPtr =
    make_unique_delegate(inputCallbacks, &InputEventCallbacks::GamepadButtonUp);
  cbKeyboardKeyDown_UPtr =
    make_unique_delegate(inputCallbacks, &InputEventCallbacks::KeyboardKeyDown);
  cbKeyboardKeyUp_UPtr =
    make_unique_delegate(inputCallbacks, &InputEventCallbacks::KeyboardKeyUp);
}

void
InputEventProcessor::AddGamepad(System::DeviceTypes::IO::GamepadId_t const gamepadId)
{
  auto gameController = SDL_GameControllerOpen(gamepadId);
  if (gameController == nullptr) {
    LogError("Unable to open gamepad: %s", SDL_GetError());
  } else {
    gamepads[gamepadId] = gameController;
  }
}

void
InputEventProcessor::RemoveGamepad(
  System::DeviceTypes::IO::GamepadId_t const gameControllerId)
{
  auto gameController = gamepads.find(gameControllerId);
  SDL_GameControllerClose(gameController->second);
  gamepads.erase(gameController);
}

NAMESPACE_END(System::EventProcessing)

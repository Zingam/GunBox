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
  std::shared_ptr<InputEventCallbacks_Interface> const inputCallbacks) -> void
{
  InitializeCallbacks(*inputCallbacks);
}

auto
InputEventProcessor::InitializeCallbacks(InputEventCallbacks_Interface& inputCallbacks) -> void
{
  cbGamepadAxisMotion_UPtr =
    make_unique_delegate(inputCallbacks, &InputEventCallbacks_Interface::GamepadAxisMotion);
  cbGamepadDeviceAdd_UPtr =
    make_unique_delegate(inputCallbacks, &InputEventCallbacks_Interface::GamepadDeviceAdd);
  cbGamepadDeviceRemove_UPtr =
    make_unique_delegate(inputCallbacks, &InputEventCallbacks_Interface::GamepadDeviceRemove);
  cbGamepadButtonDown_UPtr =
    make_unique_delegate(inputCallbacks, &InputEventCallbacks_Interface::GamepadButtonDown);
  cbGamepadButtonUp_UPtr =
    make_unique_delegate(inputCallbacks, &InputEventCallbacks_Interface::GamepadButtonUp);
  cbKeyboardKeyDown_UPtr =
    make_unique_delegate(inputCallbacks, &InputEventCallbacks_Interface::KeyboardKeyDown);
  cbKeyboardKeyUp_UPtr =
    make_unique_delegate(inputCallbacks, &InputEventCallbacks_Interface::KeyboardKeyUp);
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

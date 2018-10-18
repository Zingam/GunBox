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

void
InputProcessor::AddGamepad(GamepadId const gamepadId)
{
  auto gameController = SDL_GameControllerOpen(gamepadId);
  if (gameController == nullptr) {
    LogError("Unable to open gamepad: %s", SDL_GetError());
  } else {
    gamepads[gamepadId] = gameController;
  }
}

void
InputProcessor::RemoveGamepad(GamepadId const gameControllerId)
{
  auto gameController = gamepads.find(gameControllerId);
  SDL_GameControllerClose(gameController->second);
  gamepads.erase(gameController);
}

NAMESPACE_END(System)

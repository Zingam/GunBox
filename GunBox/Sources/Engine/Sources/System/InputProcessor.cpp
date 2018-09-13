// Self
#include "InputProcessor.hpp"

// Project headers - Common
#include "Common/Macros/SDL2_ErrorChecking.hpp"

// Third party
#include <SDL_gamecontroller.h>

NAMESPACE_START(System)

InputProcessor ::~InputProcessor()
{
  for (auto& gameController : gameControllers)
  {
    SDL_GameControllerClose(gameController.second);
  }
}

void
InputProcessor::AddGameController(GameControllerId const gameControllerId)
{
  auto gameController = SDL_GameControllerOpen(gameControllerId);
  if (gameController == nullptr) {
    SDL_LogError("Unable to open game controller");
  } else {
    gameControllers[gameControllerId] = gameController;
  }
}

void
InputProcessor::RemoveGameController(GameControllerId const gameControllerId)
{
  auto gameController = gameControllers.find(gameControllerId);
  SDL_GameControllerClose(gameController->second);
  gameControllers.erase(gameController);
}

NAMESPACE_END(System)

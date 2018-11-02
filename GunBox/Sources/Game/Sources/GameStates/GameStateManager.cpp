// Self
#include "GameStateManager.hpp"

#include "EventHandling/Commands/MainMenu_Commander.hpp"

// C Standard Library
#include <cassert>

NAMESPACE_BEGIN(GunBox)

InputEventCallbacks&
GameStateManager::GetInputEventCallbacks()
{
  return inputEventCallbacks;
}

SystemEventCallbacks&
GameStateManager::GetSystemEventCallbacks()
{
  return systemEventCallbacks;
}

auto
GameStateManager::Initialize(
  std::shared_ptr<Renderer::Graphics::GraphicsRenderer_Interface>
    graphicsRenderer) -> void
{
  this->graphicsRenderer = graphicsRenderer;
}

bool
GameStateManager::Run()
{
  assert(
    (nullptr != graphicsRenderer) &&
    "The graphics renderer is not initialized");

  if (GameState_t::InGame == gameState) {
    return true;
  } else {
    switch (gameState) {
      case GameState_t::MainMenu: {
        if (!isStateInitialized) {
          inputEventCallbacks.SetCommander<MainMenu_Commander>(mainMenu);
          isStateInitialized = true;
        }
        gameState = mainMenu.Update();
        return true;
      }
      default: {
        switch (gameState) {
          case GameState_t::Quit: {
            [[fallthrough]];
          }
          default: {
            return false;
          }
        }
      }
    }
  }
}

NAMESPACE_END(GunBox)

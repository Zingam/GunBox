// Self
#include "GameStateManager.hpp"

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

  switch (gameState) {
    case GameState_t::InGame: {
      return true;
    }
    case GameState_t::MainMenu: {
      gameState = mainMenu.Update();
      return true;
    }
    case GameState_t::Quit: {
      [[fallthrough]];
    }
    default: {
      return false;
    }
  }
}

NAMESPACE_END(GunBox)

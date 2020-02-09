// Self
#include "GameStateManager.hpp"

// Project headers
#include "EventHandling/Commands/Commander_MainMenu.hpp"
#include "EventHandling/Commands/Commander_Null.hpp"

// C Standard Library
#include <cassert>

NAMESPACE_BEGIN(GunBox)

////////////////////////////////////////////////////////////////////////////////
// Constructors & Destructors
////////////////////////////////////////////////////////////////////////////////

GameStateManager::GameStateManager(
  System::EventProcessing::InputEventProcessor const& inputEventProcessor)
  : inGame{ inputEventProcessor }
  , mainMenu{ inputEventProcessor }
{}

////////////////////////////////////////////////////////////////////////////////
// Public Methods
////////////////////////////////////////////////////////////////////////////////

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

void
GameStateManager::Initialize(
  std::shared_ptr<Renderer::Graphics::GraphicsRenderer_Interface>
    graphicsRenderer)
{
  this->graphicsRenderer = graphicsRenderer;
  inputEventCallbacks.SetCommander<Commander_Null>();
  systemEventCallbacks.SetCommander<Commander_Null>();
}

bool
GameStateManager::Run()
{
  assert(
    (nullptr != graphicsRenderer) &&
    "The graphics renderer is not initialized");

  if (GameState_t::InGame == gameState) {
    if (!isStateInitialized) {
      isStateInitialized = true;
      inGame.Initialize(graphicsRenderer);
    }
    gameState = inGame.Update();
    if (GameState_t::InGame != gameState) {
      isStateInitialized = false;
    }
    return true;
  } else {
    switch (gameState) {
      case GameState_t::MainMenu: {
        if (!isStateInitialized) {
          isStateInitialized = true;
          mainMenu.Initialize(graphicsRenderer);
          inputEventCallbacks.SetCommander<Commander_MainMenu>(mainMenu);
          systemEventCallbacks.SetCommander<Commander_MainMenu>(mainMenu);
        }
        gameState = mainMenu.Update();
        if (GameState_t::MainMenu != gameState) {
          isStateInitialized = false;
          inputEventCallbacks.SetCommander<Commander_Null>();
          systemEventCallbacks.SetCommander<Commander_Null>();
        }
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

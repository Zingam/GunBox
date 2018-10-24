// Self
#include "Game.hpp"

// Project headers
#include "EventHandling/InputEventCallbacks.hpp"
#include "EventHandling/SystemEventCallbacks.hpp"
#include "GameStates/GameStateManager.hpp"

// C Standard Library
#include <cassert>
// C++ Standard Library
#include <iostream>
#include <memory>

NAMESPACE_BEGIN(GunBox)

////////////////////////////////////////////////////////////////////////////////
// Constructors & Destructors
////////////////////////////////////////////////////////////////////////////////

Game::Game(Application::ApplicationInfo info)
  : Application::CoreApplication{ info }
{}

Game::~Game() {}

////////////////////////////////////////////////////////////////////////////////
// Virtual methods
////////////////////////////////////////////////////////////////////////////////

Application::ExitCode
Game::Execute()
{
  assert(
    (nullptr != graphicsRenderer) &&
    "The Graphics Renderer was not properly created");

  std::cout << Info().Title() << ": Staring a new game...\n";
  graphicsRenderer->Initialize();
  // clang-format off
  GameStateManager gameStateManager;
  gameStateManager.Initialize(graphicsRenderer);
  eventProcessor.InitializeCallbacks(
    gameStateManager.GetInputEventCallbacks());
  eventProcessor.InitializeCallbacks(
    gameStateManager.GetSystemEventCallbacks());
  // clang-format on

  std::cout << Info().Title() << ": Running the game...\n";

  bool isRunning = true;
  do {
    isRunning = gameStateManager.Run();
    eventProcessor.ProcessEvents();
  } while (isRunning);

  std::cout << Info().Title() << ": Exiting the game...\n";
  graphicsRenderer->Finalize();

  return Application::ExitCode::NoError;
}

NAMESPACE_END(GunBox)

// Self
#include "Game.hpp"

// Project headers
#include "EventHandling/InputEventCallbacks.hpp"
#include "EventHandling/SystemEventCallbacks.hpp"
#include "GameStates/GameStateManager.hpp"

// Engine headers - Logger
#include <Logger/LogAPI.hpp>

// C Standard Library
#include <cassert>

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
  auto gameStateManager = MainLoop_Initialize();
  MainLoop_Execute(std::move(gameStateManager));
  MainLoop_Finalize();

  return Application::ExitCode::NoError;
}

void
Game::MainLoop_Execute(std::unique_ptr<GameStateManager> gameStateManager)
{
  reLog(Info().Title(), ": Running the game...");

  std::chrono::time_point lastExecutionTime =
    std::chrono::high_resolution_clock::now();
  auto const executionPeriod =
    std::chrono::duration_cast<std::chrono::nanoseconds>(executionPeriod_60Hz);
  bool isRunning = true;

  // Main loop
  do {
    auto currentTime = std::chrono::high_resolution_clock::now();
    auto duration = currentTime - lastExecutionTime;
    if (executionPeriod <= duration) {
      lastExecutionTime = currentTime;
      // Process system events and device input
      eventProcessor.ProcessEvents();
      // Update the game state
      isRunning = gameStateManager->Run();
    }
  } while (isRunning);
}

void
Game::MainLoop_Finalize()
{
  reLog(Info().Title(), ": Exiting the game...");

  graphicsRenderer->Finalize();
}

std::unique_ptr<GameStateManager>
Game::MainLoop_Initialize()
{
  reLog(Info().Title(), ": Staring a new game...");

  assert(
    (nullptr != graphicsRenderer) &&
    "The Graphics Renderer was not properly created");

  graphicsRenderer->Initialize();

  auto gameStateManager =
    std::make_unique<GameStateManager>(eventProcessor.InputEventProcessor());
  gameStateManager->Initialize(graphicsRenderer);

  // clang-format off
  eventProcessor.InitializeCallbacks(
    gameStateManager->GetInputEventCallbacks());
  eventProcessor.InitializeCallbacks(
    gameStateManager->GetSystemEventCallbacks());
  // clang-format on

  return gameStateManager;
}

NAMESPACE_END(GunBox)

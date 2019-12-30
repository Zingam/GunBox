// Self
#include "Game.hpp"

// Project headers - Common
#include "Common/Macros/Logging.hpp"
#include "EventHandling/InputEventCallbacks.hpp"
#include "EventHandling/SystemEventCallbacks.hpp"
#include "GameStates/GameStateManager.hpp"
#include "Logging/Logging.hpp"

// Engine headers - System
#include <System/GUI/AlertBox.hpp>

// C Standard Library
#include <cassert>

NAMESPACE_BEGIN(GunBox)

////////////////////////////////////////////////////////////////////////////////
// Constructors & Destructors
////////////////////////////////////////////////////////////////////////////////

Game::Game(Application::ApplicationInfo applicationInfo)
  : Application::CoreApplication{ applicationInfo }
{}

Game::~Game() {}

////////////////////////////////////////////////////////////////////////////////
// Virtual methods
////////////////////////////////////////////////////////////////////////////////

Application::ExitCode
Game::Execute()
{
  auto gameStateManager = MainLoop_Initialize();
  if (gameStateManager) {
    MainLoop_Execute(*gameStateManager);
    MainLoop_Finalize();

    return Application::ExitCode::NoError;
  } else {
    return Application::ExitCode::InitializationError;
  }
}

////////////////////////////////////////////////////////////////////////////////
// Methods
////////////////////////////////////////////////////////////////////////////////

bool
Game::InitializeGraphicsRenderer()
{
  if (!graphicsRenderer->Initialize()) {
    GLogE("Failed to initialize the graphics renderer!");

    std::stringstream errorMessage;
    errorMessage << "Failed to initialize the graphics renderer:\n\n"
                    "  (Tip) Try a different renderer.\n\n"
                    "Press OK to quit the application!";

    using namespace System::GUI;
    AlertBox AlertBox{ applicationInfo.Title(),
                       errorMessage.str(),
                       Common::AlertBox_Base::AlertType_t::Error };
    AlertBox.Show();

    return false;
  }

  return true;
}

void
Game::MainLoop_Execute(GameStateManager& gameStateManager)
{
  GLogI(GetApplicationInfo().Title(), ": Running the game...");

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
      isRunning = gameStateManager.Run();
    }
  } while (isRunning);
}

void
Game::MainLoop_Finalize()
{
  GLogI(GetApplicationInfo().Title(), ": Exiting the game...");

  graphicsRenderer->Finalize();
}

std::unique_ptr<GameStateManager>
Game::MainLoop_Initialize()
{
  GLogI(GetApplicationInfo().Title(), ": Staring a new game...");

  assert(
    (nullptr != graphicsRenderer) &&
    "The Graphics Renderer was not properly created");

  if (IsFalse(InitializeGraphicsRenderer())) {
    return nullptr;
  }

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

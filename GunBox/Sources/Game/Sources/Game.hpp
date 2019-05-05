#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

// Engine headers - Application
#include "Application/CommandLineArgs.hpp"
#include "Application/CoreApplication.hpp"
#include "Application/ModuleInfo.hpp"

// C++ Standard Library
#include <chrono>

////////////////////////////////////////////////////////////////////////////////
// Forward declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(GunBox)

class GameStateManager;

NAMESPACE_END(GunBox)

////////////////////////////////////////////////////////////////////////////////
// Class declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(GunBox)

class Game : public Application::CoreApplication
{
public:
  Game(Application::ApplicationInfo applicationInfo);
  ~Game() final;

  // Virtual methods
public:
  auto Execute() -> Application::ExitCode final;

private:
  auto MainLoop_Initialize() -> std::unique_ptr<GameStateManager>;
  auto MainLoop_Execute(GameStateManager& gameStateManager) -> void;
  auto MainLoop_Finalize() -> void;

  // Constants
private:
  // 30Hz clock using fractional ticks
  const std::chrono::duration<double, std::ratio<1, 30>> executionPeriod_30Hz{
    1.0 / 30.0
  };
  // 60Hz clock using fractional ticks
  const std::chrono::duration<double, std::ratio<1, 60>> executionPeriod_60Hz{
    1.0 / 60.0
  };
};

NAMESPACE_END(GunBox)

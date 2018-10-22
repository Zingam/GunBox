// Self
#include "Game.hpp"

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
Game ::Execute()
{
  assert((nullptr != graphicsRenderer) &&
         "The Graphics Renderer was not properly created");

  std::cout << Info().Title() << ": Staring a new game...\n";
  graphicsRenderer->Initialize();

  std::cout << Info().Title() << ": Running the game...\n";
  while (true)
  {
    eventProcessor.ProcessEvents();
  }
  
  std::cout << Info().Title() << ": Exiting the game...\n";
  graphicsRenderer->Finalize();

  return Application::ExitCode::NoError;
}

NAMESPACE_END(GunBox)

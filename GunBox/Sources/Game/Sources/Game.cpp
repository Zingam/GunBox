// Self
#include "Game.hpp"

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

Game::ExitCode
Game ::Execute()
{
  std::cout << Info().Title() << ": Starting a new game...\n";

  return ExitCode::NoError;
}

NAMESPACE_END(GunBox)

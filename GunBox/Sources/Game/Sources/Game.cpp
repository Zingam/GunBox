// Self
#include "Game.hpp"

// C++ Standard Library
#include <iostream>
#include <memory>

NAMESPACE_START(GunBox)

////////////////////////////////////////////////////////////////////////////////
// Constructors & Destructors
////////////////////////////////////////////////////////////////////////////////

Game::Game(std::string const& name,
           Application::CommandLineArgs const& commandLineArgs)
  : Application::CoreApplication{ name, commandLineArgs }
{
#if defined(_DEBUG)
  if (commandLineArgs.ShowSystemConsole()) {
    hostPlatform.ShowSystemConsole();
  }

  if (commandLineArgs.Resolution()) {
    auto height = commandLineArgs.Resolution().value().Height;
    auto width = commandLineArgs.Resolution().value().Width;
    std::cout << "Desired resolution: " << width << "x" << height << "\n";
  }
#endif
}

Game::~Game()
{
#if defined(_DEBUG)
  if (commandLineArgs.ShowSystemConsole()) {
    hostPlatform.HideSystemConsole();
  }
#endif
}

////////////////////////////////////////////////////////////////////////////////
// Virtual methods
////////////////////////////////////////////////////////////////////////////////

Game::ExitCode
Game ::Execute() const
{
  std::cout << name << ": Starting a new game...\n";

  return ExitCode::NoError;
}

NAMESPACE_END(GunBox)

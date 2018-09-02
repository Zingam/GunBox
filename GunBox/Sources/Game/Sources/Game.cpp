// Self
#include "Game.hpp"

// System headers
#include <Windows.h>

// C++ Standard Library
#include <cstdio>
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
#if defined(_WINDOWS_) && defined(_DEBUG)
  if (commandLineArgs.ShowSystemConsole()) {
    AllocConsole();
    AttachConsole(GetCurrentProcessId());
    // Redirect the output stream to the console
    FILE* filestream_ptr;
    freopen_s(&filestream_ptr, "CON", "w", stdout);
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
#if defined(_WINDOWS_) && defined(_DEBUG)
  if (commandLineArgs.ShowSystemConsole()) {
    fclose(stdout);
    FreeConsole();
  }
#endif
}

////////////////////////////////////////////////////////////////////////////////
// Virtual methods
////////////////////////////////////////////////////////////////////////////////

void
Game ::Execute() const
{
  std::cout << name << ": Starting a new game...\n";
}

NAMESPACE_END(GunBox)

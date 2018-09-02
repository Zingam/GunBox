// Project headers
#include "Game.hpp"

// Engine headers - Common
#include "Common/Macros/Base.hpp"

// Engine headers - Application
#include "Application/CommandLineArgs.hpp"
#include "Application/CoreApplication.hpp"

NAMESPACE_START(Application)

////////////////////////////////////////////////////////////////////////////////
// Factory functions
////////////////////////////////////////////////////////////////////////////////

CoreApplication&
Create(std::string const& name, CommandLineArgs const& commandLineArgs)
{
  static GunBox::Game game { name, commandLineArgs };

  return game;
}

////////////////////////////////////////////////////////////////////////////////

NAMESPACE_END(Application)

// Project headers
#include "Game.hpp"
#include "Configuration/Values.hpp"

// Engine headers - Common
#include "Common/Macros/Base.hpp"

// Engine headers - Application
#include "Application/CommandLineArgs.hpp"
#include "Application/CoreApplication.hpp"

NAMESPACE_START(Application)

////////////////////////////////////////////////////////////////////////////////
// Factory functions
////////////////////////////////////////////////////////////////////////////////

/// <summary>
///   Creates a new specialized application object.
/// </summary>
/// <remarks>
///   Declared in <b>Engine</b> library.
/// </remarks>
CoreApplication&
Create()
{
  static GunBox::Game game{ { Game_Developer,
                              Game_Name,
                              { Game_VersionMajor,
                                Game_VersionMinor,
                                Game_VersionPatch,
                                Game_VersionBuildNumber } } };

  return game;
}

////////////////////////////////////////////////////////////////////////////////

NAMESPACE_END(Application)

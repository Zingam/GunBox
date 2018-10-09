// Project headers
#include "Configuration/Values.hpp"
#include "Game.hpp"

// Engine headers - Common
#include "Common/Macros/Base.hpp"

// Engine headers - Application
#include "Application/CommandLineArgs.hpp"
#include "Application/CoreApplication.hpp"

NAMESPACE_BEGIN(Application)

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
  static GunBox::Game game{ { Game_DeveloperOrganization,
                              Game_Title,
                              { Game_VersionMajor,
                                Game_VersionMinor,
                                Game_VersionPatch,
                                Game_VersionBuildNumber } } };

  return game;
}

////////////////////////////////////////////////////////////////////////////////

NAMESPACE_END(Application)

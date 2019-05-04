////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

// Project headers
#include "Configuration/Values.hpp"
#include "Game.hpp"

// Engine headers - Common
#include "Common/Version.hpp"
// Engine headers - Application
#include "Application/ModuleInfo.hpp"
#include "Application/CommandLineArgs.hpp"
#include "Application/CoreApplication.hpp"

#include <memory>

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
std::unique_ptr<CoreApplication>
Create()
{
  return std::make_unique<GunBox::Game>(
    ApplicationInfo{ Game_DeveloperOrganization,
                     Game_Title,
                     Version::Version_t{ Game_VersionMajor,
                                         Game_VersionMinor,
                                         Game_VersionPatch,
                                         Game_VersionBuildNumber } });
}

////////////////////////////////////////////////////////////////////////////////

NAMESPACE_END(Application)

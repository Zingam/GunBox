// Self
#include "FileSystem_SDL2.hpp"

// Project headers - Common
#include "Common/Macros/Logging.hpp"
// Inlcude headers - Application
#include "Application/ApplicationInfo.hpp"
// Project headers - System
#include "System/Platforms/SDL2/SDL2_ErrorChecking.hpp"

// Third party libraries
#include <SDL.h>

NAMESPACE_BEGIN(System::HostPlatformClasses)

////////////////////////////////////////////////////////////////////////////////
// Properties
////////////////////////////////////////////////////////////////////////////////

auto
FileSystem_SDL::BasePath() const -> std::string const&
{
  return this->basePath;
}

auto
FileSystem_SDL::PreferencesRootPath() const -> std::string const&
{
  return this->preferencesRootPath;
}

////////////////////////////////////////////////////////////////////////////////
// Methods
////////////////////////////////////////////////////////////////////////////////

bool
FileSystem_SDL::Initialize(Application::ApplicationInfo const& applicationInfo)
{
  this->applicationInfo = &applicationInfo;

  SDL_Init(0);

  auto basePath = SDL_GetBasePath();
  if (nullptr != basePath) {
    this->basePath = basePath;
  } else {
    this->basePath = "./";
  }
  SDL_free(basePath);

  auto preferencesRootPath = SDL_GetPrefPath(
    applicationInfo.Organization().c_str(), applicationInfo.Title().c_str());
  if (nullptr != preferencesRootPath) {
    this->preferencesRootPath = preferencesRootPath;
  } else {
    this->preferencesRootPath = "./";
  }
  SDL_free(preferencesRootPath);
  
  SDL_Quit();

  return true;
}

void
FileSystem_SDL::Finalize()
{}

NAMESPACE_END(System::HostPlatformClasses)

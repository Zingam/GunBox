// Self
#include "SubSystems_SDL2.hpp"

// Project headers - Logger
#include "Logger/LogAPI.hpp"
// Project headers - System
#include "System/Platforms/SDL2/SDL2_ErrorChecking.hpp"

// Third party libraries
#include <SDL.h>

NAMESPACE_BEGIN(System::HostPlatformClasses)

bool
SubSystems_SDL::Initialize()
{
  SDL_IfFailed(
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_GAMECONTROLLER))
  {
    reLogE("Unable to initialize SDL2: ", SDL_GetError());

    return false;
  }

  return true;
}

void
SubSystems_SDL::Finalize()
{
  // Clean up
  SDL_Quit();
}

NAMESPACE_END(System::HostPlatformClasses)

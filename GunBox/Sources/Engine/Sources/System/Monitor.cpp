// Self
#include "Monitor.hpp"

// Project headers - Common
#include "Common/Macros/SDL2_ErrorChecking.hpp"

// Third party
#include <SDL_video.h>

NAMESPACE_BEGIN(System)

////////////////////////////////////////////////////////////////////////////////
// Constructors & Destructors
////////////////////////////////////////////////////////////////////////////////

Monitor::Monitor(Rectangle2D rectangle)
  : rectangle{ rectangle }
{}

////////////////////////////////////////////////////////////////////////////////
// Properties
////////////////////////////////////////////////////////////////////////////////

bool
Monitor::IsPrimary()
{
  if ((0 == rectangle.Coordinate.X) && (0 == rectangle.Coordinate.Y)) {
    return true;
  } else {
    return false;
  }
}

Point2D
Monitor::MidPoint()
{
  auto x = rectangle.Size.Width % 2;
  auto y = rectangle.Size.Height % 2;
  return { x, y };
}

////////////////////////////////////////////////////////////////////////////////
// Friend functions
////////////////////////////////////////////////////////////////////////////////

std::vector<Monitor>
EnumerateMonitors()
{
  SDL_Log("Enumerating video displays:");

  auto videoDisplayCount = SDL_GetNumVideoDisplays();
  SDL_IfFailed(videoDisplayCount)
  {
    SDL_LogError("Unable to get video display count: %s", SDL_GetError());
    return {};
  }

  std::vector<Monitor> monitors;
  for (auto i = 0; i < videoDisplayCount; ++i) {
    SDL_Log("  Video display name: %s", SDL_GetDisplayName(i));

    SDL_Rect displayBounds;
    SDL_GetDisplayBounds(i, &displayBounds);
    monitors.emplace_back(Monitor{ { { displayBounds.x, displayBounds.y },
                                     { displayBounds.w, displayBounds.h } } });
  }

  return monitors;
}

NAMESPACE_END(System)

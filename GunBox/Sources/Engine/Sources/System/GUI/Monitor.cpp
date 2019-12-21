// Self
#include "Monitor.hpp"

// Project headers - Common
#include "Common/Macros/Logging.hpp"
// Project headers - System
#include "System/Platforms/SDL2/SDL2_ErrorChecking.hpp"

// Third party
#include <SDL_video.h>

NAMESPACE_BEGIN(System)

////////////////////////////////////////////////////////////////////////////////
// Constructors & Destructors
////////////////////////////////////////////////////////////////////////////////

Monitor::Monitor(DeviceTypes::Graphics::Rectangle2D_t rectangle)
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

DeviceTypes::Graphics::Point2D_t
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
  ELogI("Enumerating video displays:");

  auto videoDisplayCount = SDL_GetNumVideoDisplays();
  SDL_IfFailed(videoDisplayCount)
  {
    reLogE("Unable to get video display count: ", SDL_GetError());

    return {};
  }

  std::vector<Monitor> monitors;
  for (auto i = 0; i < videoDisplayCount; ++i) {
    ELogI("  Video display name: ", SDL_GetDisplayName(i));

    SDL_Rect displayBounds;
    SDL_GetDisplayBounds(i, &displayBounds);
    monitors.emplace_back(Monitor{ { { displayBounds.x, displayBounds.y },
                                     { displayBounds.w, displayBounds.h } } });
  }

  return monitors;
}

NAMESPACE_END(System)

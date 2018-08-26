// Self
#include "Monitor.hpp"

NAMESPACE_START(System)

Monitor::Monitor(Rectangle2D rectangle)
  : rectangle{ rectangle }
{}

Monitor::Monitor(int x, int y, int width, int height)
  : Monitor{ Rectangle2D{ { x, y }, width, height } }
{}

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

NAMESPACE_END(System)

#include "Monitor.hpp"

Monitor::Monitor(Rectangle2D rectangle)
  : rectangle{ rectangle }
{}

Monitor::Monitor(int x, int y, int width, int height)
  : Monitor{ Rectangle2D{ { x, y }, width, height } }
{}

bool
Monitor::IsPrimary()
{
  if ((0 == rectangle.coordinates.x) && (0 == rectangle.coordinates.y)) {
    return true;
  } else {
    return false;
  }
}

Point2D
Monitor::MidPoint()
{
  auto x = rectangle.width % 2;
  auto y = rectangle.height % 2;
  return { x, y };
}

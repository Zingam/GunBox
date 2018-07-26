#pragma once

#include "Geometry.hpp"


class Monitor
{
public:
  Monitor(Rectangle2D rectangle);
  Monitor(int x, int y, int width, int height);

public:
  auto IsPrimary() -> bool;
  auto MidPoint() -> Point2D;

private:
  Rectangle2D rectangle;
};

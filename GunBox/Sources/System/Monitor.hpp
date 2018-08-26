#pragma once

// Project headers - Common
#include "Common/Macros/Base.hpp"

// Project headers - System
#include "Geometry.hpp"

NAMESPACE_START(System)

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

NAMESPACE_END(System)

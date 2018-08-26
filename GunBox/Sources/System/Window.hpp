#pragma once

// Project headers - Common
#include "Common/Macros/Base.hpp"

// Project headers - System
#include "Geometry.hpp"

NAMESPACE_START(System)

class Window
{
public:
  enum class Flags
  {
    Centered,
    DefaultLocation
  };

public:
  Window(Point2D coordinate, Dimensions size);
  Window(Flags flags, Dimensions size);
};

NAMESPACE_END(System)

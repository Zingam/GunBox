#pragma once

#include "Geometry.hpp"

class Window
{
public:
  enum class Flags
  {
    Centered,
    DefaultLocation
  };

public:
  Window(Point2D coordinates, int width, int height);
  Window(Flags flags, int width, int height);
};

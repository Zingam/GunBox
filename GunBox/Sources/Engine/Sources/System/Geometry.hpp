#pragma once

// Project headers - Common
#include "Common/Macros/Base.hpp"

// Standard C++ Libraries
#include <vector>

NAMESPACE_START(System)

struct Dimensions
{
  int Height;
  int Width;
};

struct Point2D
{
  int X;
  int Y;
};

struct Rectangle2D
{
  Point2D Coordinate;
  Dimensions Size;
};

NAMESPACE_END(System)

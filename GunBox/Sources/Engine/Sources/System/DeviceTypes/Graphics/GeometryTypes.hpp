#pragma once

// Project headers - Common
#include "Common/Macros/Base.hpp"

NAMESPACE_BEGIN(System::DeviceTypes::Graphics)

struct Dimensions
{
  Dimensions() = default;
  Dimensions(int width, int height);

  int Height;
  int Width;
};

struct Point2D
{
  Point2D() = default;
  Point2D(int x, int y);

  int X;
  int Y;
};

struct Rectangle2D
{
  Rectangle2D() = default;
  Rectangle2D(Point2D coordinate, Dimensions size);

  Point2D Coordinate;
  Dimensions Size;
};

NAMESPACE_END(System::DeviceTypes::Graphics)

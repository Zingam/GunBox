#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Type declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(System::DeviceTypes::Graphics)

////////////////////////////////////////////////////////////////////////////////

struct Dimensions_t
{
  Dimensions_t() = default;
  Dimensions_t(int width, int height);

  int Height;
  int Width;
};

////////////////////////////////////////////////////////////////////////////////

struct Point2D_t
{
  Point2D_t() = default;
  Point2D_t(int x, int y);

  int X;
  int Y;
};

////////////////////////////////////////////////////////////////////////////////

struct Rectangle2D_t
{
  Rectangle2D_t() = default;
  Rectangle2D_t(Point2D_t coordinate, Dimensions_t size);

  Point2D_t Coordinate;
  Dimensions_t Size;
};

////////////////////////////////////////////////////////////////////////////////

NAMESPACE_END(System::DeviceTypes::Graphics)

#include "GeometryTypes.hpp"

NAMESPACE_BEGIN(System::DeviceTypes::Graphics)

////////////////////////////////////////////////////////////////////////////////
// Constructors & Destructors
////////////////////////////////////////////////////////////////////////////////

Dimensions::Dimensions(int width, int height)
  : Height{ height }
  , Width{ width } {};

Point2D::Point2D(int x, int y)
  : X{ x }
  , Y{ y } {};

Rectangle2D::Rectangle2D(Point2D coordinate, Dimensions size)
  : Coordinate{ coordinate }
  , Size{ size } {};

NAMESPACE_END(System::DeviceTypes::Graphics)

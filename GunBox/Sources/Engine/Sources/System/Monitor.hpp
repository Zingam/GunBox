#pragma once

// Project headers - Common
#include "Common/Macros/Base.hpp"

// Project headers - System
#include "System/Geometry.hpp"

// C++ Standard Library
#include <vector>

NAMESPACE_BEGIN(System)

class Monitor
{
private:
  Monitor(Rectangle2D rectangle);

  // Properties
public:
  auto IsPrimary() -> bool;
  auto MidPoint() -> Point2D;

public:
  friend auto EnumerateMonitors() -> std::vector<Monitor>;

private:
  Rectangle2D rectangle;
};

////////////////////////////////////////////////////////////////////////////////
// Friend functions
////////////////////////////////////////////////////////////////////////////////

auto
EnumerateMonitors() -> std::vector<Monitor>;

NAMESPACE_END(System)

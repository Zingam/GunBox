#pragma once

// Project headers - BASE
#include "Common/Macros/Base.hpp"

// Project headers - System
#include "System/DeviceTypes/Graphics/GeometryTypes.hpp"

// C++ Standard Library
#include <vector>

NAMESPACE_BEGIN(System)

class Monitor
{
private:
  Monitor(DeviceTypes::Graphics::Rectangle2D rectangle);

  // Properties
public:
  auto IsPrimary() -> bool;
  auto MidPoint() -> DeviceTypes::Graphics::Point2D;

public:
  friend auto EnumerateMonitors() -> std::vector<Monitor>;

private:
  DeviceTypes::Graphics::Rectangle2D rectangle;
};

////////////////////////////////////////////////////////////////////////////////
// Friend functions
////////////////////////////////////////////////////////////////////////////////

auto
EnumerateMonitors() -> std::vector<Monitor>;

NAMESPACE_END(System)

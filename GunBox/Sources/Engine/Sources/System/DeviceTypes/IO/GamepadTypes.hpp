#pragma once

// Project headers - BASE
#include "Common/Macros/Base.hpp"

// C Standard Library
#include <cstdint>

NAMESPACE_BEGIN(System::DeviceTypes::IO)

enum class GamepadAxis
{
  StickLeftX,
  StickLeftY,
  StickRightX,
  StickRightY,
  TriggerLeft,
  TriggerRight
};

enum class GamepadButton
{
  A,
  B,
  X,
  Y,
  DPadUp,
  DPadDown,
  DpadLeft,
  DPadRight,
  ThumbLeft,
  ThumbRight,
  ShoulderLeft,
  ShoulderRight,
  Back,
  Guide,
  Start,
};

using GamepadId = std::int32_t;

NAMESPACE_END(System::DeviceTypes::IO)

#pragma once

// BASE MACROS header
#include "Common/Macros/Base.hpp"

// C Standard Library
#include <cstdint>

NAMESPACE_BEGIN(System::DeviceTypes::IO)

enum class GamepadAxis_t
{
  StickLeftX,
  StickLeftY,
  StickRightX,
  StickRightY,
  TriggerLeft,
  TriggerRight
};

enum class GamepadButton_t
{
  UNKNOWN,
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

using GamepadId_t = std::int32_t;

NAMESPACE_END(System::DeviceTypes::IO)

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
  ButtonFaceA,
  ButtonFaceB,
  ButtonFaceX,
  ButtonFaceY,
  ButtonMenuBack,
  ButtonMenuGuide,
  ButtonMenuStart,
  ButtonShoulderLeft,
  ButtonShoulderRight,
  ButtonThumbLeft,
  ButtonThumbRight,
  DPadUp,
  DPadDown,
  DpadLeft,
  DPadRight,
};

enum class GamepadEvents_t
{
  UNKNOWN,
  ButtonFaceA,
  ButtonFaceB,
  ButtonFaceX,
  ButtonFaceY,
  ButtonMenuBack,
  ButtonMenuGuide,
  ButtonMenuStart,
  ButtonShoulderLeft,
  ButtonShoulderRight,
  ButtonThumbLeft,
  ButtonThumbRight,
  DeviceAdded,
  DeviceRemoved,
  DPadDown,
  DpadLeft,
  DPadRight,
  DPadUp,
  StickLeftX,
  StickLeftX_Left,
  StickLeftX_Right,
  StickLeftY,
  StickLeftY_Down,
  StickLeftY_Up,
  StickRightX,
  StickRightX_Left,
  StickRightX_Right,
  StickRightY,
  StickRightY_Down,
  StickRightY_Up,
  TriggerLeft,
  TriggerRight,
  __ElementsCount__
};

using GamepadId_t = std::int32_t;

NAMESPACE_END(System::DeviceTypes::IO)

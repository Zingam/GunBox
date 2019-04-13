#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

// C Standard Library
#include <cstdint>

////////////////////////////////////////////////////////////////////////////////
// Type declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(System::DeviceTypes::Input)

////////////////////////////////////////////////////////////////////////////////

enum class GamepadAxis_t
{
  StickLeftX,
  StickLeftY,
  StickRightX,
  StickRightY,
  TriggerLeft,
  TriggerRight,
  _UNKNOWN_,
  __ElementCount__
};

// Define 'GamepadAxis_t_ElementCount'
EnumSize(GamepadAxis_t);

////////////////////////////////////////////////////////////////////////////////

enum class GamepadButton_t
{
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
  DPadLeft,
  DPadRight,
  _UNKNOWN_,
  __ElementCount__
};

// Define 'GamepadButton_t_ElementCount'
EnumSize(GamepadButton_t);

////////////////////////////////////////////////////////////////////////////////

enum class GamepadEvent_t
{
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
  DPadLeft,
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
  _UNKNOWN_,
  __ElementCount__
};

// Define 'GamepadEvent_t_ElementCount'
EnumSize(GamepadEvent_t);

////////////////////////////////////////////////////////////////////////////////

using GamepadId_t = std::int32_t;

////////////////////////////////////////////////////////////////////////////////

NAMESPACE_END(System::DeviceTypes::Input)

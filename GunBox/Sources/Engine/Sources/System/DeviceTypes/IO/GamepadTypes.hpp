#pragma once

// BASE MACROS header
#include "Common/Macros/Base.hpp"

// C Standard Library
#include <cstdint>

NAMESPACE_BEGIN(System::DeviceTypes::IO)

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
  __ElementsCount__
};

constexpr auto GamepadAxis_t_ElementsCount =
  EnumCast(GamepadAxis_t::__ElementsCount__);

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
  __ElementsCount__
};

constexpr auto GamepadButton_t_ElementsCount =
  EnumCast(GamepadButton_t::__ElementsCount__);

////////////////////////////////////////////////////////////////////////////////

enum class GamepadEvents_t
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
  __ElementsCount__
};

constexpr auto GamepadEvents_t_ElementsCount =
  EnumCast(GamepadEvents_t::__ElementsCount__);

////////////////////////////////////////////////////////////////////////////////

using GamepadId_t = std::int32_t;

////////////////////////////////////////////////////////////////////////////////

NAMESPACE_END(System::DeviceTypes::IO)

#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

// Project headers - System
#include "System/DeviceTypes/Input/GamepadTypes.hpp"
#include "System/DeviceTypes/Input/KeyboardTypes.hpp"

NAMESPACE_BEGIN(System::EventProcessing)

class InputEventCallbacks_Interface
{
public:
  virtual ~InputEventCallbacks_Interface() = 0;

  // Pure virtual methods
public:
  // clang-format off
  virtual auto GamepadAxisMotion(
    System::DeviceTypes::Input::GamepadId_t id,
    System::DeviceTypes::Input::GamepadAxis_t axis,
    double value)
    -> void = 0;

  virtual auto GamepadButtonDown(
    System::DeviceTypes::Input::GamepadId_t id,
    System::DeviceTypes::Input::GamepadButton_t button)
    -> void = 0;

  virtual auto GamepadButtonUp(
    System::DeviceTypes::Input::GamepadId_t id,
    System::DeviceTypes::Input::GamepadButton_t button)
    -> void = 0;

  virtual auto GamepadDeviceAdd(
    System::DeviceTypes::Input::GamepadId_t id)
    -> void = 0;

  virtual auto GamepadDeviceRemove(
    System::DeviceTypes::Input::GamepadId_t id)
    -> void = 0;

  virtual auto KeyboardKeyDown(
    System::DeviceTypes::Input::Key_t key)
    -> void = 0;

  virtual auto KeyboardKeyUp(
    System::DeviceTypes::Input::Key_t key)
    -> void = 0;
  // clang-format on
};

NAMESPACE_END(System::EventProcessing)

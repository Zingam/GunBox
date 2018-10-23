#pragma once

// Project headers - BASE
#include "Common/Macros/Base.hpp"

// Project headers - System
#include "System/DeviceTypes/IO/GamepadTypes.hpp"
#include "System/DeviceTypes/IO/KeyboardTypes.hpp"

NAMESPACE_BEGIN(System::EventProcessing)

class InputEventCallbacks
{
public:
  virtual ~InputEventCallbacks() = 0;

  // Pure virtual methods
public:
  // clang-format off
  virtual auto GamepadAxisMotion(
    System::DeviceTypes::IO::GamepadId_t id,
    System::DeviceTypes::IO::GamepadAxis_t axis,
    float value)
    -> void = 0;

  virtual auto GamepadButtonDown(
    System::DeviceTypes::IO::GamepadId_t id,
    System::DeviceTypes::IO::GamepadButton_t button)
    -> void = 0;

  virtual auto GamepadButtonUp(
    System::DeviceTypes::IO::GamepadId_t id,
    System::DeviceTypes::IO::GamepadButton_t button)
    -> void = 0;

  virtual auto GamepadDeviceAdd(
    System::DeviceTypes::IO::GamepadId_t id)
    -> void = 0;

  virtual auto GamepadDeviceRemove(
    System::DeviceTypes::IO::GamepadId_t id)
    -> void = 0;

  virtual auto KeyboardKeyDown(
    System::DeviceTypes::IO::Key_t key)
    -> void = 0;

  virtual auto KeyboardKeyUp(
    System::DeviceTypes::IO::Key_t key)
    -> void = 0;
  // clang-format on
};

NAMESPACE_END(System::EventProcessing)

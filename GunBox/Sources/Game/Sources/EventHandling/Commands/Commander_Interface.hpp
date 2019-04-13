#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

// Engine headers - System
#include "System/DeviceTypes/Input/GamepadTypes.hpp"
#include "System/DeviceTypes/Input/KeyboardTypes.hpp"

// C++ Standard Library
#include <memory>

////////////////////////////////////////////////////////////////////////////////
// Forward declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(GunBox)

class Command_Interface;

NAMESPACE_END(GunBox)

////////////////////////////////////////////////////////////////////////////////
// Class declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(GunBox)

class Commander_Interface
{
public:
  Commander_Interface();
  virtual ~Commander_Interface() = 0;

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

protected:
  std::shared_ptr<Command_Interface> const command_Null;
};

NAMESPACE_END(GunBox)

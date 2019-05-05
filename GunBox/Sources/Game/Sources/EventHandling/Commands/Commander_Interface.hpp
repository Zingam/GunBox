#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

// Engine headers - Application
#include "Application/ApplicationState.hpp"
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
  // Constructors & Destructors
public:
  Commander_Interface();
  virtual ~Commander_Interface() = 0;

  // Virtual methods - Input
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
    System::DeviceTypes::Input::Key_t const& key)
    -> void = 0;

  virtual auto KeyboardKeyUp(
    System::DeviceTypes::Input::Key_t const& key)
    -> void = 0;
  // clang-format on

  // Virtual methods - System events
public:
  virtual auto SystemEvent(Application::State_t applicationState)
    -> void = 0;

  // Data members - variables
protected:
  std::shared_ptr<Command_Interface> const command_Null;
};

NAMESPACE_END(GunBox)

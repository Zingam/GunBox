#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

// Project headers
#include "EventHandling/Commands/Commander_Interface.hpp"

// C++ Standard Library
#include <array>
#include <memory>

////////////////////////////////////////////////////////////////////////////////
// Forward declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(GunBox)

class Command_Interface;
class MainMenu;

NAMESPACE_END(GunBox)

////////////////////////////////////////////////////////////////////////////////
// Class declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(GunBox)

class Commander_Null final : public Commander_Interface
{
public:
  // Constructors & Destructors
  ~Commander_Null() final;

  // Virtual methods
public:
  // clang-format off
  auto GamepadAxisMotion(
    System::DeviceTypes::Input::GamepadId_t id,
    System::DeviceTypes::Input::GamepadAxis_t axis,
    double value)
    -> void final;

  auto GamepadButtonDown(
    System::DeviceTypes::Input::GamepadId_t id,
    System::DeviceTypes::Input::GamepadButton_t button)
    -> void final;

  auto GamepadButtonUp(
    System::DeviceTypes::Input::GamepadId_t id,
    System::DeviceTypes::Input::GamepadButton_t button)
    -> void final;

  auto GamepadDeviceAdd(
    System::DeviceTypes::Input::GamepadId_t id)
    -> void final;

  auto GamepadDeviceRemove(
    System::DeviceTypes::Input::GamepadId_t id)
    -> void final;

  auto KeyboardKeyDown(
    System::DeviceTypes::Input::Key_t const& key)
    -> void final;

  auto KeyboardKeyUp(
    System::DeviceTypes::Input::Key_t const& key)
    -> void final;
  // clang-format on

  // Virtual methods - System events
public:
  auto SystemEvent(Application::State_t applicationState) -> void final;
};

NAMESPACE_END(GunBox)

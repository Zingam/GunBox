#pragma once

// BASE MACROS header
#include "Common/Macros/Base.hpp"

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
  ~Commander_Null() final;

public:
  // clang-format off
  auto GamepadAxisMotion(
    System::DeviceTypes::IO::GamepadId_t id,
    System::DeviceTypes::IO::GamepadAxis_t axis,
    double value)
    -> void final;

  auto GamepadButtonDown(
    System::DeviceTypes::IO::GamepadId_t id,
    System::DeviceTypes::IO::GamepadButton_t button)
    -> void final;

  auto GamepadButtonUp(
    System::DeviceTypes::IO::GamepadId_t id,
    System::DeviceTypes::IO::GamepadButton_t button)
    -> void final;

  auto GamepadDeviceAdd(
    System::DeviceTypes::IO::GamepadId_t id)
    -> void final;

  auto GamepadDeviceRemove(
    System::DeviceTypes::IO::GamepadId_t id)
    -> void final;

  auto KeyboardKeyDown(
    System::DeviceTypes::IO::Key_t key)
    -> void final;

  auto KeyboardKeyUp(
    System::DeviceTypes::IO::Key_t key)
    -> void final;
  // clang-format on
};

NAMESPACE_END(GunBox)

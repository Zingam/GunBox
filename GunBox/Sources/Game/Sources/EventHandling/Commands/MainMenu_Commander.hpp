#pragma once

// BASE MACROS header
#include "Common/Macros/Base.hpp"

// Project headers
#include "EventHandling/Commands/Commander_Interface.hpp"

// Engine headers - System
#include "System/DeviceTypes/IO/GamepadTypes.hpp"
#include "System/DeviceTypes/IO/KeyboardTypes.hpp"

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

class MainMenu_Commander final : public Commander_Interface
{
public:
  MainMenu_Commander(MainMenu& mainMenu);
  ~MainMenu_Commander() final;

public:
  // clang-format off
  auto GamepadAxisMotion(
    System::DeviceTypes::IO::GamepadId_t id,
    System::DeviceTypes::IO::GamepadAxis_t axis,
    float value)
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

private:
  std::array<
    std::shared_ptr<Command_Interface>,
    System::DeviceTypes::IO::GamepadEvents_t_ElementsCount>
    commands;
};

NAMESPACE_END(GunBox)

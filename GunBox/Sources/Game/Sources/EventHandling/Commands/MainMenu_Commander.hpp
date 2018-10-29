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

NAMESPACE_BEGIN(GunBox)

class Command_Interface;
class MainMenu;

NAMESPACE_END(GunBox)

NAMESPACE_BEGIN(GunBox)

class MainMenu_Commander final : public Commander_Interface
{
public:
  MainMenu_Commander(MainMenu& mainMenu);
  ~MainMenu_Commander() final;

public:
  // clang-format off
  virtual auto GamepadAxisMotion(
    System::DeviceTypes::IO::GamepadId_t id,
    System::DeviceTypes::IO::GamepadAxis_t axis,
    float value)
    -> void;

  virtual auto GamepadButtonDown(
    System::DeviceTypes::IO::GamepadId_t id,
    System::DeviceTypes::IO::GamepadButton_t button)
    -> void;

  virtual auto GamepadButtonUp(
    System::DeviceTypes::IO::GamepadId_t id,
    System::DeviceTypes::IO::GamepadButton_t button)
    -> void;

  virtual auto GamepadDeviceAdd(
    System::DeviceTypes::IO::GamepadId_t id)
    -> void;

  virtual auto GamepadDeviceRemove(
    System::DeviceTypes::IO::GamepadId_t id)
    -> void;

  virtual auto KeyboardKeyDown(
    System::DeviceTypes::IO::Key_t key)
    -> void;

  virtual auto KeyboardKeyUp(
    System::DeviceTypes::IO::Key_t key)
    -> void;
  // clang-format on

  private:
  std::array<
    std::shared_ptr<Command_Interface>,
    System::DeviceTypes::IO::GamepadEvents_Count>
    commands;

  std::array<
    std::shared_ptr<Command_Interface>,
    EnumCast(System::DeviceTypes::IO::GamepadEvents_t::__ElementsCount__)>
    commands1;
};

NAMESPACE_END(GunBox)

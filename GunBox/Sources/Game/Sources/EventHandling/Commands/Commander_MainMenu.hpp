#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

// Project headers
#include "EventHandling/Commands/CommandTypes.hpp"
#include "EventHandling/Commands/Commander_Interface.hpp"
#include "EventHandling/Commands/MainMenu/Command_MainMenu_Accept.hpp"
#include "EventHandling/Commands/MainMenu/Command_MainMenu_Back.hpp"

// Engine headers - System
#include "System/DeviceTypes/Input/GamepadTypes.hpp"
#include "System/DeviceTypes/Input/KeyboardTypes.hpp"

// C++ Standard Library
#include <array>
#include <chrono>
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

class Commander_MainMenu final : public Commander_Interface
{
  // Constructors & Destructors
public:
  Commander_MainMenu(MainMenu& mainMenu);
  ~Commander_MainMenu() final;

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
    System::DeviceTypes::Input::Key_t key)
    -> void final;

  auto KeyboardKeyUp(
    System::DeviceTypes::Input::Key_t key)
    -> void final;
  // clang-format on

  // Virtual methods - System events
public:
  auto SystemEvent(Application::State_t applicationState) -> void final;

  // Methods
private:
  auto Initialize() -> void;
  auto MakeCommand(Commands_MainMenu_t commandType)
    -> std::shared_ptr<Command_Interface>;

  // Data members - Constants
private:
  double const commandActivationDeadZoneMinValue = 0.1;
  // 60Hz clock using fractional ticks
  std::chrono::duration<double, std::ratio<1, 60>> const executionPeriod;

  // Data members - Variables
private:
  std::array<
    std::shared_ptr<Command_Interface>,
    System::DeviceTypes::Input::GamepadEvent_t_ElementCount>
    commands_Gamepad;
  std::array<
    std::shared_ptr<Command_Interface>,
    System::DeviceTypes::Input::ScanCode_t_ElementCount>
    commands_Keyboard;
  std::shared_ptr<Command_Interface> commands_SystemCommand;
  MainMenu& mainMenu;
};

NAMESPACE_END(GunBox)

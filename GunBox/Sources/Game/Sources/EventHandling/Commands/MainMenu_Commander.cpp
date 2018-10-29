// Self
#include "MainMenu_Commander.hpp"

// Project headers
#include "EventHandling/Commands/Command_Interface.hpp"

NAMESPACE_BEGIN(GunBox)

auto
MainMenu_Commander::GamepadAxisMotion(
  System::DeviceTypes::IO::GamepadId_t id,
  System::DeviceTypes::IO::GamepadAxis_t axis,
  float value) -> void
{
  using namespace System::DeviceTypes::IO;

  auto GetCommand = [this, value](
                      GamepadEvents_t const axisLeftOrDown,
                      GamepadEvents_t const axisRightOrUp) {
    if (0 > value) {
      return this->commands[EnumCast(axisLeftOrDown)];
    } else if (0 < value) {
      return this->commands[EnumCast(axisRightOrUp)];
    } else {
      return this->commands[EnumCast(GamepadEvents_t::UNKNOWN)];
    }
  };

  switch (axis) {
    case GamepadAxis_t::StickLeftX: {
      auto command = GetCommand(
        GamepadEvents_t::StickLeftX_Left, GamepadEvents_t::StickLeftX_Right);
      command->Execute();
      break;
    }
    case GamepadAxis_t::StickLeftY: {
      auto command = GetCommand(
        GamepadEvents_t::StickLeftY_Down, GamepadEvents_t::StickLeftY_Up);
      command->Execute();
      break;
    }
    case GamepadAxis_t::StickRightX: {
      auto command = GetCommand(
        GamepadEvents_t::StickRightX_Left, GamepadEvents_t::StickRightX_Right);
      command->Execute();
      break;
    }
    case GamepadAxis_t::StickRightY: {
      auto command = GetCommand(
        GamepadEvents_t::StickRightY_Down, GamepadEvents_t::StickRightY_Up);
      command->Execute();
      break;
    }
    case GamepadAxis_t::TriggerLeft: {
      auto command = commands[EnumCast(GamepadEvents_t::TriggerLeft)];
      command->Execute();
      break;
    }
    case GamepadAxis_t::TriggerRight: {
      auto command = commands[EnumCast(GamepadEvents_t::TriggerRight)];
      command->Execute();
      break;
    }
  }
}

void
MainMenu_Commander::GamepadButtonDown(
  System::DeviceTypes::IO::GamepadId_t id,
  System::DeviceTypes::IO::GamepadButton_t button)
{}

void
MainMenu_Commander::GamepadButtonUp(
  System::DeviceTypes::IO::GamepadId_t id,
  System::DeviceTypes::IO::GamepadButton_t button)
{}

void
MainMenu_Commander::GamepadDeviceAdd(System::DeviceTypes::IO::GamepadId_t id)
{}

void
MainMenu_Commander::GamepadDeviceRemove(System::DeviceTypes::IO::GamepadId_t id)
{}

void
MainMenu_Commander::KeyboardKeyDown(System::DeviceTypes::IO::Key_t key)
{}

void
MainMenu_Commander::KeyboardKeyUp(System::DeviceTypes::IO::Key_t key)
{}

NAMESPACE_END(GunBox)

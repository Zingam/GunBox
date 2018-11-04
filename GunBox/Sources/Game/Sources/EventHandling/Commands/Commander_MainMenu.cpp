// Self
#include "Commander_MainMenu.hpp"

// Project headers
#include "EventHandling/Commands/MainMenu/Command_MainMenu_Accept.hpp"
#include "EventHandling/Commands/MainMenu/Command_MainMenu_Back.hpp"
#include "EventHandling/Commands/MainMenu/Command_MainMenu_MoveDown.hpp"
#include "EventHandling/Commands/MainMenu/Command_MainMenu_MoveLeft.hpp"
#include "EventHandling/Commands/MainMenu/Command_MainMenu_MoveRight.hpp"
#include "EventHandling/Commands/MainMenu/Command_MainMenu_MoveUp.hpp"

NAMESPACE_BEGIN(GunBox)

Commander_MainMenu::Commander_MainMenu(MainMenu& mainMenu)
  : mainMenu{ mainMenu }
{
  commands_Gamepad.fill(command_Null);
  commands_Keyboard.fill(command_Null);
  // Initialize default input-to-command mappings
  Initialize();
}

Commander_MainMenu::~Commander_MainMenu() {}

auto
Commander_MainMenu::GamepadAxisMotion(
  System::DeviceTypes::IO::GamepadId_t id,
  System::DeviceTypes::IO::GamepadAxis_t axis,
  double value) -> void
{
  using namespace System::DeviceTypes::IO;

  auto GetCommand = [this, value](
                      GamepadEvents_t const axisLeftOrDown,
                      GamepadEvents_t const axisRightOrUp) {
    if (0 > value) {
      return this->commands_Gamepad[EnumCast(axisLeftOrDown)];
    } else if (0 < value) {
      return this->commands_Gamepad[EnumCast(axisRightOrUp)];
    } else {
      return this->commands_Gamepad[EnumCast(GamepadEvents_t::_UNKNOWN_)];
    }
  };

  switch (axis) {
    case GamepadAxis_t::StickLeftX: {
      auto command = GetCommand(
        GamepadEvents_t::StickLeftX_Left, GamepadEvents_t::StickLeftX_Right);
      command->Execute(id);
      break;
    }
    case GamepadAxis_t::StickLeftY: {
      auto command = GetCommand(
        GamepadEvents_t::StickLeftY_Down, GamepadEvents_t::StickLeftY_Up);
      command->Execute(id);
      break;
    }
    case GamepadAxis_t::StickRightX: {
      auto command = GetCommand(
        GamepadEvents_t::StickRightX_Left, GamepadEvents_t::StickRightX_Right);
      command->Execute(id);
      break;
    }
    case GamepadAxis_t::StickRightY: {
      auto command = GetCommand(
        GamepadEvents_t::StickRightY_Down, GamepadEvents_t::StickRightY_Up);
      command->Execute(id);
      break;
    }
    case GamepadAxis_t::TriggerLeft: {
      auto command = commands_Gamepad[EnumCast(GamepadEvents_t::TriggerLeft)];
      command->Execute(id);
      break;
    }
    case GamepadAxis_t::TriggerRight: {
      auto command = commands_Gamepad[EnumCast(GamepadEvents_t::TriggerRight)];
      command->Execute(id);
      break;
    }
  }
}

void
Commander_MainMenu::GamepadButtonDown(
  System::DeviceTypes::IO::GamepadId_t id,
  System::DeviceTypes::IO::GamepadButton_t button)
{
  using namespace System::DeviceTypes::IO;

  switch (button) {
    case GamepadButton_t::ButtonFaceA: {
      auto command = commands_Gamepad[EnumCast(GamepadEvents_t::ButtonFaceA)];
      command->Execute(id);
      break;
    }
    case GamepadButton_t::ButtonFaceB: {
      auto command = commands_Gamepad[EnumCast(GamepadEvents_t::ButtonFaceB)];
      command->Execute(id);
      break;
    }
    case GamepadButton_t::ButtonFaceX: {
      auto command = commands_Gamepad[EnumCast(GamepadEvents_t::ButtonFaceX)];
      command->Execute(id);
      break;
    }
    case GamepadButton_t::ButtonFaceY: {
      auto command = commands_Gamepad[EnumCast(GamepadEvents_t::ButtonFaceY)];
      command->Execute(id);
      break;
    }
    case GamepadButton_t::ButtonShoulderLeft: {
      auto command =
        commands_Gamepad[EnumCast(GamepadEvents_t::ButtonShoulderLeft)];
      command->Execute(id);
      break;
    }
    case GamepadButton_t::ButtonShoulderRight: {
      auto command =
        commands_Gamepad[EnumCast(GamepadEvents_t::ButtonShoulderRight)];
      command->Execute(id);
      break;
    }
    case GamepadButton_t::DPadDown: {
      auto command =
        commands_Gamepad[EnumCast(GamepadEvents_t::ButtonShoulderRight)];
      command->Execute(id);
      break;
    }
    case GamepadButton_t::DPadLeft: {
      auto command = commands_Gamepad[EnumCast(GamepadEvents_t::DPadLeft)];
      command->Execute(id);
      break;
    }
    case GamepadButton_t::DPadRight: {
      auto command = commands_Gamepad[EnumCast(GamepadEvents_t::DPadRight)];
      command->Execute(id);
      break;
    }
    case GamepadButton_t::DPadUp: {
      auto command = commands_Gamepad[EnumCast(GamepadEvents_t::DPadUp)];
      command->Execute(id);
      break;
    }
    default: {
      switch (button) {
        case GamepadButton_t::ButtonMenuBack: {
          auto command =
            commands_Gamepad[EnumCast(GamepadEvents_t::ButtonMenuBack)];
          command->Execute(id);
          break;
        }
        case GamepadButton_t::ButtonMenuGuide: {
          auto command =
            commands_Gamepad[EnumCast(GamepadEvents_t::ButtonMenuGuide)];
          command->Execute(id);
          break;
        }
        case GamepadButton_t::ButtonMenuStart: {
          auto command =
            commands_Gamepad[EnumCast(GamepadEvents_t::ButtonMenuStart)];
          command->Execute(id);
          break;
        }
        case GamepadButton_t::ButtonThumbLeft: {
          auto command =
            commands_Gamepad[EnumCast(GamepadEvents_t::ButtonThumbLeft)];
          command->Execute(id);
          break;
        }
        case GamepadButton_t::ButtonThumbRight: {
          auto command =
            commands_Gamepad[EnumCast(GamepadEvents_t::ButtonThumbRight)];
          command->Execute(id);
          break;
        }
      }
    }
  }
}

void
Commander_MainMenu::GamepadButtonUp(
  System::DeviceTypes::IO::GamepadId_t id,
  System::DeviceTypes::IO::GamepadButton_t button)
{}

void
Commander_MainMenu::GamepadDeviceAdd(System::DeviceTypes::IO::GamepadId_t id)
{
  using namespace System::DeviceTypes::IO;

  auto command = commands_Gamepad[EnumCast(GamepadEvents_t::DeviceAdded)];
  command->Execute(id);
}

void
Commander_MainMenu::GamepadDeviceRemove(System::DeviceTypes::IO::GamepadId_t id)
{
  using namespace System::DeviceTypes::IO;

  auto command = commands_Gamepad[EnumCast(GamepadEvents_t::DeviceRemoved)];
  command->Execute(id);
}

void
Commander_MainMenu::KeyboardKeyDown(System::DeviceTypes::IO::Key_t key)
{
  using namespace System::DeviceTypes::IO;

  auto command = commands_Keyboard[EnumCast(key.ScanCode)];
  command->Execute();
}

void
Commander_MainMenu::KeyboardKeyUp(System::DeviceTypes::IO::Key_t key)
{}

auto
Commander_MainMenu::Initialize() -> void
{
  using namespace System::DeviceTypes::IO;

  // Gamepad-to-commands mappings
  commands_Gamepad[EnumCast(GamepadEvents_t::ButtonFaceA)] =
    MakeCommand(Commands_MainMenu_t::Accept);
  commands_Gamepad[EnumCast(GamepadEvents_t::ButtonFaceB)] =
    MakeCommand(Commands_MainMenu_t::Back);
  commands_Gamepad[EnumCast(GamepadEvents_t::ButtonMenuBack)] =
    MakeCommand(Commands_MainMenu_t::Back);
  commands_Gamepad[EnumCast(GamepadEvents_t::StickLeftX_Left)] =
    MakeCommand(Commands_MainMenu_t::MoveLeft);
  commands_Gamepad[EnumCast(GamepadEvents_t::StickLeftX_Right)] =
    MakeCommand(Commands_MainMenu_t::MoveRight);
  commands_Gamepad[EnumCast(GamepadEvents_t::StickLeftY_Down)] =
    MakeCommand(Commands_MainMenu_t::MoveDown);
  commands_Gamepad[EnumCast(GamepadEvents_t::StickLeftY_Up)] =
    MakeCommand(Commands_MainMenu_t::MoveUp);

  // Keyboard-to-commands mapping
  commands_Keyboard[EnumCast(ScanCode_t::Arrow_Down)] =
    MakeCommand(Commands_MainMenu_t::MoveDown);
  commands_Keyboard[EnumCast(ScanCode_t::Arrow_Left)] =
    MakeCommand(Commands_MainMenu_t::MoveLeft);
  commands_Keyboard[EnumCast(ScanCode_t::Arrow_Right)] =
    MakeCommand(Commands_MainMenu_t::MoveRight);
  commands_Keyboard[EnumCast(ScanCode_t::Arrow_Up)] =
    MakeCommand(Commands_MainMenu_t::MoveUp);
  commands_Keyboard[EnumCast(ScanCode_t::SK_Enter)] =
    MakeCommand(Commands_MainMenu_t::Accept);
  commands_Keyboard[EnumCast(ScanCode_t::SK_Backspace)] =
    MakeCommand(Commands_MainMenu_t::Back);
}

std::shared_ptr<Command_Interface>
Commander_MainMenu::MakeCommand(Commands_MainMenu_t commandType)
{
  switch (commandType) {
    case Commands_MainMenu_t::Accept: {
      return std::make_unique<Command_MainMenu_Accept>(mainMenu);
    }
    case Commands_MainMenu_t::Back: {
      return std::make_unique<Command_MainMenu_Back>(mainMenu);
    }
    // case Commands_MainMenu_t::DeviceAdded: {
    //  return std::make_unique<Command_MainMenu_DeviceAdded>(mainMenu);
    //}
    // case Commands_MainMenu_t::DeviceRemoved: {
    //  return std::make_unique<Command_MainMenu_DeviceRemoved>(mainMenu);
    //}
    case Commands_MainMenu_t::MoveDown: {
      return std::make_unique<Command_MainMenu_MoveDown>(mainMenu);
    }
    case Commands_MainMenu_t::MoveLeft: {
      return std::make_unique<Command_MainMenu_MoveLeft>(mainMenu);
    }
    case Commands_MainMenu_t::MoveRight: {
      return std::make_unique<Command_MainMenu_MoveRight>(mainMenu);
    }
    case Commands_MainMenu_t::MoveUp: {
      return std::make_unique<Command_MainMenu_MoveUp>(mainMenu);
    }
    case Commands_MainMenu_t::_NULL_: {
      [[fallthrough]];
    }
    default: {
      return command_Null;
    }
  }
  return std::unique_ptr<Command_Interface>();
}

NAMESPACE_END(GunBox)

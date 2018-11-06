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
  System::DeviceTypes::Input::GamepadId_t id,
  System::DeviceTypes::Input::GamepadAxis_t axis,
  double value) -> void
{
  using namespace System::DeviceTypes::Input;

  auto GetCommand = [this, value](
                      GamepadEvent_t const axisLeftOrUp,
                      GamepadEvent_t const axisRightOrDown) {
    if (0 > value) {
      return this->commands_Gamepad[EnumCast(axisLeftOrUp)];
    } else if (0 < value) {
      return this->commands_Gamepad[EnumCast(axisRightOrDown)];
    } else {
      return this->commands_Gamepad[EnumCast(GamepadEvent_t::_UNKNOWN_)];
    }
  };

  switch (axis) {
    case GamepadAxis_t::StickLeftX: {
      auto command = GetCommand(
        GamepadEvent_t::StickLeftX_Left, GamepadEvent_t::StickLeftX_Right);
      command->Execute(id);
      break;
    }
    case GamepadAxis_t::StickLeftY: {
      auto command = GetCommand(
        GamepadEvent_t::StickLeftY_Up, GamepadEvent_t::StickLeftY_Down);
      command->Execute(id);
      break;
    }
    case GamepadAxis_t::StickRightX: {
      auto command = GetCommand(
        GamepadEvent_t::StickRightX_Left, GamepadEvent_t::StickRightX_Right);
      command->Execute(id);
      break;
    }
    case GamepadAxis_t::StickRightY: {
      auto command = GetCommand(
        GamepadEvent_t::StickRightY_Up, GamepadEvent_t::StickRightY_Down);
      command->Execute(id);
      break;
    }
    case GamepadAxis_t::TriggerLeft: {
      auto command = commands_Gamepad[EnumCast(GamepadEvent_t::TriggerLeft)];
      command->Execute(id);
      break;
    }
    case GamepadAxis_t::TriggerRight: {
      auto command = commands_Gamepad[EnumCast(GamepadEvent_t::TriggerRight)];
      command->Execute(id);
      break;
    }
  }
}

void
Commander_MainMenu::GamepadButtonDown(
  System::DeviceTypes::Input::GamepadId_t id,
  System::DeviceTypes::Input::GamepadButton_t button)
{
  using namespace System::DeviceTypes::Input;

  switch (button) {
    case GamepadButton_t::ButtonFaceA: {
      auto command = commands_Gamepad[EnumCast(GamepadEvent_t::ButtonFaceA)];
      command->Execute(id);
      break;
    }
    case GamepadButton_t::ButtonFaceB: {
      auto command = commands_Gamepad[EnumCast(GamepadEvent_t::ButtonFaceB)];
      command->Execute(id);
      break;
    }
    case GamepadButton_t::ButtonFaceX: {
      auto command = commands_Gamepad[EnumCast(GamepadEvent_t::ButtonFaceX)];
      command->Execute(id);
      break;
    }
    case GamepadButton_t::ButtonFaceY: {
      auto command = commands_Gamepad[EnumCast(GamepadEvent_t::ButtonFaceY)];
      command->Execute(id);
      break;
    }
    case GamepadButton_t::ButtonShoulderLeft: {
      auto command =
        commands_Gamepad[EnumCast(GamepadEvent_t::ButtonShoulderLeft)];
      command->Execute(id);
      break;
    }
    case GamepadButton_t::ButtonShoulderRight: {
      auto command =
        commands_Gamepad[EnumCast(GamepadEvent_t::ButtonShoulderRight)];
      command->Execute(id);
      break;
    }
    case GamepadButton_t::DPadDown: {
      auto command =
        commands_Gamepad[EnumCast(GamepadEvent_t::ButtonShoulderRight)];
      command->Execute(id);
      break;
    }
    case GamepadButton_t::DPadLeft: {
      auto command = commands_Gamepad[EnumCast(GamepadEvent_t::DPadLeft)];
      command->Execute(id);
      break;
    }
    case GamepadButton_t::DPadRight: {
      auto command = commands_Gamepad[EnumCast(GamepadEvent_t::DPadRight)];
      command->Execute(id);
      break;
    }
    case GamepadButton_t::DPadUp: {
      auto command = commands_Gamepad[EnumCast(GamepadEvent_t::DPadUp)];
      command->Execute(id);
      break;
    }
    default: {
      switch (button) {
        case GamepadButton_t::ButtonMenuBack: {
          auto command =
            commands_Gamepad[EnumCast(GamepadEvent_t::ButtonMenuBack)];
          command->Execute(id);
          break;
        }
        case GamepadButton_t::ButtonMenuGuide: {
          auto command =
            commands_Gamepad[EnumCast(GamepadEvent_t::ButtonMenuGuide)];
          command->Execute(id);
          break;
        }
        case GamepadButton_t::ButtonMenuStart: {
          auto command =
            commands_Gamepad[EnumCast(GamepadEvent_t::ButtonMenuStart)];
          command->Execute(id);
          break;
        }
        case GamepadButton_t::ButtonThumbLeft: {
          auto command =
            commands_Gamepad[EnumCast(GamepadEvent_t::ButtonThumbLeft)];
          command->Execute(id);
          break;
        }
        case GamepadButton_t::ButtonThumbRight: {
          auto command =
            commands_Gamepad[EnumCast(GamepadEvent_t::ButtonThumbRight)];
          command->Execute(id);
          break;
        }
      }
    }
  }
}

void
Commander_MainMenu::GamepadButtonUp(
  System::DeviceTypes::Input::GamepadId_t id,
  System::DeviceTypes::Input::GamepadButton_t button)
{}

void
Commander_MainMenu::GamepadDeviceAdd(System::DeviceTypes::Input::GamepadId_t id)
{
  using namespace System::DeviceTypes::Input;

  auto command = commands_Gamepad[EnumCast(GamepadEvent_t::DeviceAdded)];
  command->Execute(id);
}

void
Commander_MainMenu::GamepadDeviceRemove(
  System::DeviceTypes::Input::GamepadId_t id)
{
  using namespace System::DeviceTypes::Input;

  auto command = commands_Gamepad[EnumCast(GamepadEvent_t::DeviceRemoved)];
  command->Execute(id);
}

void
Commander_MainMenu::KeyboardKeyDown(System::DeviceTypes::Input::Key_t key)
{
  using namespace System::DeviceTypes::Input;

  auto command = commands_Keyboard[EnumCast(key.ScanCode)];
  command->Execute();
}

void
Commander_MainMenu::KeyboardKeyUp(System::DeviceTypes::Input::Key_t key)
{}

auto
Commander_MainMenu::Initialize() -> void
{
  using namespace System::DeviceTypes::Input;

  // Gamepad-to-commands mappings
  commands_Gamepad[EnumCast(GamepadEvent_t::ButtonFaceA)] =
    MakeCommand(Commands_MainMenu_t::Accept);
  commands_Gamepad[EnumCast(GamepadEvent_t::ButtonFaceB)] =
    MakeCommand(Commands_MainMenu_t::Back);
  commands_Gamepad[EnumCast(GamepadEvent_t::ButtonMenuBack)] =
    MakeCommand(Commands_MainMenu_t::Back);
  commands_Gamepad[EnumCast(GamepadEvent_t::StickLeftX_Left)] =
    MakeCommand(Commands_MainMenu_t::MoveLeft);
  commands_Gamepad[EnumCast(GamepadEvent_t::StickLeftX_Right)] =
    MakeCommand(Commands_MainMenu_t::MoveRight);
  commands_Gamepad[EnumCast(GamepadEvent_t::StickLeftY_Down)] =
    MakeCommand(Commands_MainMenu_t::MoveDown);
  commands_Gamepad[EnumCast(GamepadEvent_t::StickLeftY_Up)] =
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

// Self
#include "MainMenu_Commander.hpp"

// Project headers
#include "EventHandling/Commands/Command_Null.hpp"
#include "EventHandling/Commands/MainMenu/Command_MainMenu_Accept.hpp"
#include "EventHandling/Commands/MainMenu/Command_MainMenu_Back.hpp"
#include "EventHandling/Commands/MainMenu/Command_MainMenu_MoveDown.hpp"
#include "EventHandling/Commands/MainMenu/Command_MainMenu_MoveLeft.hpp"
#include "EventHandling/Commands/MainMenu/Command_MainMenu_MoveRight.hpp"
#include "EventHandling/Commands/MainMenu/Command_MainMenu_MoveUp.hpp"

NAMESPACE_BEGIN(GunBox)

MainMenu_Commander::MainMenu_Commander(MainMenu& mainMenu)
  : mainMenu{ mainMenu }
  , commands{ std::make_shared<Command_Null>() }
{}

MainMenu_Commander::~MainMenu_Commander() {}

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
      return this->commands[EnumCast(GamepadEvents_t::_UNKNOWN_)];
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
      auto command = commands[EnumCast(GamepadEvents_t::TriggerLeft)];
      command->Execute(id);
      break;
    }
    case GamepadAxis_t::TriggerRight: {
      auto command = commands[EnumCast(GamepadEvents_t::TriggerRight)];
      command->Execute(id);
      break;
    }
  }
}

void
MainMenu_Commander::GamepadButtonDown(
  System::DeviceTypes::IO::GamepadId_t id,
  System::DeviceTypes::IO::GamepadButton_t button)
{
  using namespace System::DeviceTypes::IO;

  auto command = commands[EnumCast(GamepadEvents_t::TriggerRight)];
  command->Execute(id);
}

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

auto
MainMenu_Commander::Initialize() -> void
{
  using namespace System::DeviceTypes::IO;

  commands[EnumCast(GamepadEvents_t::ButtonFaceA)] =
    MakeCommand(Commands_MainMenu_t::Accept);
  commands[EnumCast(GamepadEvents_t::ButtonFaceB)] =
    MakeCommand(Commands_MainMenu_t::Back);
  commands[EnumCast(GamepadEvents_t::ButtonMenuBack)] =
    MakeCommand(Commands_MainMenu_t::Back);
  commands[EnumCast(GamepadEvents_t::StickLeftX_Left)] =
    MakeCommand(Commands_MainMenu_t::MoveLeft);
  commands[EnumCast(GamepadEvents_t::StickLeftX_Right)] =
    MakeCommand(Commands_MainMenu_t::MoveRight);
  commands[EnumCast(GamepadEvents_t::StickLeftY_Down)] =
    MakeCommand(Commands_MainMenu_t::MoveDown);
  commands[EnumCast(GamepadEvents_t::StickLeftY_Up)] =
    MakeCommand(Commands_MainMenu_t::MoveUp);
}

std::unique_ptr<Command_Interface>
MainMenu_Commander::MakeCommand(Commands_MainMenu_t commandType)
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
      return std::make_unique<Command_Null>();
    }
  }
  return std::unique_ptr<Command_Interface>();
}

NAMESPACE_END(GunBox)

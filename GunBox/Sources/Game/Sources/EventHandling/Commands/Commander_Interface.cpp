// Self
#include "Commander_Interface.hpp"

NAMESPACE_BEGIN(GunBox)

Commander_Interface::~Commander_Interface() {}

NAMESPACE_END(GunBox)

// class MainMenu;
// class MainMenu_Commander
//{
//  enum class MenuCommand_t
//  {
//    MoveUp,
//    MoveDown,
//    MoveLeft,
//    MoveRight,
//    Accept,
//    Reject
//  };
//
// void InitializeCommand(
//  MenuCommand_t menuCommandType,
//  GamepadButton_t gamepadButton)
//{
//  commands[gamepadButton] = makeCommand(menuCommandType);
//}
// MainMenu_Commander(MainMenu& mainMenu);
// std::vector<Command> commands;
// auto InitializeCommands() -> void
//{
//  commands.resize(GamepadButtonsCount);
//  InitializeCommand(MenuCommand_t::Accept, GamepadButton_t::A);
//  InitializeCommand(MenuCommand_t::MoveDown, GamepadButton_t::DPadDown);
//  InitializeCommand(MenuCommand_t::MoveDown, GamepadAxis_t::AxisLeftY);
//}
// unique_ptr<Command> makeCommand(commandType)
//{
//  switch (commandType) {
//    case moveUp:
//      return make_unique<Command_MoveUp>(mainMenu);
//  }

//  auto GamePadButton(int b)->void
//  {
//    if (b == 1) {
//      mainMenu.MoveUp();
//    }
//    Gamepad[button] =
//  }
//};

// Commands[button] = &make_moveUp;

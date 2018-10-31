// Self
#include "Command_MainMenu_MoveDown.hpp"

NAMESPACE_BEGIN(GunBox)

Command_MainMenu_MoveDown::Command_MainMenu_MoveDown(MainMenu& mainMenu)
  : mainMenu(mainMenu)
{}

Command_MainMenu_MoveDown::~Command_MainMenu_MoveDown() {}

void
Command_MainMenu_MoveDown::Execute(std::int32_t id)
{}

NAMESPACE_END(GunBox)

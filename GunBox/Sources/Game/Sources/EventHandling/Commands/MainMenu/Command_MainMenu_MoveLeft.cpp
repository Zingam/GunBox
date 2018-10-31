// Self
#include "Command_MainMenu_MoveLeft.hpp"

NAMESPACE_BEGIN(GunBox)

Command_MainMenu_MoveLeft::Command_MainMenu_MoveLeft(MainMenu& mainMenu)
  : mainMenu(mainMenu)
{}

Command_MainMenu_MoveLeft::~Command_MainMenu_MoveLeft() {}

void
Command_MainMenu_MoveLeft::Execute(std::int32_t id)
{}

NAMESPACE_END(GunBox)

// Self
#include "Command_MainMenu_MoveDown.hpp"

// Project headers
#include "GameStates/MainMenu.hpp"

NAMESPACE_BEGIN(GunBox)

Command_MainMenu_MoveDown::Command_MainMenu_MoveDown(MainMenu& mainMenu)
  : mainMenu(mainMenu)
{}

Command_MainMenu_MoveDown::~Command_MainMenu_MoveDown() {}

void
Command_MainMenu_MoveDown::Execute(std::any const value)
{
  mainMenu.MoveDown();
}

NAMESPACE_END(GunBox)

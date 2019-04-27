// Self
#include "Command_MainMenu_Back.hpp"

// Project headers
#include "GameStates/MainMenu.hpp"

NAMESPACE_BEGIN(GunBox)

Command_MainMenu_Back::Command_MainMenu_Back(MainMenu& mainMenu)
  : mainMenu(mainMenu)
{}

Command_MainMenu_Back::~Command_MainMenu_Back() {}

void
Command_MainMenu_Back::Execute(std::any const value)
{
  mainMenu.Back();
}

NAMESPACE_END(GunBox)

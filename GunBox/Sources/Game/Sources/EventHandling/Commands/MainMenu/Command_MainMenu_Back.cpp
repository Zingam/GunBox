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
Command_MainMenu_Back::Execute(std::int32_t id)
{
  mainMenu.Back();
}

NAMESPACE_END(GunBox)

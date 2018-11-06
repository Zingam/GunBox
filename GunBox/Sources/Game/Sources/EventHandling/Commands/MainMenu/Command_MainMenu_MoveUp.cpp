// Self
#include "Command_MainMenu_MoveUp.hpp"

// Project headers
#include "GameStates/MainMenu.hpp"

NAMESPACE_BEGIN(GunBox)

Command_MainMenu_MoveUp::Command_MainMenu_MoveUp(MainMenu& mainMenu)
  : mainMenu(mainMenu)
{}

Command_MainMenu_MoveUp::~Command_MainMenu_MoveUp() {}

void
Command_MainMenu_MoveUp::Execute(std::int32_t id)
{
  mainMenu.MoveUp();
}

NAMESPACE_END(GunBox)

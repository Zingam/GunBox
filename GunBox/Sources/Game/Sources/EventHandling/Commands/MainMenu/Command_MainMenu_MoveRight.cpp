// Self
#include "Command_MainMenu_MoveRight.hpp"

// Project headers
#include "GameStates/MainMenu.hpp"

// C++ Standard Library
#include <any>

NAMESPACE_BEGIN(GunBox)

Command_MainMenu_MoveRight::Command_MainMenu_MoveRight(MainMenu& mainMenu)
  : mainMenu(mainMenu)
{}

Command_MainMenu_MoveRight::~Command_MainMenu_MoveRight() {}

void
Command_MainMenu_MoveRight::Execute(std::any const& value)
{
  mainMenu.MoveRight();
}

NAMESPACE_END(GunBox)

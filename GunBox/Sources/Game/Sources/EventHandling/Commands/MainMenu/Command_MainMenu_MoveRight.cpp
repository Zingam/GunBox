// Self
#include "Command_MainMenu_MoveRight.hpp"

NAMESPACE_BEGIN(GunBox)

Command_MainMenu_MoveRight::Command_MainMenu_MoveRight(MainMenu& mainMenu)
  : mainMenu(mainMenu)
{}

Command_MainMenu_MoveRight::~Command_MainMenu_MoveRight() {}

void
Command_MainMenu_MoveRight::Execute(std::int32_t id)
{}

NAMESPACE_END(GunBox)

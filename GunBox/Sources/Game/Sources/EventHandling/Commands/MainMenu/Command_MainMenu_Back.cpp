// Self
#include "Command_MainMenu_Back.hpp"

NAMESPACE_BEGIN(GunBox)

Command_MainMenu_Back::Command_MainMenu_Back(MainMenu& mainMenu)
  : mainMenu(mainMenu)
{}

Command_MainMenu_Back::~Command_MainMenu_Back() {}

void
Command_MainMenu_Back::Execute(std::int32_t id)
{}

NAMESPACE_END(GunBox)

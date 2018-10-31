// Self
#include "Command_MainMenu_MoveUp.hpp"

NAMESPACE_BEGIN(GunBox)

Command_MainMenu_MoveUp::Command_MainMenu_MoveUp(MainMenu& mainMenu)
  : mainMenu(mainMenu)
{}

Command_MainMenu_MoveUp::~Command_MainMenu_MoveUp() {}

void
Command_MainMenu_MoveUp::Execute(std::int32_t id)
{}

NAMESPACE_END(GunBox)

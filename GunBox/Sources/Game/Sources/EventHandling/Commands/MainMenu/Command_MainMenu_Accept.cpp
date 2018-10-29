// Self
#include "Command_MainMenu_Accept.hpp"

NAMESPACE_BEGIN(GunBox)

Command_MainMenu_Accept::Command_MainMenu_Accept(MainMenu& mainMenu)
  : mainMenu(mainMenu)
{}

Command_MainMenu_Accept::~Command_MainMenu_Accept() {}

void
Command_MainMenu_Accept::Execute()
{}

NAMESPACE_END(GunBox)

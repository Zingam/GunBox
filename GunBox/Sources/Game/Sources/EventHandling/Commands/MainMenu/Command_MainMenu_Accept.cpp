// Self
#include "Command_MainMenu_Accept.hpp"

NAMESPACE_BEGIN(GunBox)

Command_MainMenu_Accept::Command_MainMenu_Accept(MainMenu& mainMenu)
  : mainMenu(mainMenu)
{}

Command_MainMenu_Accept::~Command_MainMenu_Accept() {}

void
Command_MainMenu_Accept::Execute(std::int32_t id)
{}

NAMESPACE_END(GunBox)

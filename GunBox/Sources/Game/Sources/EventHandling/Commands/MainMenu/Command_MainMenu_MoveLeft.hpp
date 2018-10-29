#pragma once

// BASE MACROS header
#include "Common/Macros/Base.hpp"

// Project headers
#include "EventHandling/Commands/Command_Interface.hpp"

////////////////////////////////////////////////////////////////////////////////
// Forward declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(GunBox)

class MainMenu;

NAMESPACE_END(GunBox)

////////////////////////////////////////////////////////////////////////////////
// Class declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(GunBox)

class Command_MainMenu_MoveLeft final : public Command_Interface
{
public:
  Command_MainMenu_MoveLeft(MainMenu& mainMenu);
  ~Command_MainMenu_MoveLeft() final;

public:
  auto Execute() -> void final;

private:
  MainMenu& mainMenu;
};

NAMESPACE_END(GunBox)

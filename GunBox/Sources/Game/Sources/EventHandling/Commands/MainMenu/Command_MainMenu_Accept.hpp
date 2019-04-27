#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

// Project headers
#include "EventHandling/Commands/Command_Interface.hpp"

// C++ Standard Library
#include <any>

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

class Command_MainMenu_Accept final : public Command_Interface
{
public:
  Command_MainMenu_Accept(MainMenu& mainMenu);
  ~Command_MainMenu_Accept() final;

public:
  auto Execute(std::any const value) -> void final;

private:
  MainMenu& mainMenu;
};

NAMESPACE_END(GunBox)

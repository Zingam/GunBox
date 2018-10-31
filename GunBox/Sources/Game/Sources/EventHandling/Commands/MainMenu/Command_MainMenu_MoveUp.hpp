#pragma once

// BASE MACROS header
#include "Common/Macros/Base.hpp"

// Project headers
#include "EventHandling/Commands/Command_Interface.hpp"

// C Standard Library
#include <cstdint>

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

class Command_MainMenu_MoveUp final : public Command_Interface
{
public:
  Command_MainMenu_MoveUp(MainMenu& mainMenu);
  ~Command_MainMenu_MoveUp() final;

public:
  auto Execute(std::int32_t id) -> void final;

private:
  MainMenu& mainMenu;
};

NAMESPACE_END(GunBox)

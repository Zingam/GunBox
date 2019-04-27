// Self
#include "Command_UpdateApplicationState.hpp"

// Project headers
#include "GameStates/GameState.hpp"

// Engine headers - Application
#include "Application/ApplicationState.hpp"

NAMESPACE_BEGIN(GunBox)

////////////////////////////////////////////////////////////////////////////////
// Constructors & Destructors
////////////////////////////////////////////////////////////////////////////////

Command_UpdateApplicationState::Command_UpdateApplicationState(
  GameState& gameState)
  : gameState{ gameState }
{}

Command_UpdateApplicationState::~Command_UpdateApplicationState() = default;

////////////////////////////////////////////////////////////////////////////////
// Virtual methods
////////////////////////////////////////////////////////////////////////////////

void
Command_UpdateApplicationState::Execute(std::any const value)
{
  gameState.SetApplicationState(std::any_cast<Application::State_t>(value));
}

NAMESPACE_END(GunBox)

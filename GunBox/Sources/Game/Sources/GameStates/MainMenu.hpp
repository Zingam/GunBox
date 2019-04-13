#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

// Project headers
#include "GameStates/GameState.hpp"
#include "GameStates/GameStateTypes.hpp"

// Enigne headers - System
#include "System/EventProcessing/InputEventProcessor.hpp"

// C++ Standard Library
#include <memory>

////////////////////////////////////////////////////////////////////////////////
// Forward declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(Renderer::Graphics)

class GraphicsRenderer_Interface;

NAMESPACE_END(Renderer::Graphics)

////////////////////////////////////////////////////////////////////////////////
// Class declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(GunBox)

class MainMenu : public GameState
{
  // Constructors & Destructors
public:
  MainMenu(
    System::EventProcessing::InputEventProcessor const& inputEventProcessor);

  // Methods
public:
  auto Update() -> GameState_t;

  // Command actions
public:
  auto Accept() -> void;
  auto Back() -> void;
  auto MoveDown() -> void;
  auto MoveLeft() -> void;
  auto MoveRight() -> void;
  auto MoveUp() -> void;
  auto Quit() -> void;

  // Fields
private:
  bool isQuitting = false;
  bool isRequestingToQuit = false;
  GameState_t nextGameState = GameState_t::MainMenu;
};

NAMESPACE_END(GunBox)

#pragma once

// BASE MACROS header
#include "Common/Macros/Base.hpp"

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

class InGame : public GameState
{
  // Constructors & Destructors
public:
  InGame(
    System::EventProcessing::InputEventProcessor const& inputEventProcessor);

  // Methods
public:
  auto Update() -> GameState_t;

  // Fields
private:
  bool isQuitting = false;
  GameState_t nextGameState = GameState_t::InGame;
};

NAMESPACE_END(GunBox)

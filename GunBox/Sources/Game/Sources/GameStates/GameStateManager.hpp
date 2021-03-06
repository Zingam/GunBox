#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

// Project headers
#include "EventHandling/InputEventCallbacks.hpp"
#include "EventHandling/SystemEventCallbacks.hpp"
#include "GameStates/GameStateTypes.hpp"
#include "GameStates/InGame.hpp"
#include "GameStates/MainMenu.hpp"

////////////////////////////////////////////////////////////////////////////////
// Forward declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(Renderer::Graphics)

class GraphicsRenderer_Interface;

NAMESPACE_END(Renderer::Graphics)

NAMESPACE_BEGIN(System::EventProcessing)

class InputEventProcessor;

NAMESPACE_END(System::EventProcessing)

////////////////////////////////////////////////////////////////////////////////
// Class declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(GunBox)

class GameStateManager
{
  // Constructors & Destructors
public:
  GameStateManager(
    System::EventProcessing::InputEventProcessor const& inputEventProcessor);

public:
  GameStateManager(GameStateManager const&) = delete;

  // Methods
public:
  auto Initialize(
    std::shared_ptr<Renderer::Graphics::GraphicsRenderer_Interface>
      graphicsRenderer) -> void;
  auto Run() -> bool;

  // Properties
public:
  auto GetInputEventCallbacks() -> InputEventCallbacks&;
  auto GetSystemEventCallbacks() -> SystemEventCallbacks&;

  // Data members - GameStates
private:
  InGame inGame;
  MainMenu mainMenu;

  // Data members - Callbacks
private:
  InputEventCallbacks inputEventCallbacks;
  SystemEventCallbacks systemEventCallbacks;

  // Data members
private:
  GameState_t gameState = GameState_t::MainMenu;
  std::shared_ptr<Renderer::Graphics::GraphicsRenderer_Interface>
    graphicsRenderer;
  bool isStateInitialized = false;
};

NAMESPACE_END(GunBox)

#pragma once

// BASE MACROS header
#include "Common/Macros/Base.hpp"

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

private:
  GameState_t gameState = GameState_t::MainMenu;
  std::shared_ptr<Renderer::Graphics::GraphicsRenderer_Interface>
    graphicsRenderer;
  InGame inGame;
  MainMenu mainMenu;
  InputEventCallbacks inputEventCallbacks;
  bool isStateInitialized = false;
  SystemEventCallbacks systemEventCallbacks;
};

NAMESPACE_END(GunBox)

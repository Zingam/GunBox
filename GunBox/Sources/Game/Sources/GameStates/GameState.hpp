#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

// Project headers
#include "GameStates/GameStateTypes.hpp"

// Engine headers - Application
#include "Application/ApplicationState.hpp"

// C++ Standard Library
#include <memory>

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

class GameState
{
  // Constructors & Destructors
protected:
  GameState(
    System::EventProcessing::InputEventProcessor const& inputEventProcessor);

  // Properties
public:
  auto SetApplicationState(Application::State_t applicationState) -> void;

  // Methods
public:
  auto Initialize(
    std::shared_ptr<Renderer::Graphics::GraphicsRenderer_Interface>
      graphicsRenderer) -> void;

  // Data members - variables
protected:
  Application::State_t applicationState = Application::State_t::NotRunning;
  std::shared_ptr<Renderer::Graphics::GraphicsRenderer_Interface>
    graphicsRenderer;
  System::EventProcessing::InputEventProcessor const& inputEventProcessor;
};

NAMESPACE_END(GunBox)

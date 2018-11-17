#pragma once

// BASE MACROS header
#include "Common/Macros/Base.hpp"

// Project headers
#include "GameStates/GameStateTypes.hpp"

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

  // Methods
public:
  auto Initialize(
    std::shared_ptr<Renderer::Graphics::GraphicsRenderer_Interface>
      graphicsRenderer) -> void;

  // Fields
protected:
  std::shared_ptr<Renderer::Graphics::GraphicsRenderer_Interface>
    graphicsRenderer;
  System::EventProcessing::InputEventProcessor const& inputEventProcessor;
};

NAMESPACE_END(GunBox)

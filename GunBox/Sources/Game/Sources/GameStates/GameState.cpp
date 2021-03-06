// Self
#include "GameState.hpp"

// Engine headers - System
#include "System/EventProcessing/InputEventProcessor.hpp"

NAMESPACE_BEGIN(GunBox)

////////////////////////////////////////////////////////////////////////////////
// Constructors & Destructors
////////////////////////////////////////////////////////////////////////////////

GameState::GameState(
  System::EventProcessing::InputEventProcessor const& inputEventProcessor)
  : inputEventProcessor{ inputEventProcessor }
{}

////////////////////////////////////////////////////////////////////////////////
// Properties
////////////////////////////////////////////////////////////////////////////////

void
GameState::SetApplicationState(Application::State_t applicationState)
{
  this->applicationState = applicationState;
}

////////////////////////////////////////////////////////////////////////////////
// Methods
////////////////////////////////////////////////////////////////////////////////

void
GameState::Initialize(
  std::shared_ptr<Renderer::Graphics::GraphicsRenderer_Interface>
    graphicsRenderer)
{
  this->graphicsRenderer = graphicsRenderer;
}

NAMESPACE_END(GunBox)

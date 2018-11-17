// Self
#include "GameState.hpp"

// Engine headers - System
#include "System/EventProcessing/InputEventProcessor.hpp"

NAMESPACE_BEGIN(GunBox)

GameState::GameState(
  System::EventProcessing::InputEventProcessor const& inputEventProcessor)
  : inputEventProcessor{ inputEventProcessor }
{}

void
GameState::Initialize(
  std::shared_ptr<Renderer::Graphics::GraphicsRenderer_Interface>
    graphicsRenderer)
{
  this->graphicsRenderer = graphicsRenderer;
}

NAMESPACE_END(GunBox)

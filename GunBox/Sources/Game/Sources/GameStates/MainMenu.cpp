// Self
#include "MainMenu.hpp"

NAMESPACE_BEGIN(GunBox)

void
MainMenu::Initialize(
  std::shared_ptr<Renderer::Graphics::GraphicsRenderer_Interface>
    graphicsRenderer)
{
  this->graphicsRenderer = graphicsRenderer;
}

GameState_t
MainMenu::Update()
{
  if (isQuitting) {
    return GameState_t::Quit;
  } else {
    return GameState_t::MainMenu;
  }
};

NAMESPACE_END(GunBox)

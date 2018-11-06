// Self
#include "MainMenu.hpp"

#include <iostream>

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
}

////////////////////////////////////////////////////////////////////////////////
// Command actions
////////////////////////////////////////////////////////////////////////////////

void
MainMenu::Accept(){};

void
MainMenu::Back()
{
  if (isRequestingToQuit) {
    std::cout << "Quit canceled!\n";

    isRequestingToQuit = false;
    isQuitting = false;
  }
}

void
MainMenu::MoveDown()
{
  std::cout << "  MainMenu > Move down" << std::endl;
}

void
MainMenu::MoveLeft()
{
  std::cout << "  MainMenu > Move left" << std::endl;
}

void
MainMenu::MoveRight()
{
  std::cout << "  MainMenu > Move right" << std::endl;
}

void
MainMenu::MoveUp()
{
  std::cout << "  MainMenu > Move up" << std::endl;
};

void
MainMenu::Quit()
{
  if (isRequestingToQuit) {
    std::cout << "Quitting GunBox!\n";
    isQuitting = true;
  } else {
    std::cout << "Quit GunBox?\n";
    isRequestingToQuit = true;
  }
};

NAMESPACE_END(GunBox)

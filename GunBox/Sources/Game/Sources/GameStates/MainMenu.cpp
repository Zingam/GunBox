// Self
#include "MainMenu.hpp"

// Engine headers - Renderer
#include "Renderer/Graphics/GraphicsRenderer_Interface.hpp"

// Engine headers - System
#include "System/DeviceTypes/Input/KeyboardTypes.hpp"

#include <iostream>

NAMESPACE_BEGIN(GunBox)

////////////////////////////////////////////////////////////////////////////////
// Constructors & Destructors
////////////////////////////////////////////////////////////////////////////////

MainMenu::MainMenu(
  System::EventProcessing::InputEventProcessor const& inputEventProcessor)
  : GameState{ inputEventProcessor }
{}

////////////////////////////////////////////////////////////////////////////////
// Public Methods
////////////////////////////////////////////////////////////////////////////////

GameState_t
MainMenu::Update()
{
  using namespace System::DeviceTypes::Input;
  using namespace System::EventProcessing;

  static auto i = 0ll;
  auto arrow_UpState =
    inputEventProcessor.KeyboardKeyState(ScanCode_t::Arrow_Up);
  if (KeyboardState::KeyState_t::Pressed == arrow_UpState) {
    std::cout << "Arrow up is pressed " << ++i << "\n";
  }

  graphicsRenderer->Render();

  if (isQuitting) {
    return GameState_t::Quit;
  } else {
    return nextGameState;
  }
}

////////////////////////////////////////////////////////////////////////////////
// Command actions
////////////////////////////////////////////////////////////////////////////////

void
MainMenu::Accept()
{
  nextGameState = GameState_t::InGame;
};

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

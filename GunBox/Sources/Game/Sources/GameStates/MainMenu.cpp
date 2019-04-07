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

  auto specialKey_Escape =
    inputEventProcessor.KeyboardKeyState(ScanCode_t::SK_Esc);
  static auto wasPressed_SpecailKey_Escape = false;
  if (!wasPressed_SpecailKey_Escape) {
    if (KeyboardState::KeyState_t::Pressed == specialKey_Escape) {
      wasPressed_SpecailKey_Escape = true;
    }
  } else {
    if (KeyboardState::KeyState_t::Released == specialKey_Escape) {
      wasPressed_SpecailKey_Escape = false;

      Back();
    }
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
  Quit();
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

// Self
#include "MainMenu.hpp"

// Engine headers - Logger
#include <Logger/LogAPI.hpp>
// Engine headers - Renderer
#include "Renderer/Graphics/GraphicsRenderer_Interface.hpp"
// Engine headers - System
#include "System/DeviceTypes/Input/KeyboardTypes.hpp"

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
  if (Application::State_t ::Suspending == applicationState)
  {
    return nextGameState;
  }

  using namespace System::DeviceTypes::Input;
  using namespace System::EventProcessing;

  auto specialKey_Escape =
    inputEventProcessor.KeyboardKeyState(ScanCode_t::SK_Esc);
  static auto wasPressed_SpecialKey_Escape = false;
  if (!wasPressed_SpecialKey_Escape) {
    if (KeyboardState::KeyState_t::Pressed == specialKey_Escape) {
      wasPressed_SpecialKey_Escape = true;
    }
  } else {
    if (KeyboardState::KeyState_t::Released == specialKey_Escape) {
      wasPressed_SpecialKey_Escape = false;

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
    reLog("Quit canceled!");

    isRequestingToQuit = false;
    isQuitting = false;
  }
}

void
MainMenu::MoveDown()
{
  reLog("  MainMenu > Move down");
}

void
MainMenu::MoveLeft()
{
  reLog("  MainMenu > Move left");
}

void
MainMenu::MoveRight()
{
  reLog("  MainMenu > Move right");
}

void
MainMenu::MoveUp()
{
  reLog("  MainMenu > Move up");
};

void
MainMenu::Quit()
{
  if (isRequestingToQuit) {
    reLog("Quitting GunBox!");
    isQuitting = true;
  } else {
    reLog("Quit GunBox?");
    isRequestingToQuit = true;
  }
};

NAMESPACE_END(GunBox)

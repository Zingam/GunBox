// Self
#include "InGame.hpp"

// Engine headers - Logger
#include "Logger/LogAPI.hpp"
// Engine headers - Renderer
#include "Renderer/Graphics/GraphicsRenderer_Interface.hpp"
// Engine headers - System
#include "System/DeviceTypes/Input/KeyboardTypes.hpp"

NAMESPACE_BEGIN(GunBox)

////////////////////////////////////////////////////////////////////////////////
// Constructors & Destructors
////////////////////////////////////////////////////////////////////////////////

InGame::InGame(
  System::EventProcessing::InputEventProcessor const& inputEventProcessor)
  : GameState{ inputEventProcessor }
{}

////////////////////////////////////////////////////////////////////////////////
// Public Methods
////////////////////////////////////////////////////////////////////////////////

GameState_t
InGame::Update()
{
  using namespace System::DeviceTypes::Input;
  using namespace System::EventProcessing;

  auto arrow_DownState =
    inputEventProcessor.KeyboardKeyState(ScanCode_t::Arrow_Down);
  if (KeyboardState::KeyState_t::Pressed == arrow_DownState) {
    nextGameState = GameState_t::MainMenu;
  }

  static auto i = 0ll;
  auto arrow_UpState =
    inputEventProcessor.KeyboardKeyState(ScanCode_t::Arrow_Up);
  if (KeyboardState::KeyState_t::Pressed == arrow_UpState) {
    reLog("Arrow up is pressed ", ++i);
  }
  
  if (isQuitting) {
    return GameState_t::Quit;
  } else {
    return nextGameState;
  }
}

NAMESPACE_END(GunBox)

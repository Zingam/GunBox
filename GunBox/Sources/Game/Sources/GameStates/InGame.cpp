// Self
#include "InGame.hpp"

// Engine headers - System
#include "System/DeviceTypes/Input/KeyboardTypes.hpp"

#include <iostream>

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

  static auto i = 0ll;
  auto arrow_UpState =
    inputEventProcessor.KeyboardKeyState(ScanCode_t::Arrow_Up);
  if (KeyboardState::KeyState_t::Pressed == arrow_UpState) {
    std::cout << "Arrow up is pressed " << ++i << "\n";
  }

  if (isQuitting) {
    return GameState_t::Quit;
  } else {
    return GameState_t::MainMenu;
  }
}

NAMESPACE_END(GunBox)

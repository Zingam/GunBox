#pragma once

////////////////////////////////////////////////////////////////////////////////
// Inline method implementations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(System::EventProcessing)

void
KeyboardStateAccessor::SetKeyboardState(
  KeyboardState& keyboardState,
  System::DeviceTypes::Input::ScanCode_t scancode,
  KeyboardState::KeyState_t keyState)
{
  keyboardState.SetKeyState(scancode, keyState);
}

NAMESPACE_END(System::EventProcessing)

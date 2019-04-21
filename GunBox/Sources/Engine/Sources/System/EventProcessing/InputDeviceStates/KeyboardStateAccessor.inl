#pragma once

////////////////////////////////////////////////////////////////////////////////
// Inline implementations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(System::EventProcessing)

inline void
KeyboardStateAccessor::SetKeyboardState(
  KeyboardState& keyboardState,
  System::DeviceTypes::Input::ScanCode_t scancode,
  KeyboardState::KeyState_t keyState)
{
  keyboardState.SetKeyState(scancode, keyState);
}

NAMESPACE_END(System::EventProcessing)

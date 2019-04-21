#pragma once

////////////////////////////////////////////////////////////////////////////////
// Inline implementations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(System::EventProcessing)

inline KeyboardState::KeyState_t const
KeyboardState::GetKeyState(
  System::DeviceTypes::Input::ScanCode_t scanCode) const
{
  return keyStates[EnumCast(scanCode)];
}

void
inline KeyboardState::SetKeyState(
  System::DeviceTypes::Input::ScanCode_t scanCode,
  KeyboardState::KeyState_t keyState)
{
  keyStates[EnumCast(scanCode)] = keyState;
}

NAMESPACE_END(System::EventProcessing)

#pragma once

// C Standard Library
#include "GamepadStateAccessor.hpp"
#include <cassert>

////////////////////////////////////////////////////////////////////////////////
// Inline implementations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(System::EventProcessing)

inline void
GamepadStateAccessor::SetAxisState(
  GamepadState& gamepadState,
  System::DeviceTypes::Input::GamepadAxis_t gamepadAxis,
  double value)
{
  gamepadState.SetAxisState(gamepadAxis, value);
}

inline auto
GamepadStateAccessor::SetButtonState(
  GamepadState& gamepadState,
  System::DeviceTypes::Input::GamepadButton_t gamepadButton,
  GamepadState::ButtonState_t buttonState) -> void
{
  gamepadState.SetButtonState(gamepadButton, buttonState);
}

NAMESPACE_END(System::EventProcessing)

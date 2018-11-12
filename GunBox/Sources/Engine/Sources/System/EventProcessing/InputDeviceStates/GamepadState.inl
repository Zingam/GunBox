#pragma once

////////////////////////////////////////////////////////////////////////////////
// Inline method implementations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(System::EventProcessing)

inline double const
GamepadState::GetAxisState(
  System::DeviceTypes::Input::GamepadAxis_t gamepadAxis) const
{
  return axisStates[EnumCast(gamepadAxis)];
}

inline GamepadState::ButtonState_t const
GamepadState::GetButtonState(
  System::DeviceTypes::Input::GamepadButton_t button) const
{
  return buttonStates[EnumCast(button)];
}

inline void
GamepadState::SetAxisState(
  System::DeviceTypes::Input::GamepadAxis_t gamepadAxis,
  double value)
{
  axisStates[EnumCast(gamepadAxis)] = value;
}

inline void
GamepadState::SetButtonState(
  System::DeviceTypes::Input::GamepadButton_t gamepadButton,
  GamepadState::ButtonState_t buttonState)
{
  buttonStates[EnumCast(gamepadButton)] = buttonState;
}

NAMESPACE_END(System::EventProcessing)

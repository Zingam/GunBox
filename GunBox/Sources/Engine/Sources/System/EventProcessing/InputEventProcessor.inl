////////////////////////////////////////////////////////////////////////////////
// Inline method implementations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(System::EventProcessing)

////////////////////////////////////////////////////////////////////////////////
// Properties
////////////////////////////////////////////////////////////////////////////////

double
InputEventProcessor::GamepadAxisValue(
  System::DeviceTypes::Input::GamepadId_t gamepadId,
  System::DeviceTypes::Input::GamepadAxis_t gamepadAxis) const
{
  auto& gamepadState = gamepads.at(gamepadId).second;
  return gamepadState.GetAxisState(gamepadAxis);
}

GamepadState::ButtonState_t
InputEventProcessor::GamepadButtonState(
  System::DeviceTypes::Input::GamepadId_t gamepadId,
  System::DeviceTypes::Input::GamepadButton_t gamepadButton) const
{
  auto& gamepadState = gamepads.at(gamepadId).second;
  return gamepadState.GetButtonState(gamepadButton);
}

std::vector<System::DeviceTypes::Input::GamepadId_t> const&
InputEventProcessor::GamepadIds() const
{
  return gamepadIds;
}

System::EventProcessing::KeyboardState::KeyState_t
InputEventProcessor::KeyboardKeyState(
  System::DeviceTypes::Input::ScanCode_t scancode)
{
  return keyboardState.GetKeyState(scancode);
}

NAMESPACE_END(System::EventProcessing)

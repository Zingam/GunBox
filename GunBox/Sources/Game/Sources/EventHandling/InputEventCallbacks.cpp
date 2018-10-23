// Self
#include "InputEventCallbacks.hpp"

NAMESPACE_BEGIN(GunBox)

InputEventCallbacks::~InputEventCallbacks() {}

void
InputEventCallbacks::GamepadAxisMotion(
  System::DeviceTypes::IO::GamepadId_t id,
  System::DeviceTypes::IO::GamepadAxis_t axis,
  float value)
{}

void
InputEventCallbacks::GamepadButtonDown(
  System::DeviceTypes::IO::GamepadId_t id,
  System::DeviceTypes::IO::GamepadButton_t button)
{}

void
InputEventCallbacks::GamepadButtonUp(
  System::DeviceTypes::IO::GamepadId_t id,
  System::DeviceTypes::IO::GamepadButton_t button)
{}

void
InputEventCallbacks::GamepadDeviceAdd(System::DeviceTypes::IO::GamepadId_t id)
{}

void
InputEventCallbacks::GamepadDeviceRemove(
  System::DeviceTypes::IO::GamepadId_t id)
{}

void
InputEventCallbacks::KeyboardKeyDown(System::DeviceTypes::IO::Key_t key)
{}

void
InputEventCallbacks::KeyboardKeyUp(System::DeviceTypes::IO::Key_t key)
{}

NAMESPACE_END(GunBox)

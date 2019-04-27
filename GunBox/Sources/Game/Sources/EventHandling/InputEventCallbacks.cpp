// Self
#include "InputEventCallbacks.hpp"

// Project headers
#include "EventHandling/Commands/Commander_Interface.hpp"

NAMESPACE_BEGIN(GunBox)

////////////////////////////////////////////////////////////////////////////////
// Constructors & Destructors
////////////////////////////////////////////////////////////////////////////////

InputEventCallbacks::~InputEventCallbacks() = default;

////////////////////////////////////////////////////////////////////////////////
// Virtual methods
////////////////////////////////////////////////////////////////////////////////

void
InputEventCallbacks::GamepadAxisMotion(
  System::DeviceTypes::Input::GamepadId_t const id,
  System::DeviceTypes::Input::GamepadAxis_t const axis,
  double value)
{
  commander->GamepadAxisMotion(id, axis, value);
}

void
InputEventCallbacks::GamepadButtonDown(
  System::DeviceTypes::Input::GamepadId_t const id,
  System::DeviceTypes::Input::GamepadButton_t const button)
{
  commander->GamepadButtonDown(id, button);
}

void
InputEventCallbacks::GamepadButtonUp(
  System::DeviceTypes::Input::GamepadId_t const id,
  System::DeviceTypes::Input::GamepadButton_t const button)
{
  commander->GamepadButtonUp(id, button);
}

void
InputEventCallbacks::GamepadDeviceAdd(System::DeviceTypes::Input::GamepadId_t const id)
{
  commander->GamepadDeviceAdd(id);
}

void
InputEventCallbacks::GamepadDeviceRemove(
  System::DeviceTypes::Input::GamepadId_t const id)
{
  commander->GamepadDeviceRemove(id);
}

void
InputEventCallbacks::KeyboardKeyDown(System::DeviceTypes::Input::Key_t const key)
{
  commander->KeyboardKeyDown(key);
}

void
InputEventCallbacks::KeyboardKeyUp(System::DeviceTypes::Input::Key_t const key)
{
  commander->KeyboardKeyUp(key);
}

NAMESPACE_END(GunBox)

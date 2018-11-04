// Self
#include "InputEventCallbacks.hpp"

// Project headers
#include "EventHandling/Commands/Commander_Interface.hpp"


// Project headers
#include "EventHandling/Commands/Commander_Interface.hpp"

NAMESPACE_BEGIN(GunBox)

// Forward declarations require constructor and destructor definitions
InputEventCallbacks::InputEventCallbacks() = default;

InputEventCallbacks::~InputEventCallbacks() = default;

void
InputEventCallbacks::GamepadAxisMotion(
  System::DeviceTypes::IO::GamepadId_t id,
  System::DeviceTypes::IO::GamepadAxis_t axis,
  double value)
{
  commander->GamepadAxisMotion(id, axis, value);
}

void
InputEventCallbacks::GamepadButtonDown(
  System::DeviceTypes::IO::GamepadId_t id,
  System::DeviceTypes::IO::GamepadButton_t button)
{
  commander->GamepadButtonDown(id, button);
}

void
InputEventCallbacks::GamepadButtonUp(
  System::DeviceTypes::IO::GamepadId_t id,
  System::DeviceTypes::IO::GamepadButton_t button)
{
  commander->GamepadButtonUp(id, button);
}

void
InputEventCallbacks::GamepadDeviceAdd(System::DeviceTypes::IO::GamepadId_t id)
{
  commander->GamepadDeviceAdd(id);
}

void
InputEventCallbacks::GamepadDeviceRemove(
  System::DeviceTypes::IO::GamepadId_t id)
{
  commander->GamepadDeviceRemove(id);
}

void
InputEventCallbacks::KeyboardKeyDown(System::DeviceTypes::IO::Key_t key)
{
  commander->KeyboardKeyDown(key);
}

void
InputEventCallbacks::KeyboardKeyUp(System::DeviceTypes::IO::Key_t key)
{
  commander->KeyboardKeyUp(key);
}

NAMESPACE_END(GunBox)

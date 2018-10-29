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

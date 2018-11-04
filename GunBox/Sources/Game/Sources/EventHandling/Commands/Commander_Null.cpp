// Self
#include "Commander_Null.hpp"

NAMESPACE_BEGIN(GunBox)

Commander_Null::~Commander_Null() {}

void
Commander_Null::GamepadAxisMotion(
  System::DeviceTypes::IO::GamepadId_t id,
  System::DeviceTypes::IO::GamepadAxis_t axis,
  double value)
{}

void
Commander_Null::GamepadButtonDown(
  System::DeviceTypes::IO::GamepadId_t id,
  System::DeviceTypes::IO::GamepadButton_t button)
{}

void
Commander_Null::GamepadButtonUp(
  System::DeviceTypes::IO::GamepadId_t id,
  System::DeviceTypes::IO::GamepadButton_t button)
{}

void
Commander_Null::GamepadDeviceAdd(System::DeviceTypes::IO::GamepadId_t id)
{}

void
Commander_Null::GamepadDeviceRemove(System::DeviceTypes::IO::GamepadId_t id)
{}

void
Commander_Null::KeyboardKeyDown(System::DeviceTypes::IO::Key_t key)
{}

void
Commander_Null::KeyboardKeyUp(System::DeviceTypes::IO::Key_t key)
{}

NAMESPACE_END(GunBox)

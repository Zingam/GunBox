// Self
#include "Commander_Null.hpp"

NAMESPACE_BEGIN(GunBox)

Commander_Null::~Commander_Null() {}

void
Commander_Null::GamepadAxisMotion(
  System::DeviceTypes::Input::GamepadId_t id,
  System::DeviceTypes::Input::GamepadAxis_t axis,
  double value)
{}

void
Commander_Null::GamepadButtonDown(
  System::DeviceTypes::Input::GamepadId_t id,
  System::DeviceTypes::Input::GamepadButton_t button)
{}

void
Commander_Null::GamepadButtonUp(
  System::DeviceTypes::Input::GamepadId_t id,
  System::DeviceTypes::Input::GamepadButton_t button)
{}

void
Commander_Null::GamepadDeviceAdd(System::DeviceTypes::Input::GamepadId_t id)
{}

void
Commander_Null::GamepadDeviceRemove(System::DeviceTypes::Input::GamepadId_t id)
{}

void
Commander_Null::KeyboardKeyDown(System::DeviceTypes::Input::Key_t const& key)
{}

void
Commander_Null::KeyboardKeyUp(System::DeviceTypes::Input::Key_t const& key)
{}

void
Commander_Null::SystemEvent(Application::State_t applicationState)
{
  return;
}

NAMESPACE_END(GunBox)

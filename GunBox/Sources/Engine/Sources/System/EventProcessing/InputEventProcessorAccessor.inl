#pragma once

// C Standard Library
#include <cassert>

////////////////////////////////////////////////////////////////////////////////
// Inline method implementations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(System::EventProcessing)

inline void
InputEventProcessorAccessor::GamepadAxisMotion(
  InputEventProcessor& inputProcessor,
  System::DeviceTypes::Input::GamepadId_t const id,
  System::DeviceTypes::Input::GamepadAxis_t const axis,
  double const value)
{
  assert(
    (nullptr != inputProcessor.cbGamepadAxisMotion_UPtr) &&
    "The callback is not initialized");

  (*inputProcessor.cbGamepadAxisMotion_UPtr)(id, axis, value);
}

inline void
InputEventProcessorAccessor::GamepadButtonDown(
  InputEventProcessor& inputProcessor,
  System::DeviceTypes::Input::GamepadId_t id,
  System::DeviceTypes::Input::GamepadButton_t button)
{
  assert(
    (nullptr != inputProcessor.cbGamepadButtonDown_UPtr) &&
    "The callback is not initialized");

  (*inputProcessor.cbGamepadButtonDown_UPtr)(id, button);
}

inline void
InputEventProcessorAccessor::GamepadButtonUp(
  InputEventProcessor& inputProcessor,
  System::DeviceTypes::Input::GamepadId_t id,
  System::DeviceTypes::Input::GamepadButton_t button)
{
  assert(
    (nullptr != inputProcessor.cbGamepadButtonUp_UPtr) &&
    "The callback is not initialized");

  (*inputProcessor.cbGamepadButtonUp_UPtr)(id, button);
}

inline void
InputEventProcessorAccessor::GamepadDeviceAdd(
  InputEventProcessor& inputProcessor,
  System::DeviceTypes::Input::GamepadId_t const id)
{
  inputProcessor.AddGamepad(id);

  assert(
    (nullptr != inputProcessor.cbGamepadDeviceAdd_UPtr) &&
    "The callback is not initialized");
  (*inputProcessor.cbGamepadDeviceAdd_UPtr)(id);
}

inline void
InputEventProcessorAccessor::GamepadDeviceRemove(
  InputEventProcessor& inputProcessor,
  System::DeviceTypes::Input::GamepadId_t const id)
{
  inputProcessor.RemoveGamepad(id);

  assert(
    (nullptr != inputProcessor.cbGamepadDeviceRemove_UPtr) &&
    "The callback is not initialized");
  (*inputProcessor.cbGamepadDeviceRemove_UPtr)(id);
}

inline auto
InputEventProcessorAccessor::KeyboardKeyDown(
  InputEventProcessor& inputProcessor,
  System::DeviceTypes::Input::Key_t key) -> void
{
  assert(
    (nullptr != inputProcessor.cbKeyboardKeyDown_UPtr) &&
    "The callback is not initialized");
  (*inputProcessor.cbKeyboardKeyDown_UPtr)(key);
}

inline auto
InputEventProcessorAccessor::KeyboardKeyUp(
  InputEventProcessor& inputProcessor,
  System::DeviceTypes::Input::Key_t key) -> void
{
  assert(
    (nullptr != inputProcessor.cbKeyboardKeyUp_UPtr) &&
    "The callback is not initialized");
  (*inputProcessor.cbKeyboardKeyUp_UPtr)(key);
}

NAMESPACE_END(System::EventProcessing)

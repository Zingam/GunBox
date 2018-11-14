#pragma once

// BASE MACROS header
#include "Common/Macros/Base.hpp"

// Project headers - System
#include "System/DeviceTypes/Input/GamepadTypes.hpp"
#include "System/EventProcessing/InputEventProcessor.hpp"

////////////////////////////////////////////////////////////////////////////////
// Forward declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(System::EventHandlers)

class GamepadEventHandler;
class KeyboardEventHandler;

NAMESPACE_END(System::EventHandlers)

////////////////////////////////////////////////////////////////////////////////
// Class declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(System::EventProcessing)

class InputEventProcessorAccessor
{
private:
  // clang-format off
  static auto GamepadAxisMotion(
    InputEventProcessor& inputProcessor,
    System::DeviceTypes::Input::GamepadId_t id,
    System::DeviceTypes::Input::GamepadAxis_t axis,
    double value)
    -> void;

  static auto GamepadButtonDown(
    InputEventProcessor& inputProcessor,
    System::DeviceTypes::Input::GamepadId_t id,
    System::DeviceTypes::Input::GamepadButton_t button)
    -> void;

  static auto GamepadButtonUp(
    InputEventProcessor& inputProcessor,
    System::DeviceTypes::Input::GamepadId_t id,
    System::DeviceTypes::Input::GamepadButton_t button)
    -> void;

  static auto GamepadDeviceAdd(
    InputEventProcessor& inputProcessor,
    System::DeviceTypes::Input::GamepadId_t const id)
      -> void;

  static auto GamepadDeviceRemove(
    InputEventProcessor& inputProcessor,
    System::DeviceTypes::Input::GamepadId_t const id)
    -> void;

  static auto KeyboardKeyDown(
    InputEventProcessor& inputProcessor,
    System::DeviceTypes::Input::Key_t key)
    -> void;

  static auto KeyboardKeyUp(
    InputEventProcessor& inputProcessor,
    System::DeviceTypes::Input::Key_t key)
    -> void;
  // clang-format on

private:
  friend class System::EventHandlers::GamepadEventHandler;
  friend class System::EventHandlers::KeyboardEventHandler;
};

NAMESPACE_END(System::EventProcessing)

////////////////////////////////////////////////////////////////////////////////
// Inline method implementations
////////////////////////////////////////////////////////////////////////////////

#include "InputEventProcessorAccessor.inl"

////////////////////////////////////////////////////////////////////////////////

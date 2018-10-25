#pragma once

// BASE MACROS header
#include "Common/Macros/Base.hpp"

// Project headers - System
#include "System/DeviceTypes/IO/GamepadTypes.hpp"
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
  static inline auto GamepadAxisMotion(
    InputEventProcessor& inputProcessor,
    System::DeviceTypes::IO::GamepadId_t id,
    System::DeviceTypes::IO::GamepadAxis_t axis,
    float value)
    -> void;

  static inline auto GamepadButtonDown(
    InputEventProcessor& inputProcessor,
    System::DeviceTypes::IO::GamepadId_t id,
    System::DeviceTypes::IO::GamepadButton_t button)
    -> void;

  static inline auto GamepadButtonUp(
    InputEventProcessor& inputProcessor,
    System::DeviceTypes::IO::GamepadId_t id,
    System::DeviceTypes::IO::GamepadButton_t button)
    -> void;

  static auto GamepadDeviceAdd(
    InputEventProcessor& inputProcessor,
    System::DeviceTypes::IO::GamepadId_t const id)
      -> void;

  static auto GamepadDeviceRemove(
    InputEventProcessor& inputProcessor,
    System::DeviceTypes::IO::GamepadId_t const id)
    -> void;

  static inline auto KeyboardKeyDown(
    InputEventProcessor& inputProcessor,
    System::DeviceTypes::IO::Key_t key)
    -> void;

  static inline auto KeyboardKeyUp(
    InputEventProcessor& inputProcessor,
    System::DeviceTypes::IO::Key_t key)
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

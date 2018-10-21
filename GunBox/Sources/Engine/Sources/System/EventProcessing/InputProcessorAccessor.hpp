#pragma once

// Project headers - BASE
#include "Common/Macros/Base.hpp"

// Project headers - System
#include "System/DeviceTypes/IO/GamepadTypes.hpp"
#include "System/EventProcessing/InputProcessor.hpp"

////////////////////////////////////////////////////////////////////////////////
// Forward declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(System::EventHandlers::IO)

class GamepadEventHandler;
class KeyboardEventHandler;

NAMESPACE_END(System::EventHandlers::IO)

////////////////////////////////////////////////////////////////////////////////
// Class declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(System)

class InputProcessorAccessor
{
private:
  // clang-format off
  static inline auto GamepadAxisMotion(
    InputProcessor& inputProcessor,
    System::DeviceTypes::IO::GamepadId_t id,
    System::DeviceTypes::IO::GamepadAxis_t axis,
    float value)
    -> void;

  static inline auto GamepadButtonDown(
    InputProcessor& inputProcessor,
    System::DeviceTypes::IO::GamepadId_t id,
    System::DeviceTypes::IO::GamepadButton_t button)
    -> void;

  static inline auto GamepadButtonUp(
    InputProcessor& inputProcessor,
    System::DeviceTypes::IO::GamepadId_t id,
    System::DeviceTypes::IO::GamepadButton_t button)
    -> void;

  static auto GamepadDeviceAdd(
    InputProcessor& inputProcessor,
    System::DeviceTypes::IO::GamepadId_t const id)
      -> void;

  static auto GamepadDeviceRemove(
    InputProcessor& inputProcessor,
    System::DeviceTypes::IO::GamepadId_t const id)
    -> void;

  static inline auto KeyboardKeyDown(
    InputProcessor& inputProcessor,
    System::DeviceTypes::IO::Key_t key)
    -> void;

  static inline auto KeyboardKeyUp(
    InputProcessor& inputProcessor,
    System::DeviceTypes::IO::Key_t key)
    -> void;
  // clang-format on

private:
  friend class System::EventHandlers::IO::GamepadEventHandler;
  friend class System::EventHandlers::IO::KeyboardEventHandler;
};

NAMESPACE_END(System)

////////////////////////////////////////////////////////////////////////////////
// Inline method implementations
////////////////////////////////////////////////////////////////////////////////

#include "InputProcessorAccessor.inl"

////////////////////////////////////////////////////////////////////////////////

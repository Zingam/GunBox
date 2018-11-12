#pragma once

// BASE MACROS header
#include "Common/Macros/Base.hpp"

// Project headers - Common
#include "Common/SimpleDelegate.hpp"
// Project headers - System
#include "System/DeviceTypes/Input/GamepadTypes.hpp"
#include "System/EventProcessing/InputDeviceStates/GamepadState.hpp"
#include "System/EventProcessing/InputDeviceStates/KeyboardState.hpp"
#include "System/EventProcessing/InputEventCallbacks_Interface.hpp"

// C Standard Library
#include <cstdint>
// C++ Standard Library
#include <map>
#include <memory>
#include <unordered_map>

NAMESPACE_BEGIN(System::EventProcessing)

class InputEventProcessor
{
public:
  using Gamepad_t = void*;

public:
  auto InitializeCallbacks(
    std::shared_ptr<InputEventCallbacks_Interface> const inputCallbacks)
    -> void;

  auto InitializeCallbacks(InputEventCallbacks_Interface& inputCallbacks)
    -> void;

  auto ProcessInputDeviceStates() -> void;

  // Properties
public:
  auto Gamepads() const -> std::map<
    System::DeviceTypes::Input::GamepadId_t const,
    std::pair<Gamepad_t, System::EventProcessing::GamepadState>> const&;

  auto KeyboardState() const -> System::EventProcessing::KeyboardState const&;

private:
  auto ProcessKeyboardDeviceStates() -> void;

  auto ProcessGamepadDeviceStates() -> void;

  auto AddGamepad(System::DeviceTypes::Input::GamepadId_t const deviceIndex)
    -> void;

  auto RemoveGamepad(System::DeviceTypes::Input::GamepadId_t const gamepadId)
    -> void;

  // Callbacks
private:
  // clang-format off
  std::unique_ptr<SimpleDelegate<InputEventCallbacks_Interface,
    decltype(&InputEventCallbacks_Interface::GamepadAxisMotion)>>
    cbGamepadAxisMotion_UPtr;

  std::unique_ptr<SimpleDelegate<InputEventCallbacks_Interface,
    decltype(&InputEventCallbacks_Interface::GamepadDeviceAdd)>>
    cbGamepadDeviceAdd_UPtr;

  std::unique_ptr<SimpleDelegate<InputEventCallbacks_Interface,
    decltype(&InputEventCallbacks_Interface::GamepadDeviceRemove)>>
    cbGamepadDeviceRemove_UPtr;

  std::unique_ptr<SimpleDelegate<InputEventCallbacks_Interface,
    decltype(&InputEventCallbacks_Interface::GamepadButtonDown)>>
    cbGamepadButtonDown_UPtr;

  std::unique_ptr<SimpleDelegate<InputEventCallbacks_Interface,
    decltype(&InputEventCallbacks_Interface::GamepadButtonUp)>>
    cbGamepadButtonUp_UPtr;

  std::unique_ptr<SimpleDelegate<InputEventCallbacks_Interface,
    decltype(&InputEventCallbacks_Interface::KeyboardKeyDown)>>
    cbKeyboardKeyDown_UPtr;

  std::unique_ptr<SimpleDelegate<InputEventCallbacks_Interface,
    decltype(&InputEventCallbacks_Interface::KeyboardKeyUp)>>
    cbKeyboardKeyUp_UPtr;
  // clang-format on

private:
  friend class InputEventProcessorAccessor;

private:
  std::map<
    System::DeviceTypes::Input::GamepadId_t const,
    std::pair<Gamepad_t, System::EventProcessing::GamepadState>>
    gamepads;
  System::EventProcessing::KeyboardState keyboardState;
};

NAMESPACE_END(System::EventProcessing)

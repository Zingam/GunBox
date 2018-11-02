#pragma once

// BASE MACROS header
#include "Common/Macros/Base.hpp"

// Project headers - Common
#include "Common/SimpleDelegate.hpp"
// Project headers - System
#include "System/DeviceTypes/IO/GamepadTypes.hpp"
#include "System/EventProcessing/InputEventCallbacks_Interface.hpp"

// C Standard Library
#include <cstdint>
// C++ Standard Library
#include <map>
#include <memory>

////////////////////////////////////////////////////////////////////////////////
// Forward declarations
////////////////////////////////////////////////////////////////////////////////

struct _SDL_GameController;
using Gamepad = _SDL_GameController*;

////////////////////////////////////////////////////////////////////////////////
// Class declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(System::EventProcessing)

class InputEventProcessor
{
public:
  ~InputEventProcessor();

public:
  auto InitializeCallbacks(
    std::shared_ptr<InputEventCallbacks> const inputCallbacks) -> void;

  auto InitializeCallbacks(InputEventCallbacks& inputCallbacks) -> void;

private:
  auto AddGamepad(System::DeviceTypes::IO::GamepadId_t const id) -> void;

  auto RemoveGamepad(System::DeviceTypes::IO::GamepadId_t const id) -> void;

  // Callbacks
private:
  // clang-format off
  std::unique_ptr<SimpleDelegate<InputEventCallbacks,
    decltype(&InputEventCallbacks::GamepadAxisMotion)>>
    cbGamepadAxisMotion_UPtr;

  std::unique_ptr<SimpleDelegate<InputEventCallbacks,
    decltype(&InputEventCallbacks::GamepadDeviceAdd)>>
    cbGamepadDeviceAdd_UPtr;

  std::unique_ptr<SimpleDelegate<InputEventCallbacks,
    decltype(&InputEventCallbacks::GamepadDeviceRemove)>>
    cbGamepadDeviceRemove_UPtr;

  std::unique_ptr<SimpleDelegate<InputEventCallbacks,
    decltype(&InputEventCallbacks::GamepadButtonDown)>>
    cbGamepadButtonDown_UPtr;

  std::unique_ptr<SimpleDelegate<InputEventCallbacks,
    decltype(&InputEventCallbacks::GamepadButtonUp)>>
    cbGamepadButtonUp_UPtr;

  std::unique_ptr<SimpleDelegate<InputEventCallbacks,
    decltype(&InputEventCallbacks::KeyboardKeyDown)>>
    cbKeyboardKeyDown_UPtr;

  std::unique_ptr<SimpleDelegate<InputEventCallbacks,
    decltype(&InputEventCallbacks::KeyboardKeyUp)>>
    cbKeyboardKeyUp_UPtr;
  // clang-format on

private:
  friend class InputEventProcessorAccessor;

private:
  std::map<System::DeviceTypes::IO::GamepadId_t const, Gamepad> gamepads;
};

NAMESPACE_END(System::EventProcessing)

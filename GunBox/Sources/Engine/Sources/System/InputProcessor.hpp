#pragma once

// Project headers - BASE
#include "Common/Macros/Base.hpp"

// Project headers - Common
#include "Common/SimpleDelegate.hpp"
// Project headers - System
#include "System/DeviceTypes/IO/GamepadTypes.hpp"
#include "System/InputCallbacks.hpp"

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

NAMESPACE_BEGIN(System)

class InputProcessor
{
public:
  ~InputProcessor();

public:
  auto SetInputCallbacksObject(
    std::shared_ptr<InputCallbacks> const inputCallbacks) -> void;

  auto SetInputCallbacksObject(InputCallbacks& inputCallbacks) -> void;

private:
  auto AddGamepad(System::DeviceTypes::IO::GamepadId_t const id) -> void;

  auto RemoveGamepad(System::DeviceTypes::IO::GamepadId_t const id) -> void;

  // Callbacks
private:
  // clang-format off
  std::unique_ptr<SimpleDelegate<InputCallbacks,
    decltype(&InputCallbacks::GamepadAxisMotion)>>
    cbGamepadAxisMotion_UPtr;

  std::unique_ptr<SimpleDelegate<InputCallbacks,
    decltype(&InputCallbacks::GamepadDeviceAdd)>>
    cbGamepadDeviceAdd_UPtr;

  std::unique_ptr<SimpleDelegate<InputCallbacks,
    decltype(&InputCallbacks::GamepadDeviceRemove)>>
    cbGamepadDeviceRemove_UPtr;

  std::unique_ptr<SimpleDelegate<InputCallbacks,
    decltype(&InputCallbacks::GamepadButtonDown)>>
    cbGamepadButtonDown_UPtr;

  std::unique_ptr<SimpleDelegate<InputCallbacks,
    decltype(&InputCallbacks::GamepadButtonUp)>>
    cbGamepadButtonUp_UPtr;

  std::unique_ptr<SimpleDelegate<InputCallbacks,
    decltype(&InputCallbacks::KeyboardKeyDown)>>
    cbKeyboardKeyDown_UPtr;

  std::unique_ptr<SimpleDelegate<InputCallbacks,
    decltype(&InputCallbacks::KeyboardKeyUp)>>
    cbKeyboardKeyUp_UPtr;
  // clang-format on

private:
  friend class InputProcessorAccessor;

private:
  std::map<System::DeviceTypes::IO::GamepadId_t const, Gamepad> gamepads;
};

NAMESPACE_END(System)

////////////////////////////////////////////////////////////////////////////////
// Inline method implementations
////////////////////////////////////////////////////////////////////////////////

#include "InputProcessor.inl"

////////////////////////////////////////////////////////////////////////////////

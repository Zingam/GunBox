#pragma once

// Project headers - Common
#include "Common/Macros/Base.hpp"

// Project headers - Common
#include "Common/SimpleDelegate.hpp"
// Project headers - System
#include "System/InputCallbacks.hpp"

// C Standard Library
#include <cstdint>
// C++ Standard Library
#include <map>

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
  using GamepadId = std::int32_t;

public:
  ~InputProcessor();

public:
  auto AddGamepad(GamepadId const gameControllerId) -> void;
  auto RemoveGamepad(GamepadId const gameControllerId) -> void;

private:
  std::map<GamepadId const, Gamepad> gamepads;
  InputCallbacks& inputCallbacks;
  // Callbacks
  std::unique_ptr<SimpleDelegate<InputCallbacks,
                                 decltype(&InputCallbacks::GamepadAxisMotion)>>
    cbGamepadAxisMotion_UPtr;
  std::unique_ptr<SimpleDelegate<InputCallbacks,
                                 decltype(&InputCallbacks::GamepadButtonDown)>>
    cbGamepadButtonDown_UPtr;
  std::unique_ptr<
    SimpleDelegate<InputCallbacks, decltype(&InputCallbacks::GamepadButtonUp)>>
    cbGamepadButtonUp_UPtr;
  std::unique_ptr<
    SimpleDelegate<InputCallbacks, decltype(&InputCallbacks::KeyboardKeyDown)>>
    cbKeyboardKeyDown_UPtr;
  std::unique_ptr<
    SimpleDelegate<InputCallbacks, decltype(&InputCallbacks::KeyboardKeyUp)>>
    cbKeyboardKeyUp_UPtr;
};

NAMESPACE_END(System)

////////////////////////////////////////////////////////////////////////////////
// Inline method implementations
////////////////////////////////////////////////////////////////////////////////

#include "InputProcessor.inl"

////////////////////////////////////////////////////////////////////////////////

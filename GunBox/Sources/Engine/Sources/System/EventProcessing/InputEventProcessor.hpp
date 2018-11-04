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
    std::shared_ptr<InputEventCallbacks_Interface> const inputCallbacks)
    -> void;

  auto InitializeCallbacks(InputEventCallbacks_Interface& inputCallbacks)
    -> void;

private:
  auto AddGamepad(System::DeviceTypes::IO::GamepadId_t const deviceIndex)
    -> void;

  auto RemoveGamepad(System::DeviceTypes::IO::GamepadId_t const gamepadId) -> void;

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
  std::map<System::DeviceTypes::IO::GamepadId_t const, Gamepad> gamepads;
};

NAMESPACE_END(System::EventProcessing)

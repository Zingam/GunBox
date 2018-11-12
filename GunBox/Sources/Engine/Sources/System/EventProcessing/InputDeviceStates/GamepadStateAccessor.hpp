#pragma once

// BASE MACROS header
#include "Common/Macros/Base.hpp"

// Project headers - System
#include "System/DeviceTypes/Input/GamepadTypes.hpp"
#include "System/EventProcessing/InputDeviceStates/GamepadState.hpp"

////////////////////////////////////////////////////////////////////////////////
// Forward declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(System::EventProcessing)

class InputEventProcessor;

NAMESPACE_END(System::EventProcessing)

////////////////////////////////////////////////////////////////////////////////
// Class declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(System::EventProcessing)

class GamepadStateAccessor
{
private:
  static inline auto SetAxisState(
    GamepadState& gamepadState,
    System::DeviceTypes::Input::GamepadAxis_t gamepadAxis,
    double value) -> void;

  static inline auto SetButtonState(
    GamepadState& gamepadState,
    System::DeviceTypes::Input::GamepadButton_t gamepadButton,
    GamepadState::ButtonState_t buttonState) -> void;

private:
  friend class System::EventProcessing::InputEventProcessor;
};

NAMESPACE_END(System::EventProcessing)

////////////////////////////////////////////////////////////////////////////////
// Inline method implementations
////////////////////////////////////////////////////////////////////////////////

#include "GamepadStateAccessor.inl"

////////////////////////////////////////////////////////////////////////////////

#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

// Project headers - System
#include "System/DeviceTypes/Input/GamepadTypes.hpp"

// C++ Standard Library
#include <array>

////////////////////////////////////////////////////////////////////////////////
// Forward declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(System::EventProcessing)

class GamepadStateAccessor;

NAMESPACE_END(System::EventProcessing)

////////////////////////////////////////////////////////////////////////////////
// Class declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(System::EventProcessing)

class GamepadState
{
public:
  enum class ButtonState_t
  {
    Pressed,
    Released
  };

public:
  auto GetAxisState(System::DeviceTypes::Input::GamepadAxis_t gamepadAxis) const
    -> double const;

  auto GetButtonState(System::DeviceTypes::Input::GamepadButton_t button) const
    -> ButtonState_t const;

private:
  auto SetAxisState(
    System::DeviceTypes::Input::GamepadAxis_t gamepadAxis,
    double value) -> void;

  auto SetButtonState(
    System::DeviceTypes::Input::GamepadButton_t gamepadButton,
    GamepadState::ButtonState_t buttonState) -> void;

private:
  friend class System::EventProcessing::GamepadStateAccessor;

private:
  std::array<double, System::DeviceTypes::Input::GamepadAxis_t_ElementCount>
    axisStates;
  std::array<
    ButtonState_t,
    System::DeviceTypes::Input::GamepadButton_t_ElementCount>
    buttonStates;
};

NAMESPACE_END(System::EventProcessing)

////////////////////////////////////////////////////////////////////////////////
// Inline implementations
////////////////////////////////////////////////////////////////////////////////

#include "GamepadState.inl"

////////////////////////////////////////////////////////////////////////////////

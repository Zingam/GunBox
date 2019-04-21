#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

// Engine headers - System
#include "System/DeviceTypes/Input/GamepadTypes.hpp"
#include "System/DeviceTypes/Input/KeyboardTypes.hpp"
#include "System/EventProcessing/InputEventCallbacks_Interface.hpp"

// C++ Standard Library
#include <memory>

////////////////////////////////////////////////////////////////////////////////
// Forward declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(GunBox)

class Commander_Interface;

NAMESPACE_END(GunBox)

////////////////////////////////////////////////////////////////////////////////
// Class declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(GunBox)

class InputEventCallbacks final
  : public System::EventProcessing::InputEventCallbacks_Interface
{
public:
  InputEventCallbacks();
  ~InputEventCallbacks() final;

public:
  template<typename Commander, typename... Args>
  auto SetCommander(Args&&... args) -> void;

  // Virtual methods
public:
  // clang-format off
  auto GamepadAxisMotion(
    System::DeviceTypes::Input::GamepadId_t const id,
    System::DeviceTypes::Input::GamepadAxis_t const axis,
    double const value)
    -> void final;

  auto GamepadButtonDown(
    System::DeviceTypes::Input::GamepadId_t const id,
    System::DeviceTypes::Input::GamepadButton_t const button)
    -> void final;

  auto GamepadButtonUp(
    System::DeviceTypes::Input::GamepadId_t const id,
    System::DeviceTypes::Input::GamepadButton_t const button)
    -> void final;

  auto GamepadDeviceAdd(
    System::DeviceTypes::Input::GamepadId_t const id)
    -> void final;

  auto GamepadDeviceRemove(
    System::DeviceTypes::Input::GamepadId_t const id)
    -> void final;

  auto KeyboardKeyDown(
    System::DeviceTypes::Input::Key_t const key)
    -> void final;

  auto KeyboardKeyUp(
    System::DeviceTypes::Input::Key_t const key)
    -> void final;
  // clang-format on

private:
  std::unique_ptr<Commander_Interface> commander;
};

NAMESPACE_END(GunBox)

////////////////////////////////////////////////////////////////////////////////
// Inline implementations
////////////////////////////////////////////////////////////////////////////////

#include "InputEventCallbacks.inl"

////////////////////////////////////////////////////////////////////////////////

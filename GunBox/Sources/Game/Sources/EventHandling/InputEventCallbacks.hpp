#pragma once

// BASE MACROS header
#include "Common/Macros/Base.hpp"

// Engine headers - System
#include "System/DeviceTypes/IO/GamepadTypes.hpp"
#include "System/DeviceTypes/IO/KeyboardTypes.hpp"
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
    System::DeviceTypes::IO::GamepadId_t id,
    System::DeviceTypes::IO::GamepadAxis_t axis,
    float value)
    -> void final;

  auto GamepadButtonDown(
    System::DeviceTypes::IO::GamepadId_t id,
    System::DeviceTypes::IO::GamepadButton_t button)
    -> void final;

  auto GamepadButtonUp(
    System::DeviceTypes::IO::GamepadId_t id,
    System::DeviceTypes::IO::GamepadButton_t button)
    -> void final;

  auto GamepadDeviceAdd(
    System::DeviceTypes::IO::GamepadId_t id)
    -> void final;

  auto GamepadDeviceRemove(
    System::DeviceTypes::IO::GamepadId_t id)
    -> void final;

  auto KeyboardKeyDown(
    System::DeviceTypes::IO::Key_t key)
    -> void final;

  auto KeyboardKeyUp(
    System::DeviceTypes::IO::Key_t key)
    -> void final;
  // clang-format on

private:
  std::unique_ptr<Commander_Interface> commander;
};

NAMESPACE_END(GunBox)

////////////////////////////////////////////////////////////////////////////////
// Inline method implementations
////////////////////////////////////////////////////////////////////////////////

#include "InputEventCallbacks.inl"

////////////////////////////////////////////////////////////////////////////////

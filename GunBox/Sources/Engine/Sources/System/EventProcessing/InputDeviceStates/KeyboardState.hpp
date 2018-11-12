#pragma once

// BASE MACROS header
#include "Common/Macros/Base.hpp"

// Project headers - System
#include "System/DeviceTypes/Input/KeyboardTypes.hpp"

// C++ Standard Library
#include <array>

////////////////////////////////////////////////////////////////////////////////
// Forward declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(System::EventProcessing)

class KeyboardStateAccessor;

NAMESPACE_END(System::EventProcessing)

////////////////////////////////////////////////////////////////////////////////
// Class declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(System::EventProcessing)

class KeyboardState
{
public:
  enum class KeyState_t
  {
    Pressed,
    Released
  };

public:
  auto GetKeyState(System::DeviceTypes::Input::ScanCode_t scanCode) const
    -> KeyState_t const;

private:
  auto SetKeyState(
    System::DeviceTypes::Input::ScanCode_t scanCode,
    KeyboardState::KeyState_t keyState) -> void;

private:
  friend class System::EventProcessing::KeyboardStateAccessor;

private:
  std::array<KeyState_t, System::DeviceTypes::Input::ScanCode_t_ElementsCount>
    keyStates;
};

NAMESPACE_END(System::EventProcessing)

////////////////////////////////////////////////////////////////////////////////
// Inline method implementations
////////////////////////////////////////////////////////////////////////////////

#include "KeyboardState.inl"

////////////////////////////////////////////////////////////////////////////////
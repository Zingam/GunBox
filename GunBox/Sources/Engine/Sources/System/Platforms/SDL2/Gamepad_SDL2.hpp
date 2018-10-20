#pragma once

// Project headers - System
#include "System/DeviceTypes/IO/GamepadTypes.hpp"

// Third party libraries
#include <SDL_events.h>

NAMESPACE_BEGIN(System::Platforms::Gamepad)

inline System::DeviceTypes::IO::GamepadButton_t
ConvertGamepadButton(SDL_ControllerButtonEvent event);

NAMESPACE_END(System::Platforms::Gamepad)

////////////////////////////////////////////////////////////////////////////////
// Inline function implementations
////////////////////////////////////////////////////////////////////////////////

#include "Gamepad_SDL2.inl"

////////////////////////////////////////////////////////////////////////////////

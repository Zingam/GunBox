#pragma once

// Project headers - System
#include "System/DeviceTypes/Input/GamepadTypes.hpp"

// Third party libraries
#include <SDL_GameController.h>

NAMESPACE_BEGIN(System::Platforms::Gamepad)

System::DeviceTypes::Input::GamepadAxis_t
ConvertGamepadAxis(SDL_GameControllerAxis axis);

System::DeviceTypes::Input::GamepadButton_t
ConvertGamepadButton(SDL_GameControllerButton button);

NAMESPACE_END(System::Platforms::Gamepad)

////////////////////////////////////////////////////////////////////////////////
// Inline function implementations
////////////////////////////////////////////////////////////////////////////////

#include "Gamepad_SDL2.inl"

////////////////////////////////////////////////////////////////////////////////

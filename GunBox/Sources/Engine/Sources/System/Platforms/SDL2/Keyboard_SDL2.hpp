#pragma once

// Project headers - System
#include "System/DeviceTypes/IO/KeyboardTypes.hpp"

// Third party libraries
#include <SDL_events.h>
#include <SDL_scancode.h>

NAMESPACE_BEGIN(System::Platforms::Keyboard)

inline System::DeviceTypes::IO::ScanCode_t
ConvertScanCode(SDL_Scancode scancode);

inline System::DeviceTypes::IO::Key_t
ConvertToKey(SDL_KeyboardEvent event);

NAMESPACE_END(System::Platforms::Keyboard)

////////////////////////////////////////////////////////////////////////////////
// Inline function implementations
////////////////////////////////////////////////////////////////////////////////

#include "Keyboard_SDL2.inl"

////////////////////////////////////////////////////////////////////////////////

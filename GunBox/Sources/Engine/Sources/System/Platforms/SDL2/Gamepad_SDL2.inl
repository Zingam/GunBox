#pragma once

////////////////////////////////////////////////////////////////////////////////
// Inline function implementations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(System::Platforms::Gamepad)

inline System::DeviceTypes::IO::GamepadButton_t
ConvertGamepadButton(SDL_ControllerButtonEvent event)
{
  using namespace System::DeviceTypes::IO;

  switch (event.button) {
    case SDL_CONTROLLER_BUTTON_A: {
      return GamepadButton_t::A;
    }
    case SDL_CONTROLLER_BUTTON_B: {
      return GamepadButton_t::B;
    }
    case SDL_CONTROLLER_BUTTON_BACK: {
      return GamepadButton_t::Back;
    }
    case SDL_CONTROLLER_BUTTON_DPAD_DOWN: {
      return GamepadButton_t::DPadDown;
    }
    case SDL_CONTROLLER_BUTTON_DPAD_LEFT: {
      return GamepadButton_t::DpadLeft;
    }
    case SDL_CONTROLLER_BUTTON_DPAD_RIGHT: {
      return GamepadButton_t::DPadRight;
    }
    case SDL_CONTROLLER_BUTTON_DPAD_UP: {
      return GamepadButton_t::DPadUp;
    }
    case SDL_CONTROLLER_BUTTON_GUIDE: {
      return GamepadButton_t::Guide;
    }
    case SDL_CONTROLLER_BUTTON_LEFTSHOULDER: {
      return GamepadButton_t::ShoulderLeft;
    }
    case SDL_CONTROLLER_BUTTON_RIGHTSHOULDER: {
      return GamepadButton_t::ShoulderRight;
    }
    case SDL_CONTROLLER_BUTTON_START: {
      return GamepadButton_t::Start;
    }
    case SDL_CONTROLLER_BUTTON_LEFTSTICK: {
      return GamepadButton_t::ThumbLeft;
    }
    case SDL_CONTROLLER_BUTTON_RIGHTSTICK: {
      return GamepadButton_t::ThumbRight;
    }
    case SDL_CONTROLLER_BUTTON_X: {
      return GamepadButton_t::X;
    }
    case SDL_CONTROLLER_BUTTON_Y: {
      return GamepadButton_t::Y;
    }
    default: {
      return GamepadButton_t::UNKNOWN;
    }
  }
}

NAMESPACE_END(System::Platforms::Gamepad)

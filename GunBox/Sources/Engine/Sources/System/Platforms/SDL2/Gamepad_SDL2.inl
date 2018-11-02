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
      return GamepadButton_t::ButtonFaceA;
    }
    case SDL_CONTROLLER_BUTTON_B: {
      return GamepadButton_t::ButtonFaceB;
    }
    case SDL_CONTROLLER_BUTTON_DPAD_DOWN: {
      return GamepadButton_t::DPadDown;
    }
    case SDL_CONTROLLER_BUTTON_DPAD_LEFT: {
      return GamepadButton_t::DPadLeft;
    }
    case SDL_CONTROLLER_BUTTON_DPAD_RIGHT: {
      return GamepadButton_t::DPadRight;
    }
    case SDL_CONTROLLER_BUTTON_DPAD_UP: {
      return GamepadButton_t::DPadUp;
    }
    case SDL_CONTROLLER_BUTTON_LEFTSHOULDER: {
      return GamepadButton_t::ButtonShoulderLeft;
    }
    case SDL_CONTROLLER_BUTTON_RIGHTSTICK: {
      return GamepadButton_t::ButtonThumbRight;
    }
    case SDL_CONTROLLER_BUTTON_X: {
      return GamepadButton_t::ButtonFaceX;
    }
    case SDL_CONTROLLER_BUTTON_Y: {
      return GamepadButton_t::ButtonFaceY;
    }
    default: {
      switch (event.button) {
        case SDL_CONTROLLER_BUTTON_RIGHTSHOULDER: {
          return GamepadButton_t::ButtonShoulderRight;
        }
        case SDL_CONTROLLER_BUTTON_LEFTSTICK: {
          return GamepadButton_t::ButtonThumbLeft;
        }
        default: {
          switch (event.button) {
            case SDL_CONTROLLER_BUTTON_BACK: {
              return GamepadButton_t::ButtonMenuBack;
            }
            case SDL_CONTROLLER_BUTTON_GUIDE: {
              return GamepadButton_t::ButtonMenuGuide;
            }
            case SDL_CONTROLLER_BUTTON_START: {
              return GamepadButton_t::ButtonMenuStart;
            }
            default: {
              return GamepadButton_t::_UNKNOWN_;
            }
          }
        }
      }
    }
  }
}

NAMESPACE_END(System::Platforms::Gamepad)

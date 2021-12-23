#pragma once

////////////////////////////////////////////////////////////////////////////////
// Inline function implementations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(System::Platforms::Gamepad)

inline System::DeviceTypes::Input::GamepadAxis_t
#pragma warning(suppress: 26812) // Allow unscoped enum
ConvertGamepadAxis(SDL_GameControllerAxis axis)
{
  using namespace System::DeviceTypes::Input;

  switch (axis) {
    case SDL_CONTROLLER_AXIS_LEFTX: {
      return GamepadAxis_t::StickLeftX;
    }
    case SDL_CONTROLLER_AXIS_LEFTY: {
      return GamepadAxis_t::StickLeftY;
    }
    case SDL_CONTROLLER_AXIS_RIGHTX: {
      return GamepadAxis_t::StickRightX;
    }
    case SDL_CONTROLLER_AXIS_RIGHTY: {
      return GamepadAxis_t::StickRightY;
    }
    case SDL_CONTROLLER_AXIS_TRIGGERLEFT: {
      return GamepadAxis_t::TriggerLeft;
    }
    case SDL_CONTROLLER_AXIS_TRIGGERRIGHT: {
      return GamepadAxis_t::TriggerRight;
    }
    default: {
      return GamepadAxis_t::_UNKNOWN_;
    }
  }
}

inline System::DeviceTypes::Input::GamepadButton_t
#pragma warning(suppress: 26812) // Allow unscoped enum
ConvertGamepadButton(SDL_GameControllerButton button)
{
  using namespace System::DeviceTypes::Input;

  switch (button) {
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
      switch (button) {
        case SDL_CONTROLLER_BUTTON_RIGHTSHOULDER: {
          return GamepadButton_t::ButtonShoulderRight;
        }
        case SDL_CONTROLLER_BUTTON_LEFTSTICK: {
          return GamepadButton_t::ButtonThumbLeft;
        }
        default: {
          switch (button) {
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

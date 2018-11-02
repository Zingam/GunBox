#pragma once

////////////////////////////////////////////////////////////////////////////////
// Inline function implementations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(System::Platforms::Keyboard)

inline System::DeviceTypes::IO::ScanCode_t
ConvertScanCode(SDL_Scancode scancode)
{
  using namespace System::DeviceTypes::IO;

  switch (scancode) {
    case SDL_SCANCODE_DOWN: {
      return ScanCode_t::Arrow_Down;
    }
    case SDL_SCANCODE_LEFT: {
      return ScanCode_t::Arrow_Left;
    }
    case SDL_SCANCODE_RIGHT: {
      return ScanCode_t::Arrow_Right;
    }
    case SDL_SCANCODE_UP: {
      return ScanCode_t::Arrow_Up;
    }
    case SDL_SCANCODE_A: {
      return ScanCode_t::CH_L_A;
    }
    case SDL_SCANCODE_B: {
      return ScanCode_t::CH_L_B;
    }
    case SDL_SCANCODE_C: {
      return ScanCode_t::CH_L_C;
    }
    case SDL_SCANCODE_D: {
      return ScanCode_t::CH_L_D;
    }
    case SDL_SCANCODE_E: {
      return ScanCode_t::CH_L_E;
    }
    case SDL_SCANCODE_F: {
      return ScanCode_t::CH_L_F;
    }
    case SDL_SCANCODE_G: {
      return ScanCode_t::CH_L_G;
    }
    case SDL_SCANCODE_H: {
      return ScanCode_t::CH_L_H;
    }
    case SDL_SCANCODE_I: {
      return ScanCode_t::CH_L_I;
    }
    case SDL_SCANCODE_J: {
      return ScanCode_t::CH_L_J;
    }
    case SDL_SCANCODE_K: {
      return ScanCode_t::CH_L_K;
    }
    case SDL_SCANCODE_L: {
      return ScanCode_t::CH_L_L;
    }
    case SDL_SCANCODE_M: {
      return ScanCode_t::CH_L_M;
    }
    case SDL_SCANCODE_N: {
      return ScanCode_t::CH_L_N;
    }
    case SDL_SCANCODE_O: {
      return ScanCode_t::CH_L_O;
    }
    case SDL_SCANCODE_P: {
      return ScanCode_t::CH_L_P;
    }
    case SDL_SCANCODE_Q: {
      return ScanCode_t::CH_L_Q;
    }
    case SDL_SCANCODE_R: {
      return ScanCode_t::CH_L_R;
    }
    case SDL_SCANCODE_S: {
      return ScanCode_t::CH_L_S;
    }
    case SDL_SCANCODE_T: {
      return ScanCode_t::CH_L_T;
    }
    case SDL_SCANCODE_U: {
      return ScanCode_t::CH_L_U;
    }
    case SDL_SCANCODE_V: {
      return ScanCode_t::CH_L_V;
    }
    case SDL_SCANCODE_W: {
      return ScanCode_t::CH_L_W;
    }
    case SDL_SCANCODE_X: {
      return ScanCode_t::CH_L_X;
    }
    case SDL_SCANCODE_Y: {
      return ScanCode_t::CH_L_Y;
    }
    case SDL_SCANCODE_Z: {
      return ScanCode_t::CH_L_Z;
    }
    case SDL_SCANCODE_APOSTROPHE: {
      return ScanCode_t::CH_S_Apostrophe;
    }
    case SDL_SCANCODE_BACKSLASH: {
      return ScanCode_t::CH_S_Backslash;
    }
    case SDL_SCANCODE_COMMA: {
      return ScanCode_t::CH_S_Comma;
    }
    case SDL_SCANCODE_EQUALS: {
      return ScanCode_t::CH_S_Equals;
    }
    case SDL_SCANCODE_GRAVE: {
      return ScanCode_t::CH_S_Grave;
    }
    case SDL_SCANCODE_LEFTBRACKET: {
      return ScanCode_t::CH_S_LeftBracket;
    }
    case SDL_SCANCODE_MINUS: {
      return ScanCode_t::CH_S_Minus;
    }
    case SDL_SCANCODE_RIGHTBRACKET: {
      return ScanCode_t::CH_S_RightBracket;
    }
    case SDL_SCANCODE_SEMICOLON: {
      return ScanCode_t::CH_S_Semicolon;
    }
    case SDL_SCANCODE_SLASH: {
      return ScanCode_t::CH_S_Slash;
    }
    case SDL_SCANCODE_F1: {
      return ScanCode_t::F1;
    }
    case SDL_SCANCODE_F2: {
      return ScanCode_t::F2;
    }
    case SDL_SCANCODE_F3: {
      return ScanCode_t::F3;
    }
    case SDL_SCANCODE_F4: {
      return ScanCode_t::F4;
    }
    case SDL_SCANCODE_F5: {
      return ScanCode_t::F5;
    }
    case SDL_SCANCODE_F6: {
      return ScanCode_t::F6;
    }
    case SDL_SCANCODE_F7: {
      return ScanCode_t::F7;
    }
    case SDL_SCANCODE_F8: {
      return ScanCode_t::F8;
    }
    case SDL_SCANCODE_F9: {
      return ScanCode_t::F9;
    }
    case SDL_SCANCODE_F10: {
      return ScanCode_t::F10;
    }
    case SDL_SCANCODE_F11: {
      return ScanCode_t::F1;
    }
    case SDL_SCANCODE_F12: {
      return ScanCode_t::F1;
    }
    case SDL_SCANCODE_0: {
      return ScanCode_t::NK_0;
    }
    case SDL_SCANCODE_1: {
      return ScanCode_t::NK_1;
    }
    case SDL_SCANCODE_2: {
      return ScanCode_t::NK_2;
    }
    case SDL_SCANCODE_3: {
      return ScanCode_t::NK_3;
    }
    case SDL_SCANCODE_4: {
      return ScanCode_t::NK_4;
    }
    case SDL_SCANCODE_5: {
      return ScanCode_t::NK_5;
    }
    case SDL_SCANCODE_6: {
      return ScanCode_t::NK_6;
    }
    case SDL_SCANCODE_7: {
      return ScanCode_t::NK_7;
    }
    case SDL_SCANCODE_8: {
      return ScanCode_t::NK_8;
    }
    case SDL_SCANCODE_9: {
      return ScanCode_t::NK_9;
    }
    case SDL_SCANCODE_KP_0: {
      return ScanCode_t::NKP_0;
    }
    case SDL_SCANCODE_KP_1: {
      return ScanCode_t::NKP_1;
    }
    case SDL_SCANCODE_KP_2: {
      return ScanCode_t::NKP_2;
    }
    case SDL_SCANCODE_KP_3: {
      return ScanCode_t::NKP_3;
    }
    case SDL_SCANCODE_KP_4: {
      return ScanCode_t::NKP_4;
    }
    case SDL_SCANCODE_KP_5: {
      return ScanCode_t::NKP_5;
    }
    case SDL_SCANCODE_KP_6: {
      return ScanCode_t::NKP_6;
    }
    case SDL_SCANCODE_KP_7: {
      return ScanCode_t::NKP_7;
    }
    case SDL_SCANCODE_KP_8: {
      return ScanCode_t::NKP_8;
    }
    case SDL_SCANCODE_KP_9: {
      return ScanCode_t::NKP_9;
    }
    case SDL_SCANCODE_KP_DIVIDE: {
      return ScanCode_t::NKP_Divide;
    }
    case SDL_SCANCODE_KP_MULTIPLY: {
      return ScanCode_t::NKP_Multiply;
    }
    case SDL_SCANCODE_KP_MINUS: {
      return ScanCode_t::NKP_Minus;
    }
    case SDL_SCANCODE_KP_PLUS: {
      return ScanCode_t::NKP_Plus;
    }
    case SDL_SCANCODE_KP_ENTER: {
      return ScanCode_t::NKP_Enter;
    }
    case SDL_SCANCODE_KP_PERIOD: {
      return ScanCode_t::NKP_Period;
    }
    case SDL_SCANCODE_LALT: {
      return ScanCode_t::SK_AltLeft;
    }
    case SDL_SCANCODE_RALT: {
      return ScanCode_t::SK_AltRight;
    }
    case SDL_SCANCODE_BACKSPACE: {
      return ScanCode_t::SK_Backspace;
    }
    case SDL_SCANCODE_CAPSLOCK: {
      return ScanCode_t::SK_CapsLock;
    }
    case SDL_SCANCODE_DELETE: {
      return ScanCode_t::SK_Del;
    }
    case SDL_SCANCODE_END: {
      return ScanCode_t::SK_End;
    }
    case SDL_SCANCODE_RETURN: {
      return ScanCode_t::SK_Enter;
    }
    case SDL_SCANCODE_ESCAPE: {
      return ScanCode_t::SK_Esc;
    }
    case SDL_SCANCODE_HOME: {
      return ScanCode_t::SK_Home;
    }
    case SDL_SCANCODE_INSERT: {
      return ScanCode_t::SK_Ins;
    }
    case SDL_SCANCODE_LCTRL: {
      return ScanCode_t::SK_CtrlLeft;
    }
    case SDL_SCANCODE_RCTRL: {
      return ScanCode_t::SK_CtrlRight;
    }
    case SDL_SCANCODE_LSHIFT: {
      return ScanCode_t::SK_ShiftLeft;
    }
    case SDL_SCANCODE_RSHIFT: {
      return ScanCode_t::SK_ShiftRight;
    }
    case SDL_SCANCODE_SPACE: {
      return ScanCode_t::SK_Space;
    }
    case SDL_SCANCODE_TAB: {
      return ScanCode_t::SK_Tab;
    }
    case SDL_SCANCODE_PAGEDOWN: {
      return ScanCode_t::SK_PageDown;
    }
    case SDL_SCANCODE_PAGEUP: {
      return ScanCode_t::SK_PageUp;
    }
    default: {
      return ScanCode_t::_UNKNOWN_;
    }
  }
}

inline System::DeviceTypes::IO::Key_t
ConvertToKey(SDL_KeyboardEvent event)
{
  using namespace System::DeviceTypes::IO;

  auto keyCode = static_cast<KeyCode_t>(event.keysym.sym);
  auto modifier = static_cast<KeyModifier_t>(event.keysym.mod);
  auto scanCode = ConvertScanCode(event.keysym.scancode);

  return { keyCode, modifier, scanCode };
}

NAMESPACE_END(System::Platforms::Keyboard)

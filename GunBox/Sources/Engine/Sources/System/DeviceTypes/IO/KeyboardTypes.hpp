#pragma once

// Project headers - BASE
#include "Common/Macros/Base.hpp"

// C Standard Library
#include <cstdint>

NAMESPACE_BEGIN(System::DeviceTypes::IO)

using KeyCode = std::int32_t;

enum class KeyModifier
{
  None,
  Alt, // Left or Right
  AltGr,
  AltLeft,
  AltRight,
  CapsLock,
  Ctrl, // Left or Right
  CtrlLeft,
  CtrlRight,
  Num,
  Shift, // Left or Right
  ShiftLeft,
  ShiftRight,
  WindowsKey, // Left or Right
  WindowsKeyLeft,
  WindowsKeyRight
};

enum class ScanCode
{
  F1,
  F2,
  F3,
  F4,
  F5,
  F6,
  F7,
  F8,
  F9,
  F10,
  F11,
  F12,
  CH_L_A,
  CH_L_B,
  CH_L_C,
  CH_L_D,
  CH_L_E,
  CH_L_F,
  CH_L_G,
  CH_L_H,
  CH_L_I,
  CH_L_J,
  CH_L_K,
  CH_L_L,
  CH_L_M,
  CH_L_N,
  CH_L_O,
  CH_L_P,
  CH_L_Q,
  CH_L_R,
  CH_L_S,
  CH_L_T,
  CH_L_U,
  CH_L_V,
  CH_L_W,
  CH_L_X,
  CH_L_Y,
  CH_L_Z,
  CH_Backslash,
  CH_Comma,
  CH_Equal,
  CH_LeftBracket,
  CH_Minus,
  CH_Period,
  CH_RightBracket,
  CH_Semicolon,
  CH_Slash,
  CH_Quote,
  NK_0,
  NK_1,
  NK_2,
  NK_3,
  NK_4,
  NK_5,
  NK_6,
  NK_7,
  NK_8,
  NK_9,
  NKP_0,
  NKP_1,
  NKP_2,
  NKP_3,
  NKP_4,
  NKP_5,
  NKP_6,
  NKP_7,
  NKP_8,
  NKP_9,
  NKP_Divide,
  NKP_Multiply,
  NKP_Minus,
  NKP_Plus,
  NKP_Enter,
  NKP_Period,
  ArrowDown,
  ArrowLeft,
  ArrowRight,
  ArrowUp,
  SK_Backspace,
  SK_Del,
  SK_End,
  SK_Esc,
  SK_Home,
  SK_Ins,
  SK_Space,
  SK_PageDown,
  SK_PageUp,
};

NAMESPACE_END(System::DeviceTypes::IO)

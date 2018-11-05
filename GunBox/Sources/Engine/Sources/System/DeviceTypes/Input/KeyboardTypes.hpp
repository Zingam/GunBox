#pragma once

// BASE MACROS header
#include "Common/Macros/Base.hpp"

// C Standard Library
#include <cstdint>

NAMESPACE_BEGIN(System::DeviceTypes::Input)

using KeyCode_t = std::int32_t;

////////////////////////////////////////////////////////////////////////////////

enum class KeyModifier_t
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
  WindowsKeyRight,
  __ElementsCount__
};

constexpr auto KeyModifier_t_ElementsCount =
  EnumCast(KeyModifier_t::__ElementsCount__);

////////////////////////////////////////////////////////////////////////////////

enum class ScanCode_t
{
  Arrow_Down,
  Arrow_Left,
  Arrow_Right,
  Arrow_Up,
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
  CH_S_Apostrophe,
  CH_S_Backslash,
  CH_S_Comma,
  CH_S_Equals,
  CH_S_Grave,
  CH_S_LeftBracket,
  CH_S_Minus,
  CH_S_Period,
  CH_S_RightBracket,
  CH_S_Semicolon,
  CH_S_Slash,
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
  SK_AltLeft,
  SK_AltRight,
  SK_Backspace,
  SK_CapsLock,
  SK_CtrlLeft,
  SK_CtrlRight,
  SK_Del,
  SK_End,
  SK_Enter,
  SK_Esc,
  SK_Home,
  SK_Ins,
  SK_ShiftLeft,
  SK_ShiftRight,
  SK_Space,
  SK_Tab,
  SK_PageDown,
  SK_PageUp,
  _UNKNOWN_,
  __ElementsCount__
};

constexpr auto ScanCode_t_ElementsCount =
  EnumCast(ScanCode_t::__ElementsCount__);

////////////////////////////////////////////////////////////////////////////////

struct Key_t
{
  KeyCode_t KeyCode;
  KeyModifier_t KeyModifier;
  ScanCode_t ScanCode;
};

NAMESPACE_END(System::DeviceTypes::Input)

#pragma once

// BASE MACROS header
#include "Common/Macros/Base.hpp"

NAMESPACE_BEGIN(GunBox)

enum class Commands_MainMenu_t
{
  Accept,
  Back,
  DeviceAdded,
  DeviceRemoved,
  MoveDown,
  MoveLeft,
  MoveRight,
  MoveUp,
  _NULL_,
  __ElementsCount__
};

constexpr auto Commands_MainMenu_t_ElementsCount =
  EnumCast(Commands_MainMenu_t::__ElementsCount__);

NAMESPACE_END(GunBox)

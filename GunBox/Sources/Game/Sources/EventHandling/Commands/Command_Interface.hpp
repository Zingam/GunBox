#pragma once

// BASE MACROS header
#include "Common/Macros/Base.hpp"

NAMESPACE_BEGIN(GunBox)

class Command_Interface
{
public:
  virtual ~Command_Interface() = 0;

public:
  virtual auto Execute() -> void {};
};

NAMESPACE_END(GunBox)

#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

// C Standard Library
#include <cstdint>

NAMESPACE_BEGIN(GunBox)

class Command_Interface
{
public:
  virtual ~Command_Interface() = 0;

public:
  virtual auto Execute(std::int32_t id = -1) -> void = 0;
};

NAMESPACE_END(GunBox)

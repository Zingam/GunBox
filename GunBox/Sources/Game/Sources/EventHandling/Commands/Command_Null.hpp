#pragma once

// BASE MACROS header
#include "Common/Macros/Base.hpp"

// Project headers
#include "EventHandling/Commands/Command_Interface.hpp"

NAMESPACE_BEGIN(GunBox)

class Command_Null final : public Command_Interface
{
public:
  ~Command_Null() final;

public:
  auto Execute(std::int32_t id) -> void final;
};

NAMESPACE_END(GunBox)

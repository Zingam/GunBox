#pragma once

// Project headers - Common
#include "Common/Macros/Base.hpp"

NAMESPACE_START(System::EventHandlers)

struct EventHandler
{
  virtual ~EventHandler() = 0;
  virtual auto Process(void* event) -> bool = 0;
};

NAMESPACE_END(System::EventHandlers)

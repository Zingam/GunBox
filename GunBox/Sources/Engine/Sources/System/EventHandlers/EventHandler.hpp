#pragma once

// Project headers - Common
#include "Common/Macros/Base.hpp"

union SDL_Event;

NAMESPACE_BEGIN(System::EventHandlers)

struct EventHandler
{
  virtual ~EventHandler() = 0;
  virtual auto Process(SDL_Event const& event) -> bool = 0;
};

NAMESPACE_END(System::EventHandlers)

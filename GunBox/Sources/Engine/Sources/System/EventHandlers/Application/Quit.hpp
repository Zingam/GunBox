#pragma once

// Project headers - Common
#include "Common/Macros/Base.hpp"

// Project headers - System
#include "System/EventHandlers/EventHandler.hpp"

NAMESPACE_BEGIN(System::EventHandlers::Application)

struct Quit : public EventHandler
{
  virtual ~Quit() final;
  virtual auto Process(SDL_Event const& event) -> bool final;
};

NAMESPACE_END(System::EventHandlers::Application)

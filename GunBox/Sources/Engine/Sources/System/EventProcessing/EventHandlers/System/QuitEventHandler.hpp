#pragma once

// Project headers - BASE
#include "Common/Macros/Base.hpp"

// Project headers - System
#include "System/EventProcessing/EventHandlers/EventHandler.hpp"

NAMESPACE_BEGIN(System::EventHandlers::System)

class QuitEventHandler : public EventHandler
{
public:
  ~QuitEventHandler() final;

public:
  auto Process(SDL_Event const& event) -> bool final;
};

NAMESPACE_END(System::EventHandlers::System)

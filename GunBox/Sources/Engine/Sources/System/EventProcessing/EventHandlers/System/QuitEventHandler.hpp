#pragma once

// Project headers - BASE
#include "Common/Macros/Base.hpp"

// Project headers - System
#include "System/EventProcessing/EventHandlers/EventHandler.hpp"

////////////////////////////////////////////////////////////////////////////////
// Forward declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(System)

class SystemEventProcessor;

NAMESPACE_END(System)

////////////////////////////////////////////////////////////////////////////////
// Class declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(System::EventHandlers)

class QuitEventHandler : public EventHandler
{
public:
  QuitEventHandler(SystemEventProcessor& systemEventProcessor);

  ~QuitEventHandler() final;

public:
  auto Process(SDL_Event const& event) -> bool final;

private:
  SystemEventProcessor& systemEventProcessor;
};

NAMESPACE_END(System::EventHandlers)

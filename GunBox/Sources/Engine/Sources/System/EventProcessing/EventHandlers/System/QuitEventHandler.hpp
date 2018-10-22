#pragma once

// Project headers - BASE
#include "Common/Macros/Base.hpp"

// Project headers - System
#include "System/EventProcessing/EventHandlers/EventHandler.hpp"

////////////////////////////////////////////////////////////////////////////////
// Forward declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(System::EventProcessing)

class SystemEventProcessor;

NAMESPACE_END(System::EventProcessing)

////////////////////////////////////////////////////////////////////////////////
// Class declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(System::EventHandlers)

class QuitEventHandler : public EventHandler
{
public:
  QuitEventHandler(
    System::EventProcessing::SystemEventProcessor& systemEventProcessor);

  ~QuitEventHandler() final;

public:
  auto Process(SDL_Event const& event) -> bool final;

private:
  System::EventProcessing::SystemEventProcessor& systemEventProcessor;
};

NAMESPACE_END(System::EventHandlers)

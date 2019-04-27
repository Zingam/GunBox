#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

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

class ApplicationResume_EventHandler : public EventHandler
{
public:
  ApplicationResume_EventHandler(
    System::EventProcessing::SystemEventProcessor& systemEventProcessor);

  ~ApplicationResume_EventHandler() final;

public:
  auto Process(SDL_Event const& event) -> bool final;

private:
  System::EventProcessing::SystemEventProcessor& systemEventProcessor;
};

NAMESPACE_END(System::EventHandlers)

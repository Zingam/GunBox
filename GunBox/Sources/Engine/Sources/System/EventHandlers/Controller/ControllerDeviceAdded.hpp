#pragma once

// Project headers - Common
#include "Common/Macros/Base.hpp"

// Project headers - System
#include "System/EventHandlers/EventHandler.hpp"
#include "System/InputProcessor.hpp"

NAMESPACE_START(System::EventHandlers::Controller)

class DeviceAdded : public EventHandler
{
public:
  DeviceAdded(InputProcessor& inputProcessor);

public:
  auto Process(SDL_Event const& event) -> bool final;

private:
  InputProcessor& inputProcessor;
};

NAMESPACE_END(System::EventHandlers::Controller)

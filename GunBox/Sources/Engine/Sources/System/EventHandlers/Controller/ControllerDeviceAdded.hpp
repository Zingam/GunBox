#pragma once

// Project headers - Common
#include "Common/Macros/Base.hpp"

// Project headers - System
#include "System/EventHandlers/EventHandler.hpp"

NAMESPACE_START(System::EventHandlers::Controller)

struct DeviceAdded : public EventHandler
{
};

NAMESPACE_END(System::EventHandlers::Controller)

#pragma once

// C Standard Library
#include <cassert>

////////////////////////////////////////////////////////////////////////////////
// Inline method implementations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(System)

inline void
SystemEventProcessorAccessor::Quit(SystemEventProcessor& systemEventProcessor)
{
  assert(
    (nullptr != systemEventProcessor.cbQuit_UPtr) &&
    "The callback is not initialized");

  (*systemEventProcessor.cbQuit_UPtr)();
}

NAMESPACE_END(System)

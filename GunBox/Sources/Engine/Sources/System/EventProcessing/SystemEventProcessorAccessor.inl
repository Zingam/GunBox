#pragma once

// C Standard Library
#include <cassert>

////////////////////////////////////////////////////////////////////////////////
// Inline implementations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(System::EventProcessing)

inline void
SystemEventProcessorAccessor::ApplicationQuit(
  SystemEventProcessor& systemEventProcessor)
{
  assert(
    (nullptr != systemEventProcessor.cbApplicationQuit_UPtr) &&
    "The callback is not initialized");

  (*systemEventProcessor.cbApplicationQuit_UPtr)();
}

inline void
SystemEventProcessorAccessor::ApplicationResume(
  SystemEventProcessor& systemEventProcessor)
{
  assert(
    (nullptr != systemEventProcessor.cbApplicationResume_UPtr) &&
    "The callback is not initialized");

  (*systemEventProcessor.cbApplicationResume_UPtr)();
}

inline void
SystemEventProcessorAccessor::ApplicationSuspend(
  SystemEventProcessor& systemEventProcessor)
{
  assert(
    (nullptr != systemEventProcessor.cbApplicationSuspend_UPtr) &&
    "The callback is not initialized");

  (*systemEventProcessor.cbApplicationSuspend_UPtr)();
}

NAMESPACE_END(System::EventProcessing)

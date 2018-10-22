#pragma once

// Project headers - BASE
#include "Common/Macros/Base.hpp"

// Project headers - System
#include "System/EventProcessing/SystemEventProcessor.hpp"

////////////////////////////////////////////////////////////////////////////////
// Forward declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(System::EventHandlers)

class QuitEventHandler;

NAMESPACE_END(System::EventHandlers)

////////////////////////////////////////////////////////////////////////////////
// Class declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(System::EventProcessing)

class SystemEventProcessorAccessor
{
private:
  // clang-format off
  static inline auto Quit(SystemEventProcessor& systemEventProcessor)
    -> void;
  // clang-format on

private:
  friend class System::EventHandlers::QuitEventHandler;
};

NAMESPACE_END(System::EventProcessing)

////////////////////////////////////////////////////////////////////////////////
// Inline method implementations
////////////////////////////////////////////////////////////////////////////////

#include "SystemEventProcessorAccessor.inl"

////////////////////////////////////////////////////////////////////////////////

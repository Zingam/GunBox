#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

// Project headers - Common
#include "Common/SimpleDelegate.hpp"
// Project headers - System
#include "System/EventProcessing/SystemEventCallbacks_Interface.hpp"

// C++ Standard Library
#include <memory>

////////////////////////////////////////////////////////////////////////////////
// Class declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(System::EventProcessing)

class SystemEventProcessor
{
public:
  auto InitializeCallbacks(SystemEventCallbacks_Interface& systemEventCallbacks)
    -> void;

  // Callbacks
private:
  // clang-format off
  std::unique_ptr<SimpleDelegate<SystemEventCallbacks_Interface,
    decltype(&SystemEventCallbacks_Interface::Quit)>>
    cbQuit_UPtr;
  // clang-format on

private:
  friend class SystemEventProcessorAccessor;
};

NAMESPACE_END(System::EventProcessing)

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
  // Methods
public:
  auto InitializeCallbacks(SystemEventCallbacks_Interface& systemEventCallbacks)
    -> void;

  // Callbacks
private:
  // clang-format off
  std::unique_ptr<SimpleDelegate<SystemEventCallbacks_Interface,
    decltype(&SystemEventCallbacks_Interface::ApplicationResume)>>
    cbApplicationResume_UPtr;
  std::unique_ptr<SimpleDelegate<SystemEventCallbacks_Interface,
    decltype(&SystemEventCallbacks_Interface::ApplicationSuspend)>>
    cbApplicationSuspend_UPtr;
  std::unique_ptr<SimpleDelegate<SystemEventCallbacks_Interface,
    decltype(&SystemEventCallbacks_Interface::ApplicationQuit)>>
    cbApplicationQuit_UPtr;
  // clang-format on

  // Data members
private:
  friend class SystemEventProcessorAccessor;
};

NAMESPACE_END(System::EventProcessing)

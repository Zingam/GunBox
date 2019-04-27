// Self
#include "SystemEventCallbacks.hpp"

// Project headers
#include "EventHandling/Commands/Commander_Interface.hpp"

// Engine headers - Logger
#include "Logger/LogAPI.hpp"

NAMESPACE_BEGIN(GunBox)

////////////////////////////////////////////////////////////////////////////////
// Constructors & Destructors
////////////////////////////////////////////////////////////////////////////////

SystemEventCallbacks::~SystemEventCallbacks() = default;

////////////////////////////////////////////////////////////////////////////////
// Virtual methods
////////////////////////////////////////////////////////////////////////////////

auto
SystemEventCallbacks::ApplicationResume() -> void
{
  reLog("[Application Lifecycle Event] -> Resume");

  commander->SystemEvent(Application::State_t::Resuming);
};

auto
SystemEventCallbacks::ApplicationSuspend() -> void
{
  reLog("[Application Lifecycle Event] -> Suspend");

  commander->SystemEvent(Application::State_t::Suspending);
};

auto
SystemEventCallbacks::ApplicationQuit() -> void
{
  reLog("[Application Lifecycle Event] -> Quit");

  commander->SystemEvent(Application::State_t::Quitting);
};

NAMESPACE_END(GunBox)

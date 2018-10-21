// Self
#include "SystemEventProcessor.hpp"

NAMESPACE_BEGIN(System)

SystemEventProcessor ::~SystemEventProcessor() {}

auto
SystemEventProcessor::SetSystemEventCallbacksObject(
  std::shared_ptr<SystemEventCallbacks> const systemEventCallbacks) -> void
{
  SetSystemEventCallbacksObject(*systemEventCallbacks);
}

auto
SystemEventProcessor::SetSystemEventCallbacksObject(
  SystemEventCallbacks& systemEventCallbacks) -> void
{
  cbQuit_UPtr =
    make_unique_delegate(systemEventCallbacks, &SystemEventCallbacks::Quit);
}

NAMESPACE_END(System)

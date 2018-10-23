// Self
#include "SystemEventProcessor.hpp"

NAMESPACE_BEGIN(System::EventProcessing)

SystemEventProcessor ::~SystemEventProcessor() {}

auto
SystemEventProcessor::InitializeCallbacks(
  std::shared_ptr<SystemEventCallbacks> const systemEventCallbacks) -> void
{
  InitializeCallbacks(*systemEventCallbacks);
}

auto
SystemEventProcessor::InitializeCallbacks(
  SystemEventCallbacks& systemEventCallbacks) -> void
{
  cbQuit_UPtr =
    make_unique_delegate(systemEventCallbacks, &SystemEventCallbacks::Quit);
}

NAMESPACE_END(System::EventProcessing)

// Self
#include "SystemEventProcessor.hpp"

NAMESPACE_BEGIN(System::EventProcessing)

SystemEventProcessor ::~SystemEventProcessor() {}

auto
SystemEventProcessor::InitializeCallbacks(
  std::shared_ptr<SystemEventCallbacks_Interface> const systemEventCallbacks) -> void
{
  InitializeCallbacks(*systemEventCallbacks);
}

auto
SystemEventProcessor::InitializeCallbacks(
  SystemEventCallbacks_Interface& systemEventCallbacks) -> void
{
  cbQuit_UPtr =
    make_unique_delegate(systemEventCallbacks, &SystemEventCallbacks_Interface::Quit);
}

NAMESPACE_END(System::EventProcessing)

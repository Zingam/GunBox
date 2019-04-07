// Self
#include "SystemEventProcessor.hpp"

NAMESPACE_BEGIN(System::EventProcessing)

auto
SystemEventProcessor::InitializeCallbacks(
  SystemEventCallbacks_Interface& systemEventCallbacks) -> void
{
  cbQuit_UPtr =
    make_unique_delegate(systemEventCallbacks, &SystemEventCallbacks_Interface::Quit);
}

NAMESPACE_END(System::EventProcessing)

// Self
#include "SystemEventProcessor.hpp"

NAMESPACE_BEGIN(System::EventProcessing)

auto
SystemEventProcessor::InitializeCallbacks(
  SystemEventCallbacks_Interface& systemEventCallbacks) -> void
{
  // clang-format off
  cbApplicationQuit_UPtr = make_unique_delegate(
    systemEventCallbacks, &SystemEventCallbacks_Interface::ApplicationQuit);
  cbApplicationResume_UPtr = make_unique_delegate(
    systemEventCallbacks, &SystemEventCallbacks_Interface::ApplicationResume);
  cbApplicationSuspend_UPtr = make_unique_delegate(
    systemEventCallbacks, &SystemEventCallbacks_Interface::ApplicationSuspend);
  // clang-format on
}

NAMESPACE_END(System::EventProcessing)

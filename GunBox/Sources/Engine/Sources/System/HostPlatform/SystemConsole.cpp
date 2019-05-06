// Self
#include "SystemConsole.hpp"

NAMESPACE_BEGIN(System::HostPlatformClasses)

void
SystemConsole::EnableInput() const
{
  o_ptr->EnableInput();
}

void
SystemConsole::Hide() const
{
  o_ptr->Hide();
}

void
SystemConsole::Pause() const
{
  o_ptr->Pause();
}

void
SystemConsole::Show() const
{
  o_ptr->Show();
}

NAMESPACE_END(System::HostPlatformClasses)

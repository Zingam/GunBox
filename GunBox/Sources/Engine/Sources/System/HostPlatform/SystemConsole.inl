#pragma once

////////////////////////////////////////////////////////////////////////////////
// Inline method implementations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(System::HostPlatformClasses)

inline void
SystemConsole::Hide()
{
  o_ptr->Hide();
}

inline void
SystemConsole::Show()
{
  o_ptr->Show();
}

NAMESPACE_END(System::HostPlatformClasses)

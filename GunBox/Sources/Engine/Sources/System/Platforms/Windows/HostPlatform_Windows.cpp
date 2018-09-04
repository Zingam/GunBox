// Self
#include "HostPlatform_Windows.hpp"

// System headers
#undef NOMENUS
#undef NOSYSCOMMANDS
#undef NOUSER
#include <Windows.h>

// C Standard Library
#include <cstdio>

NAMESPACE_START(System)

void
HostPlatform_Windows::HideSystemConsole()
{
  fclose(stdout);
  FreeConsole();
}

void
HostPlatform_Windows::ShowSystemConsole()
{
  // Create a system console window for the current process
  AllocConsole();
  AttachConsole(GetCurrentProcessId());
  // Disable the close menu button to prevent the system console window from
  // closing the application if clicked
  auto consoleHandle = GetConsoleWindow();
  HMENU hmenu = GetSystemMenu(consoleHandle, FALSE);
  EnableMenuItem(hmenu, SC_CLOSE, MF_GRAYED);
  // Redirect the standard output stream to the system console window
  FILE* filestream_ptr;
  freopen_s(&filestream_ptr, "CON", "w", stdout);
}

NAMESPACE_END(System)

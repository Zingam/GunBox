// Self
#include "SystemConsole_Windows.hpp"

// System headers
#undef NOMENUS
#undef NOSYSCOMMANDS
#undef NOUSER
#include <Windows.h>

// C Standard Library
#include <cstdlib>
#include <cstdio>

NAMESPACE_BEGIN(System::HostPlatformClasses)

void
SystemConsole_Windows::Hide() const
{
  fclose(stderr);
  fclose(stdin);
  fclose(stdout);

  FreeConsole();
}

void
SystemConsole_Windows::Pause() const
{
  system("pause");
}

void
SystemConsole_Windows::Show() const
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
  freopen_s(&filestream_ptr, "CON", "w", stderr);
  freopen_s(&filestream_ptr, "CON", "r", stdin);
  freopen_s(&filestream_ptr, "CON", "w", stdout);
}

NAMESPACE_END(System::HostPlatformClasses)

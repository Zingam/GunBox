// Self
#include "SystemConsole_Windows.hpp"

// System headers
#undef NOMENUS
#undef NOSYSCOMMANDS
#undef NOUSER
#include <Windows.h>

// C Standard Library
#include <cassert>
#include <cstdio>
#include <cstdlib>

NAMESPACE_BEGIN(System::HostPlatformClasses)

void
SystemConsole_Windows::EnableInput()
{
  assert(!isShown && "System console is already shown!");

  isInputEnabled = true;
}

void
SystemConsole_Windows::Hide()
{
  assert(isShown && "System console is not shown!");

  // Close the standard IO streams
  fclose(stderr);
  fclose(stdout);
  if (isInputEnabled) {
    fclose(stdin);
  }

  FreeConsole();

  isShown = false;
}

void
SystemConsole_Windows::Pause() const
{
  assert(isShown && "System console is not shown!");

  system("pause");
}

void
SystemConsole_Windows::Show()
{
  assert(!isShown && "System console is already shown!");

  // Create a system console window for the current process
  AllocConsole();
  AttachConsole(GetCurrentProcessId());

  // Disable the close menu button to prevent the system console window from
  // closing the application if clicked
  auto consoleHandle = GetConsoleWindow();
  HMENU hmenu = GetSystemMenu(consoleHandle, FALSE);
  EnableMenuItem(hmenu, SC_CLOSE, MF_GRAYED);

  // Redirect the standard IO streams to the system console window
  FILE* filestream_ptr = nullptr;
  freopen_s(&filestream_ptr, "CON", "w", stderr);
  freopen_s(&filestream_ptr, "CON", "w", stdout);
  if (!isInputEnabled) {
    freopen_s(&filestream_ptr, "CON", "r", stdin);
  }

  isShown = true;
}

NAMESPACE_END(System::HostPlatformClasses)

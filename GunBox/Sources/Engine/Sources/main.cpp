// Project headers - Application Entry point
#include "main.hpp"

// Project headers - Application
#include "Application/CoreApplication.hpp"
#include "Application/CoreApplicationFactory.hpp"

////////////////////////////////////////////////////////////////////////////////
// Main entry point
////////////////////////////////////////////////////////////////////////////////

int
main(int argc, char* argv[])
{
  auto exitCode = Application::ExitCode::NoError;

  // Initialize
  auto application = Application::Create();
  auto isRunning = application->IsAlreadyRunning();

  if (!isRunning) {
    application->ProcessCommandLineArgs(argc, argv);

    exitCode = application->Initialize();
    if (Application::ExitCode::NoError == exitCode) {
      // Execute the Main loop
      exitCode = application->Execute();
      // TODO: Error reporting on execution failure
    }
    application->Finalize();
  }

  return static_cast<int>(exitCode);
}

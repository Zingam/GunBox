// Project headers - Application Entry point
#include "main.hpp"

// Project headers - Application
#include "Application/CoreApplication.hpp"
#include "Application/CoreApplicationFactory.hpp"

int
main(int argc, char* argv[])
{
  // Initialize
  auto& application = Application::Create();
  application.ProcessCommandLineArgs(argc, argv);
  application.Initialize();
  // Execute the Main loop
  auto exitResult = application.Execute();
  application.Finalize();

  return static_cast<int>(exitResult);
}

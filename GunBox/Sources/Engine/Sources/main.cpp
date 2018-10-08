// Project headers - Common
#include "Common/Macros/Base.hpp"

// Project headers - Application
#include "Application/CommandLineArgs.hpp"
#include "Application/CoreApplication.hpp"
#include "Application/CoreApplicationFactory.hpp"

// Third party libraries
#include <SDL.h>

// C++ Standard library
#include <sstream>

int
main(int argc, char* argv[])
{
  Application::CommandLineArgs commandLineArgs;
  auto hasParsingError = commandLineArgs.Parse(argc, argv);
  if (hasParsingError) {
    std::stringstream errorMessage;
    errorMessage << "Error parsing command line arguments.\n";
    errorMessage << hasParsingError.value() << "\n";
    SDL_ShowSimpleMessageBox(
      SDL_MESSAGEBOX_ERROR, "GunBox", errorMessage.str().c_str(), nullptr);

    return -1;
  }

  auto& application = Application::Create("GunBox", commandLineArgs);
  SDL_Log("Initalizing: %s", application.Name().c_str());
  auto exitResult = application.Execute();

  return static_cast<int>(exitResult);
}

// Self
#include "CoreApplication.hpp"

// Third party libraries
#include <SDL.h>

// C++ Standard library
#include <sstream>

NAMESPACE_START(Application)

////////////////////////////////////////////////////////////////////////////////
// Constructors & Destructors
////////////////////////////////////////////////////////////////////////////////

CoreApplication::CoreApplication(ProductInfo const& productInfo)
  : productInfo{ std::move(productInfo) }
{
  preferences = std::make_unique<Preferences>(this->productInfo);
}

CoreApplication::~CoreApplication() {}

////////////////////////////////////////////////////////////////////////////////
// Properties
////////////////////////////////////////////////////////////////////////////////

ProductInfo const&
CoreApplication::Info() const
{
  return productInfo;
}

////////////////////////////////////////////////////////////////////////////////
// Virtual methods
////////////////////////////////////////////////////////////////////////////////

auto
CoreApplication::Finalize() -> void
{
#if defined(_DEBUG)
  SDL_Log("Finalizing: %s", productInfo.Name().c_str());

  if (nullptr != commandLineArgs) {
    if (commandLineArgs->ShowSystemConsole()) {
      hostPlatform.HideSystemConsole();
    }
  }
#endif
}

auto
CoreApplication::Initialize() -> void
{
#if defined(_DEBUG)
  if (nullptr != commandLineArgs) {
    if (commandLineArgs->ShowSystemConsole()) {
      hostPlatform.ShowSystemConsole();
    }

    SDL_Log("Initalizing: %s", productInfo.Name().c_str());

    if (commandLineArgs->Resolution()) {
      auto height = commandLineArgs->Resolution().value().Height;
      auto width = commandLineArgs->Resolution().value().Width;
      SDL_Log("Desired resolution: %dx%d", width, height);
    }
  } else {
    SDL_Log("Initalizing: %s", productInfo.Name().c_str());
  }
#endif

  auto hasLoadingError = preferences->LoadFromFile();
  if (hasLoadingError) {
    std::stringstream errorMessage;
    errorMessage << "Error loading preferences from file:\n";
    errorMessage << "    " << hasLoadingError.value() << "\n";
    errorMessage << "Using default values!";

    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
                             productInfo.Name().c_str(),
                             errorMessage.str().c_str(),
                             nullptr);

    // Main window
    preferences->SetMainWindowDefaultValues();
  }
}

void
CoreApplication::ProcessCommandLineArgs(int argc, char** argv)
{
  commandLineArgs = std::make_unique<CommandLineArgs>();
  auto hasParsingError = commandLineArgs->Parse(argc, argv);
  if (hasParsingError) {
    std::stringstream errorMessage;
    errorMessage << "Error parsing command line arguments.\n";
    errorMessage << hasParsingError.value() << "\n";
    SDL_ShowSimpleMessageBox(
      SDL_MESSAGEBOX_ERROR, "GunBox", errorMessage.str().c_str(), nullptr);

    commandLineArgs.release();
  }
}

NAMESPACE_END(Application)

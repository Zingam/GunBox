// Self
#include "CoreApplication.hpp"

// Project headers - Base
#include "Common/Macros/Logging.hpp"

// Project headers - Renderer/Graphics
#include "Renderer/Graphics/GraphicsRendererFactory.hpp"
#include "Renderer/Graphics/GraphicsRenderer_Interface.hpp"

// Third party libraries
#include <SDL.h>

// C++ Standard library
#include <sstream>

NAMESPACE_BEGIN(Application)

////////////////////////////////////////////////////////////////////////////////
// Constructors & Destructors
////////////////////////////////////////////////////////////////////////////////

CoreApplication::CoreApplication(ApplicationInfo const& info)
  : info{ std::move(info) }
  , preferences{ std::make_unique<Preferences>(this->info) }
{}

CoreApplication::~CoreApplication() {}

////////////////////////////////////////////////////////////////////////////////
// Virtual methods
////////////////////////////////////////////////////////////////////////////////

void
CoreApplication::Finalize()
{
#if defined(_DEBUG)
  LogInfo("Finalizing: %s", info.Title().c_str());

  if (nullptr != commandLineArgs) {
    if (commandLineArgs->ShowSystemConsole()) {
      hostPlatform.SystemConsole().Hide();
    }
  }
#endif
  
  hostPlatform.SubSystems().Finalize();

  auto hasSaveError = preferences->SaveToFile();
  if (hasSaveError) {
    std::stringstream errorMessage;
    errorMessage << "Unable to save preferences!\n";
    errorMessage << "    Error:\n";
    errorMessage << hasSaveError.value();
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
                             info.Title().c_str(),
                             errorMessage.str().c_str(),
                             nullptr);
  }
}

Application::ExitCode
CoreApplication::Initialize()
{
#if defined(_DEBUG)
  if (nullptr != commandLineArgs) {
    if (commandLineArgs->ShowSystemConsole()) {
      hostPlatform.SystemConsole().Show();
    }

    LogInfo("Initalizing: %s", info.Title().c_str());

    if (commandLineArgs->Resolution()) {
      auto height = commandLineArgs->Resolution().value().Height;
      auto width = commandLineArgs->Resolution().value().Width;
      LogInfo("Desired resolution: %dx%d", width, height);
    }
  } else {
    LogInfo("Initalizing: %s", info.Title().c_str());
  }
#endif

  auto hasLoadError = preferences->LoadFromFile();
  if (hasLoadError) {
    std::stringstream errorMessage;
    errorMessage << "Error loading preferences from file:\n";
    errorMessage << "    " << hasLoadError.value() << "\n";
    errorMessage << "Using default values!";

    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
                             info.Title().c_str(),
                             errorMessage.str().c_str(),
                             nullptr);

    // Main window
    preferences->SetMainWindowDefaultValues();
  }

  if (!hostPlatform.SubSystems().Initialize()) {
    return Application::ExitCode::InitializationError;
  }

  graphicsRenderer =
    Renderer::Graphics::Create(info, *preferences, hostPlatform);

  return Application::ExitCode::NoError;
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

// Self
#include "CoreApplication.hpp"

// BASE MACROS header
#include "Common/Macros/Logging.hpp"

// Project headers - Renderer/Graphics
#include "Renderer/Graphics/GraphicsRendererFactory.hpp"
#include "Renderer/Graphics/GraphicsRenderer_Interface.hpp"

// Third party libraries
#include <SDL.h>

// C++ Standard Library
#include <sstream>

NAMESPACE_BEGIN(Application)

////////////////////////////////////////////////////////////////////////////////
// Constructors & Destructors
////////////////////////////////////////////////////////////////////////////////

CoreApplication::CoreApplication(ApplicationInfo const& info)
  : info{ std::move(info) }
  , preferences{ std::make_unique<Preferences>(this->info) }
{
  hostPlatform.FileSystem().Initialize(info);
}

CoreApplication::~CoreApplication() {}

////////////////////////////////////////////////////////////////////////////////
// Properties
////////////////////////////////////////////////////////////////////////////////

ApplicationInfo const&
CoreApplication::Info() const
{
  return info;
}

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
    SDL_ShowSimpleMessageBox(
      SDL_MESSAGEBOX_ERROR,
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
  }
#endif

  LogInfo("Initializing: %s", info.Title().c_str());
  LogInfo(
    "Base directory:\n"
    "        %s",
    hostPlatform.FileSystem().BasePath().c_str());
  LogInfo(
    "Preferencies root directory:\n"
    "        %s",
    hostPlatform.FileSystem().PreferencesRootPath().c_str());

  auto hasLoadError = preferences->LoadFromFile();
  if (hasLoadError) {
    std::stringstream errorMessage;
    errorMessage << "Error loading preferences from file:\n";
    errorMessage << "    " << hasLoadError.value() << "\n";
    errorMessage << "Using default values!";

    SDL_ShowSimpleMessageBox(
      SDL_MESSAGEBOX_ERROR,
      info.Title().c_str(),
      errorMessage.str().c_str(),
      nullptr);

    // Main window
    preferences->SetMainWindowDefaultValues();
  }

  if (!hostPlatform.SubSystems().Initialize()) {
    return Application::ExitCode::InitializationError;
  }

  auto creationPreferences = *preferences;
#if defined(_DEBUG)
  if (nullptr != commandLineArgs) {
    if (commandLineArgs->Resolution()) {
      auto height = commandLineArgs->Resolution().value().Height;
      auto width = commandLineArgs->Resolution().value().Width;

      LogInfo("Desired resolution: %dx%d", width, height);

      creationPreferences.MainWindowMetrics().Size.Height = height;
      creationPreferences.MainWindowMetrics().Size.Width = width;
    }

    if (commandLineArgs->Renderer()) {
      auto renderer = commandLineArgs->Renderer().value();

      LogInfo("Desired renderer: %d", static_cast<int>(renderer));

      creationPreferences.RendererAPI() = renderer;
    }
  }
#endif

  graphicsRenderer =
    Renderer::Graphics::Create(info, creationPreferences, hostPlatform);

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

    commandLineArgs.reset();
  }
}

NAMESPACE_END(Application)

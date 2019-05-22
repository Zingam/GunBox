#include "CoreApplication.hpp"
// Self
#include "CoreApplication.hpp"

// Project headers - Application
#include "Application/Configuration/Values.hpp"
// Project headers - Logger
#include "Logger/LogAPI.hpp"
// Project headers - Renderer/Graphics
#include "Renderer/Graphics/GraphicsRendererFactory.hpp"
#include "Renderer/Graphics/GraphicsRenderer_Interface.hpp"
// Project headers - System/GUI
#include "System/GUI/AlertBox.hpp"

// C++ Standard Library
#include <iostream>
#include <sstream>
#include <string>

NAMESPACE_BEGIN(Application)

////////////////////////////////////////////////////////////////////////////////
// Constructors & Destructors
////////////////////////////////////////////////////////////////////////////////

CoreApplication::CoreApplication(ApplicationInfo const& applicationInfo)
  : applicationInfo{ std::move(applicationInfo) }
  , engineInfo{ Engine_Title,
                Version::Version_t{ Engine_VersionMajor,
                                    Engine_VersionMinor,
                                    Engine_VersionPatch,
                                    Engine_VersionBuildNumber } }
  , preferences{ std::make_unique<Preferences>(this->applicationInfo) }
{
  hostPlatform.FileSystem().Initialize(applicationInfo);
}

CoreApplication::~CoreApplication() {}

////////////////////////////////////////////////////////////////////////////////
// Properties
////////////////////////////////////////////////////////////////////////////////

ApplicationInfo const&
CoreApplication::GetApplicationInfo() const
{
  return applicationInfo;
}

EngineInfo const&
CoreApplication::GetEngineInfo() const
{
  return engineInfo;
}

CommandLineArgs const&
CoreApplication::GetCommandLineArgs() const
{
  return *commandLineArgs;
}

////////////////////////////////////////////////////////////////////////////////
// Virtual methods
////////////////////////////////////////////////////////////////////////////////

void
CoreApplication::Finalize()
{
  if (isInitialized) {

#if defined(_DEBUG)
    reLogI("Finalizing: ", applicationInfo.Title());

    if (nullptr != commandLineArgs) {
      if (commandLineArgs->ShowSystemConsole()) {
        hostPlatform.SystemConsole().Hide();
      }
    }
#endif

    auto hasSaveError = preferences->SaveToFile();
    if (hasSaveError) {
      std::stringstream errorMessage;
      errorMessage << "Unable to save preferences!\n";
      errorMessage << "    Error:\n";
      errorMessage << hasSaveError.value();

      using namespace System::GUI;
      AlertBox AlertBox{ applicationInfo.Title(),
                         errorMessage.str(),
                         Common::AlertBox_Base::AlertType_t::Error };
      AlertBox.Show();
    }

    hostPlatform.SubSystems().Finalize();
  }
}

Application::ExitCode
CoreApplication::Initialize()
{
  reLogInitialize(applicationInfo.Title());

  if (nullptr != commandLineArgs) {
    if (commandLineArgs->ShowHelp()) {
      hostPlatform.SystemConsole().Show();

      std::cout << commandLineArgs->AsString() << "\n";

      hostPlatform.SystemConsole().Pause();
      hostPlatform.SystemConsole().Hide();

      return Application::ExitCode::InitializationError;
    }
#if defined(_DEBUG)
    if (nullptr != commandLineArgs) {
      if (commandLineArgs->ShowSystemConsole()) {
        hostPlatform.SystemConsole().Show();
      }
    }
#endif
  }

  // clang-format off
  reLogI(
    "Initializing:      ", applicationInfo.Title());
  reLogI(
    "  Version:         ", applicationInfo.GetVersion().AsString());
  reLogI(
    "  Directories:");
  reLogI(
    "    Base:");
  reLogI(
    "      ",
    hostPlatform.FileSystem().BasePath());
  reLogI(
    "    Preferencies:");
  reLogI(
    "      ",
    hostPlatform.FileSystem().PreferencesRootPath());
  // clang-format on
  auto const& compilerInfo = hostPlatform.SystemInfo().CompilerInfo();
  auto const& longVersion = compilerInfo.GetVersion().LongVersion();
  std::string_view compilerVersion;
  if (std::nullopt != longVersion) {
    compilerVersion = longVersion.value();
  } else {
    compilerVersion = compilerInfo.GetVersion().AsString();
  }
  // clang-format off
  reLogI(
    "  Compiler:        ",
    compilerInfo.Name());
  reLogI(
    "    Version:       ",
    compilerVersion.data());
  reLogI(
    "    C++ Standard:  ",
    compilerInfo.LanguageStandard());
  // clang-format on

  auto hasLoadError = preferences->LoadFromFile();
  if (hasLoadError) {
    std::stringstream errorMessage;
    errorMessage << "Error loading preferences from file:\n";
    errorMessage << "    " << hasLoadError.value() << "\n";
    errorMessage << "Using default values!";

    using namespace System::GUI;
    AlertBox AlertBox{ applicationInfo.Title(),
                       errorMessage.str(),
                       Common::AlertBox_Base::AlertType_t::Error };
    AlertBox.Show();

    // Main window
    preferences->SetMainWindowDefaultValues();
  }

  if (!hostPlatform.SubSystems().Initialize()) {
    return Application::ExitCode::InitializationError;
  }

  auto& creationPreferences = *preferences;
#if defined(_DEBUG) || !defined(NDEBUG)
  if (nullptr != commandLineArgs) {
    if (commandLineArgs->Resolution()) {
      auto height = commandLineArgs->Resolution().value().Height;
      auto width = commandLineArgs->Resolution().value().Width;

      reLogI("Desired resolution: ", width, "x", height);

      creationPreferences.MainWindowMetrics().Size.Height = height;
      creationPreferences.MainWindowMetrics().Size.Width = width;
    }

    if (commandLineArgs->Renderer()) {
      auto renderer = commandLineArgs->Renderer().value();

      reLogI("Desired renderer:   ", Renderer::Graphics::AsString(renderer));

      creationPreferences.RendererAPI() = renderer;
    }
  }
#endif

  graphicsRenderer =
    Renderer::Graphics::Create(*this, creationPreferences, hostPlatform);

  isInitialized = true;

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

    using namespace System::GUI;
    AlertBox AlertBox{ applicationInfo.Title(),
                       errorMessage.str(),
                       Common::AlertBox_Base::AlertType_t::Error };
    AlertBox.Show();

    commandLineArgs.reset();
  }
}

NAMESPACE_END(Application)

// Self
#include "CoreApplication.hpp"

// Project headers - Logger
#include "Logger/LogAPI.hpp"
// Project headers - Renderer/Graphics
#include "Renderer/Graphics/GraphicsRendererFactory.hpp"
#include "Renderer/Graphics/GraphicsRenderer_Interface.hpp"
// Project headers - System/GUI
#include "System/GUI/AlertBox.hpp"

// C++ Standard Library
#include <iostream>
#include <string>
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
  if (isInitialized) {

#if defined(_DEBUG)
    reLogI("Finalizing: ", info.Title());

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
      AlertBox AlertBox{ info.Title(),
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

  using namespace std::string_literals;

  // clang-format off
  reLogI(
    "Initializing:      ", info.Title());
  reLogI(
    "  Version:         ", info.GetVersion().AsString());
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
    AlertBox AlertBox{ info.Title(),
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
#if defined(_DEBUG)
  if (nullptr != commandLineArgs) {
    if (commandLineArgs->Resolution()) {
      auto height = commandLineArgs->Resolution().value().Height;
      auto width = commandLineArgs->Resolution().value().Width;

      reLogI("Desired resolution: ", width,"x", height);

      creationPreferences.MainWindowMetrics().Size.Height = height;
      creationPreferences.MainWindowMetrics().Size.Width = width;
    }

    if (commandLineArgs->Renderer()) {
      auto renderer = commandLineArgs->Renderer().value();

      reLogI("Desired renderer: ", static_cast<int>(renderer));

      creationPreferences.RendererAPI() = renderer;
    }
  }
#endif

  graphicsRenderer =
    Renderer::Graphics::Create(info, creationPreferences, hostPlatform);

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
    AlertBox AlertBox{ info.Title(),
                       errorMessage.str(),
                       Common::AlertBox_Base::AlertType_t::Error };
    AlertBox.Show();

    commandLineArgs.reset();
  }
}

NAMESPACE_END(Application)

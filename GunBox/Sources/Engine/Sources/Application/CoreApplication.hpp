#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

// Project headers - Application
#include "Application/CommandLineArgs.hpp"
#include "Application/ModuleInfo.hpp"
#include "Application/Preferences.hpp"

// Project headers - Renderer/Graphics
#include "Renderer/Graphics/GraphicsRenderer_Interface.hpp"

// Project headers - System
#include "System/EventProcessor.hpp"
#include "System/HostPlatform.hpp"

// C++ Standard Library
#include <memory>
#include <optional>
#include <string>

////////////////////////////////////////////////////////////////////////////////
// Class declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(Application)

enum class ExitCode
{
  GenericError = -1,
  InitializationError = -2,
  NoError = 0
};

/// <summary>
///   Abstract interface class.
/// </summary>
class CoreApplication
{
protected:
  CoreApplication(ApplicationInfo const& applicationInfo);

public:
  virtual ~CoreApplication() = 0;

  // Properties
public:
  auto GetApplicationInfo() const -> ApplicationInfo const&;
  auto GetEngineInfo() const -> EngineInfo const&;
  auto GetCommandLineArgs() const -> std::optional<CommandLineArgs> const&;

  // Pure virtual methods
public:
  virtual auto Execute() -> ExitCode = 0;

  // Virtual methods
public:
  virtual auto Finalize() -> void;
  virtual auto Initialize() -> ExitCode;
  virtual auto ProcessCommandLineArgs(int argc, char** argv) -> void;

protected:
  std::optional<CommandLineArgs> commandLineArgs;
  System::EventProcessor eventProcessor;
  std::shared_ptr<Renderer::Graphics::GraphicsRenderer_Interface>
    graphicsRenderer;
  System::HostPlatform hostPlatform;
  ApplicationInfo const applicationInfo;
  EngineInfo const engineInfo;
  bool isInitialized = false;
  std::unique_ptr<Preferences> preferences;
};

NAMESPACE_END(Application)

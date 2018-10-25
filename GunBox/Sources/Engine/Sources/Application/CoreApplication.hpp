#pragma once

// BASE MACROS header
#include "Common/Macros/Base.hpp"

// Project headers - Application
#include "Application/ApplicationInfo.hpp"
#include "Application/CommandLineArgs.hpp"
#include "Application/Preferences.hpp"

// Project headers - Renderer/Graphics
#include "Renderer/Graphics/GraphicsRenderer_Interface.hpp"

// Project headers - System
#include "System/EventProcessor.hpp"
#include "System/HostPlatform.hpp"

// C++ Standard Library
#include <memory>
#include <string>

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
  CoreApplication(ApplicationInfo const& info);

public:
  virtual ~CoreApplication() = 0;

  // Properties
public:
  auto Info() const -> ApplicationInfo const&;

  // Pure virtual methods
public:
  virtual auto Execute() -> ExitCode = 0;

  // Virtual methods
public:
  virtual auto Finalize() -> void;
  virtual auto Initialize() -> ExitCode;
  virtual auto ProcessCommandLineArgs(int argc, char** argv) -> void;

protected:
  std::unique_ptr<CommandLineArgs> commandLineArgs;
  System::EventProcessor eventProcessor;
  std::shared_ptr<Renderer::Graphics::GraphicsRenderer_Interface>
    graphicsRenderer;
  System::HostPlatform hostPlatform;
  ApplicationInfo const info;
  std::unique_ptr<Preferences> preferences;
};

NAMESPACE_END(Application)

////////////////////////////////////////////////////////////////////////////////
// Inline method implementations
////////////////////////////////////////////////////////////////////////////////

#include "CoreApplication.inl"

////////////////////////////////////////////////////////////////////////////////

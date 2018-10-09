#pragma once

// Project headers - Common
#include "Common/Macros/Base.hpp"

// Project headers - Application
#include "CommandLineArgs.hpp"
#include "Preferences.hpp"
#include "ProductInfo.hpp"

// Project headers - System
#include "System/HostPlatform.hpp"

// C++ Standard Library
#include <memory>
#include <string>

NAMESPACE_BEGIN(Application)

/// <summary>
///   Abstract interface class.
/// </summary>
class CoreApplication
{
public:
  enum class ExitCode
  {
    GenericError = -1,
    NoError = 0
  };

protected:
  CoreApplication(ProductInfo const& productInfo);

public:
  virtual ~CoreApplication() = 0;

  // Properties
public:
  auto Info() const -> ProductInfo const&;

  // Pure virtual methods
public:
  virtual auto Execute() -> ExitCode = 0;

  // Virtual methods
public:
  virtual auto Finalize() -> void;
  virtual auto Initialize() -> void;
  virtual auto ProcessCommandLineArgs(int argc, char** argv) -> void;

protected:
  std::unique_ptr<CommandLineArgs> commandLineArgs;
  System::HostPlatform hostPlatform;
  std::unique_ptr<Preferences> preferences;
  const ProductInfo productInfo;
};

NAMESPACE_END(Application)

////////////////////////////////////////////////////////////////////////////////
// Inline method implementations
////////////////////////////////////////////////////////////////////////////////

#include "CoreApplication.inl"

////////////////////////////////////////////////////////////////////////////////

#pragma once

// Project headers - Common
#include "Common/Macros/Base.hpp"

// Project headers - Application
#include "CommandLineArgs.hpp"

// Project headers - System
#include "System/HostPlatform.hpp"

// C++ Standard Library
#include <memory>
#include <string>

NAMESPACE_START(Application)

/// <summary>
///   Abstract interface class.
/// </summary>
class CoreApplication
{
protected:
  CoreApplication(std::string const& name,
                  CommandLineArgs const& commandLineArgs);

public:
  virtual ~CoreApplication() = 0;

  // Properties
public:
  auto Name() const -> std::string const&;

  // Pure virtual methods
public:
  virtual auto Execute() const -> void = 0;

protected:
  CommandLineArgs const& commandLineArgs;
  System::HostPlatform hostPlatform;
  std::string name;
};

NAMESPACE_END(Application)

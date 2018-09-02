#pragma once

// Project headers - Common
#include "Common/Macros/Base.hpp"

// Project headers - Application
#include "CommandLineArgs.hpp"

// C++ Standard Library
#include <memory>
#include <string>

NAMESPACE_START(Application)

/// <remarks>
///   <c>CoreApplication</c> is an abstract class due to its pure virtual
///   destructor.
/// </remarks>
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
  std::string name;
  CommandLineArgs const& commandLineArgs;
};

NAMESPACE_END(Application)

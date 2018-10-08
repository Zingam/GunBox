#pragma once

// Project headers - Common
#include "Common/Macros/Base.hpp"

// Project headers - Application
#include "CommandLineArgs.hpp"

// Project headers - System
#include "System/HostPlatform.hpp"

// C Standard Library
#include <cstdint>
// C++ Standard Library
#include <memory>
#include <string>

NAMESPACE_START(Application)

/// <summary>
///   Abstract interface class.
/// </summary>
class CoreApplication
{
public:
  struct ProductInfo
  {
    // Types
    using VersionBuildNumber_t = std::uint64_t;
    using VersionMajor_t = std::uint32_t;
    using VersionMinor_t = std::uint32_t;
    using VersionPatch_t = std::uint32_t;
    using Version_t = std::tuple<VersionMajor_t,
                                 VersionMinor_t,
                                 VersionPatch_t,
                                 VersionBuildNumber_t>;

    // Constructors
    ProductInfo(std::string const& Developer,
                std::string const& Name,
                Version_t const& version);

    // Values
    std::string Developer;
    std::string Name;
    Version_t Version;
  };

public:
  enum class ExitCode
  {
    GenericError = -1,
    NoError = 0
  };

protected:
  CoreApplication(ProductInfo productInfo);

public:
  virtual ~CoreApplication() = 0;

  // Properties
public:
  auto Developer() const -> std::string const&;
  auto Name() const -> std::string const&;
  auto VersionString() const -> std::string;
  auto VersionNumber() const& -> ProductInfo::Version_t;
  auto VersionNumberBuildNumber() const -> ProductInfo::VersionBuildNumber_t;
  auto VersionNumberMajor() const -> ProductInfo::VersionMajor_t;
  auto VersionNumberMinor() const -> ProductInfo::VersionMinor_t;
  auto VersionNumberPatch() const -> ProductInfo::VersionPatch_t;

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
  ProductInfo productInfo;
};

NAMESPACE_END(Application)

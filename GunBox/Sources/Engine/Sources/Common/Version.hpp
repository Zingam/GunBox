#pragma once

// C++ Standard Library
#include <optional>
#include <string>
#include <tuple>

class Version
{
  // Types
public:
  using BuildNumber_t = std::uint64_t;
  using Major_t = std::uint32_t;
  using Minor_t = std::uint32_t;
  using PatchLevel_t = std::uint32_t;
  using Version_t =
    std::tuple<Version::Major_t, Minor_t, PatchLevel_t, BuildNumber_t>;

  // Constructors
public:
  Version(Version_t version);
  Version(Version_t version, std::string const& longVersion);

  // Properties
public:
  auto BuildNumber() const -> BuildNumber_t;
  auto LongVersion() const -> std::optional<std::string> const&;
  auto Major() const -> Major_t;
  auto Minor() const -> Minor_t;
  auto PatchLevel() const -> PatchLevel_t;

  // Methods
public:
  auto AsNumbers() const -> Version_t const&;
  auto AsString() const -> std::string const&;

private:
  std::optional<std::string> longVersion;
  Version_t const version;
  std::string versionString;
};

#pragma once
////////////////////////////////////////////////////////////////////////////////

// C Standard Library
#include <cstdint>
// C++ Standard Library
#include <optional>
#include <string>
#include <tuple>

////////////////////////////////////////////////////////////////////////////////
// Class declarations
////////////////////////////////////////////////////////////////////////////////

class Version
{
  // Types
public:
  using BuildNumber_t = std::uint32_t;
  using Major_t = std::uint32_t;
  using Minor_t = std::uint32_t;
  using PatchLevel_t = std::uint32_t;
  using Version_t =
    std::tuple<Version::Major_t, Minor_t, PatchLevel_t, BuildNumber_t>;

  // Constructors
public:
  template<typename FormatFunc>
  Version(Version_t version, FormatFunc formatFunc);
  Version(Version_t version);
  template<typename FormatFunc>
  Version(
    Version_t version,
    std::string const& longVersion,
    FormatFunc formatFunc);
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
  auto AsNumber() const -> std::uint32_t const;
  auto AsNumbers() const -> Version_t const&;
  auto AsString() const -> std::string const&;

private:
  std::optional<std::string> longVersion;
  Version_t const version;
  std::string versionString;
};

////////////////////////////////////////////////////////////////////////////////
// Inline implementations
////////////////////////////////////////////////////////////////////////////////

#include "Version.inl"

////////////////////////////////////////////////////////////////////////////////

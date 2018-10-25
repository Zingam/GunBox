#pragma once

// BASE MACROS header
#include "Common/Macros/Base.hpp"

// C Standard Library
#include <cstdint>
// C++ Standard Library
#include <sstream>
#include <string>
#include <tuple>

NAMESPACE_BEGIN(Application)

class ApplicationInfo
{
  // Types
public:
  using VersionBuildNumber_t = std::uint64_t;
  using VersionMajor_t = std::uint32_t;
  using VersionMinor_t = std::uint32_t;
  using VersionPatch_t = std::uint32_t;
  using Version_t = std::
    tuple<VersionMajor_t, VersionMinor_t, VersionPatch_t, VersionBuildNumber_t>;

  // Constructors
public:
  ApplicationInfo(std::string const& organization,
                  std::string const& title,
                  Version_t const& version);

  // Properties
public:
  auto Organization() const -> std::string const;
  auto Title() const -> std::string const&;
  auto Version() const -> Version_t const&;
  auto VersionNumber() const& -> ApplicationInfo::Version_t;
  auto VersionNumberBuildNumber() const
    -> ApplicationInfo::VersionBuildNumber_t;
  auto VersionNumberMajor() const -> ApplicationInfo::VersionMajor_t;
  auto VersionNumberMinor() const -> ApplicationInfo::VersionMinor_t;
  auto VersionNumberPatch() const -> ApplicationInfo::VersionPatch_t;
  auto VersionString() const -> std::string;

private:
  std::string const organization;
  std::string const title;
  Version_t const version;
};

NAMESPACE_END(Application)

////////////////////////////////////////////////////////////////////////////////
// Inline method implementations
////////////////////////////////////////////////////////////////////////////////

#include "ApplicationInfo.inl"

////////////////////////////////////////////////////////////////////////////////

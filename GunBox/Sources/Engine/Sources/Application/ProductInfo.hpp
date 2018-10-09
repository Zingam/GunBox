#pragma once

// Project headers - Common
#include "Common/Macros/Base.hpp"

// C Standard Library
#include <cstdint>
// C++ Standard Library
#include <sstream>
#include <string>
#include <tuple>

NAMESPACE_BEGIN(Application)

class ProductInfo
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
  ProductInfo(std::string const& Developer,
              std::string const& Name,
              Version_t const& version);

  // Properties
public:
  auto Developer() const -> std::string const;
  auto Name() const -> std::string const&;
  auto Version() const -> Version_t const&;
  auto VersionNumber() const& -> ProductInfo::Version_t;
  auto VersionNumberBuildNumber() const -> ProductInfo::VersionBuildNumber_t;
  auto VersionNumberMajor() const -> ProductInfo::VersionMajor_t;
  auto VersionNumberMinor() const -> ProductInfo::VersionMinor_t;
  auto VersionNumberPatch() const -> ProductInfo::VersionPatch_t;
  auto VersionString() const -> std::string;

private:
  std::string const developer;
  std::string const name;
  Version_t const version;
};

NAMESPACE_END(Application)

////////////////////////////////////////////////////////////////////////////////
// Inline method implementations
////////////////////////////////////////////////////////////////////////////////

#include "ProductInfo.inl"

////////////////////////////////////////////////////////////////////////////////

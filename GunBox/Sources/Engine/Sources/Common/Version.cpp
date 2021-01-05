// Self
#include "Version.hpp"

// C Standard Library
#include <cmath>
// C++ Standard Library
#include <sstream>

////////////////////////////////////////////////////////////////////////////////
// Constructors & Destructors
////////////////////////////////////////////////////////////////////////////////

Version::Version(Version_t version)
  : Version(std::move(version), [this]() {
    std::stringstream ss;
    ss << this->Major() << '.';
    ss << this->Minor() << '.';
    ss << this->PatchLevel() << '.';
    ss << this->BuildNumber();

    return ss.str();
  })
{}

Version::Version(Version_t version, std::string const& longVersion)
  : Version(std::move(version))
{
  this->longVersion = longVersion;
}

////////////////////////////////////////////////////////////////////////////////
// Properties
////////////////////////////////////////////////////////////////////////////////

Version::BuildNumber_t
Version::BuildNumber() const
{
  return std::get<3>(version);
}

std::optional<std::string> const&
Version::LongVersion() const
{
  return longVersion;
}

Version::Major_t
Version::Major() const
{
  return std::get<0>(version);
}

Version::Minor_t
Version::Minor() const
{
  return std::get<1>(version);
}

Version::PatchLevel_t
Version::PatchLevel() const
{
  return std::get<2>(version);
}

////////////////////////////////////////////////////////////////////////////////
// Methods
////////////////////////////////////////////////////////////////////////////////

std::uint32_t const
Version::AsNumber() const
{
  std::uint32_t version[][3]{
    { 0, 1, this->Major() },
    { 0, 1, this->Minor() },
    { 0, 1, this->PatchLevel() },
  };
  constexpr size_t elementCount = sizeof(version) / sizeof(std::uint32_t) / 3;

  // Calculate the digit count in each version number
  for (std::int32_t i = 0L; elementCount > i; ++i) {
    version[i][0] = static_cast<std::uint32_t>(std::log10(version[i][2])) + 1;
    version[i][1] = static_cast<std::uint32_t>(std::pow(10, version[i][0]));
  }

  for (std::int32_t i = (elementCount - 2); 0 <= i; --i) {
    version[i][1] = version[i][1] * version[i + 1][1];
  }

  std::uint32_t versionNumber = 0L;
  for (std::int32_t i = 0; (elementCount - 1) > i; ++i) {
    versionNumber += version[i + 1][1] * version[i][2];
  }
  versionNumber += version[elementCount - 1][2];

  return versionNumber;
}

Version::Version_t const&
Version::AsNumbers() const
{
  return version;
}

std::string const&
Version::AsString() const
{
  return versionString;
}

auto
GreaterOrEqual(Version const& lhs, Version const& rhs) -> bool
{
  return (lhs.Major() >= rhs.Major()) && (lhs.Minor() >= rhs.Minor()) &&
         (lhs.PatchLevel() >= rhs.PatchLevel()) &&
         (lhs.BuildNumber() >= rhs.BuildNumber());
}

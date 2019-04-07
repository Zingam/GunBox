// Self
#include "Version.hpp"

// C++ Standard Library
#include <sstream>

////////////////////////////////////////////////////////////////////////////////
// Constructors & Destructors
////////////////////////////////////////////////////////////////////////////////

Version::Version(Version_t version)
  : version{ std::move(version) }
{
  std::stringstream ss;
  ss << this->Major() << '.';
  ss << this->Minor() << '.';
  ss << this->PatchLevel() << '.';
  ss << this->BuildNumber();

  this->versionString = ss.str();
}

Version::Version(Version_t version, std::string const& longVersion)
  : Version(version)
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

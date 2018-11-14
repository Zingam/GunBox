// Self
#include "ApplicationInfo.hpp"

NAMESPACE_BEGIN(Application)

////////////////////////////////////////////////////////////////////////////////
// Constructors & Destructors
////////////////////////////////////////////////////////////////////////////////

ApplicationInfo::ApplicationInfo(std::string const& organization,
                                 std::string const& title,
                                 Version_t const& version)
  : organization{ organization }
  , title{ title }
  , version{ version }
{}

////////////////////////////////////////////////////////////////////////////////
// Properties
////////////////////////////////////////////////////////////////////////////////

std::string const
ApplicationInfo::Organization() const
{
  return organization;
}

std::string const&
ApplicationInfo::Title() const
{
  return title;
}

ApplicationInfo::Version_t const&
ApplicationInfo::Version() const
{
  return version;
}

std::string
ApplicationInfo::VersionString() const
{
  std::stringstream ss;
  ss << VersionNumberMajor() << '.';
  ss << VersionNumberMinor() << '.';
  ss << VersionNumberPatch() << '.';
  ss << VersionNumberBuildNumber();

  return ss.str();
}

ApplicationInfo::Version_t
ApplicationInfo::VersionNumber() const&
{
  return version;
}

ApplicationInfo::VersionBuildNumber_t
ApplicationInfo::VersionNumberBuildNumber() const
{
  return std::get<3>(version);
}

ApplicationInfo::VersionMajor_t
ApplicationInfo::VersionNumberMajor() const
{
  return std::get<0>(version);
}

ApplicationInfo::VersionMinor_t
ApplicationInfo::VersionNumberMinor() const
{
  return std::get<1>(version);
}

ApplicationInfo::VersionPatch_t
ApplicationInfo::VersionNumberPatch() const
{
  return std::get<2>(version);
}

NAMESPACE_END(Application)

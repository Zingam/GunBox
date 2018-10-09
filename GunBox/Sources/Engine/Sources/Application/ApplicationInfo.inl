#pragma once

////////////////////////////////////////////////////////////////////////////////
// Inline method implementations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(Application)

////////////////////////////////////////////////////////////////////////////////
// Properties
////////////////////////////////////////////////////////////////////////////////

inline std::string const
ApplicationInfo::Organization() const
{
  return organization;
}

inline std::string const&
ApplicationInfo::Title() const
{
  return title;
}

inline ApplicationInfo::Version_t const&
ApplicationInfo::Version() const
{
  return version;
}

inline std::string
ApplicationInfo::VersionString() const
{
  std::stringstream ss;
  ss << VersionNumberMajor() << '.';
  ss << VersionNumberMinor() << '.';
  ss << VersionNumberPatch() << '.';
  ss << VersionNumberBuildNumber();

  return ss.str();
}

inline ApplicationInfo::Version_t
ApplicationInfo::VersionNumber() const&
{
  return version;
}

inline ApplicationInfo::VersionBuildNumber_t
ApplicationInfo::VersionNumberBuildNumber() const
{
  return std::get<3>(version);
}

inline ApplicationInfo::VersionMajor_t
ApplicationInfo::VersionNumberMajor() const
{
  return std::get<0>(version);
}

inline ApplicationInfo::VersionMinor_t
ApplicationInfo::VersionNumberMinor() const
{
  return std::get<1>(version);
}

inline ApplicationInfo::VersionPatch_t
ApplicationInfo::VersionNumberPatch() const
{
  return std::get<2>(version);
}

NAMESPACE_END(Application)

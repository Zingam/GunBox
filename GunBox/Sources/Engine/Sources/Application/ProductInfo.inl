#pragma once

////////////////////////////////////////////////////////////////////////////////
// Inline method implementations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(Application)

////////////////////////////////////////////////////////////////////////////////
// Properties
////////////////////////////////////////////////////////////////////////////////

inline std::string const
ProductInfo::Developer() const
{
  return developer;
}

inline std::string const&
ProductInfo::Name() const
{
  return name;
}

inline ProductInfo::Version_t const&
ProductInfo::Version() const
{
  return version;
}

inline std::string
ProductInfo::VersionString() const
{
  std::stringstream ss;
  ss << VersionNumberMajor() << '.';
  ss << VersionNumberMinor() << '.';
  ss << VersionNumberPatch() << '.';
  ss << VersionNumberBuildNumber();

  return ss.str();
}

inline ProductInfo::Version_t
ProductInfo::VersionNumber() const&
{
  return version;
}

inline ProductInfo::VersionBuildNumber_t
ProductInfo::VersionNumberBuildNumber() const
{
  return std::get<3>(version);
}

inline ProductInfo::VersionMajor_t
ProductInfo::VersionNumberMajor() const
{
  return std::get<0>(version);
}

inline ProductInfo::VersionMinor_t
ProductInfo::VersionNumberMinor() const
{
  return std::get<1>(version);
}

inline ProductInfo::VersionPatch_t
ProductInfo::VersionNumberPatch() const
{
  return std::get<2>(version);
}

NAMESPACE_END(Application)

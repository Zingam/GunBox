// Self
#include "ApplicationInfo.hpp"

NAMESPACE_BEGIN(Application)

////////////////////////////////////////////////////////////////////////////////
// Constructors & Destructors
////////////////////////////////////////////////////////////////////////////////

ApplicationInfo::ApplicationInfo(std::string const& organization,
                                 std::string const& title,
                                 Version const& version)
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

Version const&
ApplicationInfo::GetVersion() const
{
  return version;
}

NAMESPACE_END(Application)

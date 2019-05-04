// Self
#include "ModuleInfo.hpp"

NAMESPACE_BEGIN(Application)

////////////////////////////////////////////////////////////////////////////////
// [ModuleInfo] Constructors & Destructors
////////////////////////////////////////////////////////////////////////////////

ModuleInfo::ModuleInfo(std::string const& title, Version const& version)
  : title{ title }
  , version{ version }
{}

////////////////////////////////////////////////////////////////////////////////
// [ModuleInfo] Properties
////////////////////////////////////////////////////////////////////////////////

std::string const&
ModuleInfo::Title() const
{
  return title;
}

Version const&
ModuleInfo::GetVersion() const
{
  return version;
}

////////////////////////////////////////////////////////////////////////////////
// [ApplicationInfo] Constructors & Destructors
////////////////////////////////////////////////////////////////////////////////

ApplicationInfo::ApplicationInfo(
  std::string const& organization,
  std::string const& title,
  Version const& version)
  : ModuleInfo{ title, version }
  , organization{ organization }
{}

////////////////////////////////////////////////////////////////////////////////
// [ApplicationInfo] Properties
////////////////////////////////////////////////////////////////////////////////

std::string const
ApplicationInfo::Organization() const
{
  return organization;
}

////////////////////////////////////////////////////////////////////////////////
// [EngineInfo] Constructors & Destructors
////////////////////////////////////////////////////////////////////////////////

EngineInfo::EngineInfo(std::string const& title, Version const& version)
  : ModuleInfo{ title, version }
{}

NAMESPACE_END(Application)
// Self
#include "FileSystem.hpp"

NAMESPACE_BEGIN(System::HostPlatformClasses)

////////////////////////////////////////////////////////////////////////////////
// Properties
////////////////////////////////////////////////////////////////////////////////

std::string const&
FileSystem::BasePath() const
{
  return o_ptr->BasePath();
}

std::string const&
FileSystem::PreferencesRootPath() const
{
  return o_ptr->PreferencesRootPath();
}

////////////////////////////////////////////////////////////////////////////////
// Methods
////////////////////////////////////////////////////////////////////////////////

void
FileSystem::Finalize()
{
  o_ptr->Finalize();
}

bool
FileSystem::Initialize(Application::ApplicationInfo const& applicationInfo)
{
  return o_ptr->Initialize(applicationInfo);
}


NAMESPACE_END(System::HostPlatformClasses)

#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

// Project headers - Common
#include "Common/implementedBy.hpp"
// Project headers - System
#include "System/Platforms/FileSystem_Implementation.hpp"

NAMESPACE_BEGIN(Application)

class ApplicationInfo;

NAMESPACE_END(Application)

NAMESPACE_BEGIN(System::HostPlatformClasses)

class FileSystem : public implementedBy<FileSystem_Implementation>
{
  // Properties
public:
  auto BasePath() const -> std::string const&;
  auto PreferencesRootPath() const -> std::string const&;

  // Methods
public:
  auto Initialize(Application::ApplicationInfo const& applicationInfo) -> bool;
};

NAMESPACE_END(System::HostPlatformClasses)

#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

// C++ Standard Library
#include <string>

NAMESPACE_BEGIN(Application)

class ApplicationInfo;

NAMESPACE_END(Application)

NAMESPACE_BEGIN(System::HostPlatformClasses)

using FileSystem_Implementation = class FileSystem_SDL
{
// Properties
public:
  auto BasePath() const -> std::string const&;
  auto PreferencesRootPath() const -> std::string const&;

  // Methods
public:
  auto Initialize(Application::ApplicationInfo const& applicationInfo) -> bool;
  auto Finalize() -> void;

private:
  Application::ApplicationInfo const* applicationInfo = nullptr;
  std::string basePath;
  std::string preferencesRootPath;
};

NAMESPACE_END(System::HostPlatformClasses)

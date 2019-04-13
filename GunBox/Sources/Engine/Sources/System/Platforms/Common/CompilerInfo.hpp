#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

// Project headers - Common
#include "Common/Version.hpp"

// C Standard Library
#include <cstdint>
// C++ Standard Library
#include <memory>
#include <string>

NAMESPACE_BEGIN(System::HostPlatformClasses)

class CompilerInfo
{
public:
  CompilerInfo();

public:
  auto LanguageStandard() const -> std::uint32_t;
  auto Name() const -> std::string const&;
  auto GetVersion() const -> Version const&;

private:
  std::uint32_t languageStandard;
  std::string name;
  std::unique_ptr<Version> version;
  std::unique_ptr<Version> versionCompatibility;
};

NAMESPACE_END(System::HostPlatformClasses)

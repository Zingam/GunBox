#pragma once

// BASE MACROS header
#include "Common/Macros/Base.hpp"

#include <cstdint>
#include <string>

NAMESPACE_BEGIN(System::HostPlatformClasses)

class CompilerInfo
{
public:
  struct Version_t
  {
    std::uint32_t Build;
    std::string Full;
    std::uint32_t Major;
    std::uint32_t Minor;
    std::uint32_t PatchLevel;
  };

public:
  CompilerInfo();

public:
  auto LanguageStandard() const -> std::uint32_t;
  auto Name() const -> std::string const&;
  auto Version() const -> Version_t const&;

private:
  std::uint32_t languageStandard;
  std::string name;
  Version_t version;
  Version_t versionCompatibility;
};

NAMESPACE_END(System::HostPlatformClasses)

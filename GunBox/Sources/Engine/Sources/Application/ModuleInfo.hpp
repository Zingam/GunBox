#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

// Project headers - Common
#include "Common/Version.hpp"

// C Standard Library
#include <cstdint>
// C++ Standard Library
#include <sstream>
#include <string>
#include <tuple>

////////////////////////////////////////////////////////////////////////////////
// Class declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(Application)

////////////////////////////////////////////////////////////////////////////////

class ModuleInfo
{
  // Constructors
public:
  ModuleInfo(
    std::string const& title,
    Version const& version,
    std::string const& uuid);

  // Properties
public:
  auto Title() const -> std::string const&;
  auto GetVersion() const -> Version const&;
  auto UUID() const -> std::string const&;

private:
  std::string const title;
  Version const version;
  std::string const uuid;
};

////////////////////////////////////////////////////////////////////////////////

class ApplicationInfo : public ModuleInfo
{
  // Constructors
public:
  ApplicationInfo(
    std::string const& organization,
    std::string const& title,
    Version const& version,
    std::string const& uuid);

  // Properties
public:
  auto Organization() const -> std::string const;

private:
  std::string const organization;
};

////////////////////////////////////////////////////////////////////////////////

class EngineInfo : public ModuleInfo
{
  // Constructors
public:
  EngineInfo(
    std::string const& title,
    Version const& version,
    std::string const& uuid);
};

////////////////////////////////////////////////////////////////////////////////

NAMESPACE_END(Application)

#pragma once

// BASE MACROS header
#include "Common/Macros/Base.hpp"

// Project headers - Common
#include "Common/Version.hpp"

// C Standard Library
#include <cstdint>
// C++ Standard Library
#include <sstream>
#include <string>
#include <tuple>

NAMESPACE_BEGIN(Application)

class ApplicationInfo
{
  // Constructors
public:
  ApplicationInfo(std::string const& organization,
                  std::string const& title,
                  Version const& version);

  // Properties
public:
  auto Organization() const -> std::string const;
  auto Title() const -> std::string const&;
  auto GetVersion() const -> Version const&;

private:
  std::string const organization;
  std::string const title;
  Version const version;
};

NAMESPACE_END(Application)

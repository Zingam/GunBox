#pragma once

// BASE MACROS header
#include "Common/Macros/Base.hpp"

// Project headers - System
#include "System/DeviceTypes/Graphics/GeometryTypes.hpp"

// C++ Standard Library
#include <functional>
#include <map>
#include <optional>
#include <string>
#include <vector>

NAMESPACE_BEGIN(Application)

class CommandLineArgs
{
public:
  struct OptionInfo
  {
    struct ParameterInfo
    {
      const int Count;
      const std::string Description;
      const std::function<std::optional<std::string>(
        std::string const&,
        std::vector<std::string> const&)>
        Parse;
    };
    const ParameterInfo Parameters;
    const std::string Description;
  };

public:
  CommandLineArgs();

  // Properties
public:
  auto Fullscreen() const -> std::optional<bool>;
  auto ShowHelp() const -> std::optional<bool>;
  auto ShowSystemConsole() const -> std::optional<bool>;
  auto Resolution() const
    -> std::optional<System::DeviceTypes::Graphics::Dimensions>;

  // Methods
public:
  auto Parse(int argc, char* argv[]) -> std::optional<std::string>;

private:
  auto ParseFullscreen(std::string const& option,
                       std::vector<std::string> const& parameters)
    -> std::optional<std::string>;
  auto ParseShowHelp(std::string const& option,
                     std::vector<std::string> const& parameters)
    -> std::optional<std::string>;
  auto ParseShowSystemConsole(std::string const& option,
                              std::vector<std::string> const& parameters)
    -> std::optional<std::string>;
  auto ParseResolution(std::string const& option,
                       std::vector<std::string> const& parameters)
    -> std::optional<std::string>;

  // Constant fields
private:
  const std::map<const std::string, const OptionInfo> options;

  // Variable fields
private:
  std::optional<bool> fullscreen;
  std::optional<bool> showHelp;
  std::optional<bool> showSystemConsole;
  std::optional<System::DeviceTypes::Graphics::Dimensions> resolution;
};

NAMESPACE_END(Application)

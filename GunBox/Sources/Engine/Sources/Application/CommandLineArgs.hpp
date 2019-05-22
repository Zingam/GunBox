#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

// Project headers - System
#include "System/DeviceTypes/Graphics/GeometryTypes.hpp"
#include "System/DeviceTypes/Graphics/RendererTypes.hpp"

// C++ Standard Library
#include <functional>
#include <map>
#include <optional>
#include <string>
#include <vector>

////////////////////////////////////////////////////////////////////////////////
// Class declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(Application)

class CommandLineArgs
{
  // Types
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
  auto Renderer() const -> std::optional<System::DeviceTypes::Graphics::API_t>;
  auto RendererFeatures() const
    -> std::vector<System::DeviceTypes::Graphics::APIFeatures_t> const&;
  auto Resolution() const
    -> std::optional<System::DeviceTypes::Graphics::Dimensions_t>;
  auto ShowHelp() const -> std::optional<bool>;
  auto ShowSystemConsole() const -> std::optional<bool>;

  // Methods
public:
  auto AsString() -> std::string;
  auto Parse(int argc, char* argv[]) -> std::optional<std::string>;

private:
  auto ParseFullscreen(
    std::string const& option,
    std::vector<std::string> const& parameters) -> std::optional<std::string>;
  auto ParseRenderer(
    std::string const& option,
    std::vector<std::string> const& parameters) -> std::optional<std::string>;
  auto ParseResolution(
    std::string const& option,
    std::vector<std::string> const& parameters) -> std::optional<std::string>;
  auto ParseShowHelp(
    std::string const& option,
    std::vector<std::string> const& parameters) -> std::optional<std::string>;
  auto ParseShowSystemConsole(
    std::string const& option,
    std::vector<std::string> const& parameters) -> std::optional<std::string>;

  // Data members (constants)
private:
  const std::map<const std::string, const OptionInfo> options;

  // Data members (variables)
private:
  std::optional<std::string> executableFilename;
  std::optional<bool> fullscreen;
  std::optional<System::DeviceTypes::Graphics::API_t> renderer;
  std::vector<System::DeviceTypes::Graphics::APIFeatures_t> rendererFeatures;
  std::optional<System::DeviceTypes::Graphics::Dimensions_t> resolution;
  std::optional<bool> showHelp;
  std::optional<bool> showSystemConsole;
};

NAMESPACE_END(Application)

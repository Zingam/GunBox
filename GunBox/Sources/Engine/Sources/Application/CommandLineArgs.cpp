// Self
#include "CommandLineArgs.hpp"

// C Standard Library
#include <cassert>
// C++ Standard Library
#include <filesystem>
#include <iomanip>
#include <iostream>
#include <regex>

NAMESPACE_BEGIN(Application)

////////////////////////////////////////////////////////////////////////////////
// Constructors & Destructors
////////////////////////////////////////////////////////////////////////////////

CommandLineArgs::CommandLineArgs()
  : options{ { "--fullscreen",
               { { 0,
                   "",
                   [this](
                     std::string const& option,
                     std::vector<std::string> const& parameters) {
                     return this->ParseFullscreen(option, parameters);
                   } },
                 "Starts the application in fullscreen mode." } },
             { "--help",
               { { 0,
                   "",
                   [this](
                     std::string const& option,
                     std::vector<std::string> const& parameters) {
                     return this->ParseShowHelp(option, parameters);
                   } },
                 "Displays the command line options." } },
             { "--renderer:",
               { { 1,
                   "<Direct3D_12|OpenGL|Vulkan>",
                   [this](
                     std::string const& option,
                     std::vector<std::string> const& parameters) {
                     return this->ParseRenderer(option, parameters);
                   } },
                 "Displays the command line options." } },
             { "--resolution:",
               { { 1,
                   "<width>x<height>",
                   [this](
                     std::string const& option,
                     std::vector<std::string> const& parameters) {
                     return this->ParseResolution(option, parameters);
                   } },
                 "A valid resolution for the application window." } },
             { "--show-system-console",
               { { 0,
                   "",
                   [this](
                     std::string const& option,
                     std::vector<std::string> const& parameters) {
                     return this->ParseShowSystemConsole(option, parameters);
                   } },
                 "Opens a system console on supported systems." } } }
{}

////////////////////////////////////////////////////////////////////////////////
// Properties
////////////////////////////////////////////////////////////////////////////////

std::optional<bool>
CommandLineArgs::Fullscreen() const
{
  return fullscreen;
}

auto
CommandLineArgs::Renderer() const
  -> std::optional<System::DeviceTypes::Graphics::API_t>
{
  return renderer;
}

std::optional<bool>
CommandLineArgs::ShowHelp() const
{
  return showHelp;
}

std::optional<bool>
CommandLineArgs::ShowSystemConsole() const
{
  return showSystemConsole;
}

std::optional<System::DeviceTypes::Graphics::Dimensions_t>
CommandLineArgs::Resolution() const
{
  return resolution;
}

////////////////////////////////////////////////////////////////////////////////
// Methods
////////////////////////////////////////////////////////////////////////////////

std::optional<std::string>
CommandLineArgs::Parse(int argc, char* argv[])
{
  std::filesystem::path executablePath{ argv[0] };
  this->executableFilename = executablePath.stem().string();

  // Skip the first argument which is the path of the executable
  for (int argumentIndex = 1; argumentIndex < argc; ++argumentIndex) {
    auto search = options.find(argv[argumentIndex]);
    if (options.end() == search) {
      return std::optional{ "Invalid argument: " +
                            std::string{ argv[argumentIndex] } };
    }
    auto const& optionInfo = search->second;
    assert(
      (0 <= optionInfo.Parameters.Count) &&
      "Parameters count cannot be a negative number.");
    std::vector<std::string> parameters;
    for (int parameterIndex = 0; parameterIndex < optionInfo.Parameters.Count;
         ++parameterIndex) {
      parameters.emplace_back(argv[++argumentIndex]);
    }
    auto option = search->first;
    auto hasError = optionInfo.Parameters.Parse(option, parameters);
    if (hasError) {
      return hasError;
    }
  }

  return std::nullopt;
}

auto
CommandLineArgs::Print() -> void
{
  std::cout << "Usage:\n\n";
  std::cout << "  " << executableFilename.value() << " <options>\n\n";
  std::cout << "Options:\n\n";

  auto maxOptionLength = 0ull;
  auto maxParametersLength = 0ull;

  for (auto& option : this->options) {
    auto const nameLength = option.first.size();
    auto const parametersLength = option.second.Parameters.Description.size();
    if (nameLength > maxOptionLength) {
      maxOptionLength = nameLength;
    }
    if (parametersLength > maxParametersLength) {
      maxParametersLength = parametersLength;
    }
  }

  maxOptionLength += 1;
  maxParametersLength += 1;

  std::cout << std::left << "  " << std::setw(maxOptionLength) << "Name"
            << std::setw(maxParametersLength) << "Parameters" << std::setw(2)
            << "  Description"
            << "\n\n";

  for (auto& option : this->options) {
    auto& name = option.first;
    auto& parameters = option.second.Parameters.Description;
    auto& description = option.second.Description;

    std::cout << std::left << "  " << std::setw(maxOptionLength) << name
              << std::setw(maxParametersLength) << parameters << std::setw(2)
              << "-" << description << "\n";
  }
}

std::optional<std::string>
CommandLineArgs::ParseFullscreen(
  std::string const& option,
  std::vector<std::string> const& parameters)
{
  if (fullscreen) {
    return "Duplicated option: " + option;
  }
  fullscreen = true;

  return std::nullopt;
}

auto
CommandLineArgs::ParseRenderer(
  std::string const& option,
  std::vector<std::string> const& parameters) -> std::optional<std::string>
{
  if (renderer) {
    return "Duplicated option: " + option + " " + parameters[0];
  }
  assert((1 == parameters.size()) && "Too many parameters");

  auto rendererParameter = parameters[0];
  if ("Direct3D_12" == rendererParameter) {
    renderer = System::DeviceTypes::Graphics::API_t::Direct3D_12;
  } else if ("OpenGL" == rendererParameter) {
    renderer = System::DeviceTypes::Graphics::API_t::OpenGL;
  } else if ("Vulkan" == rendererParameter) {
    renderer = System::DeviceTypes::Graphics::API_t::Vulkan;
  } else {
    return std::optional{ "Invalid parameter: " + rendererParameter + "\n" +
                          "  for option: " + option };
  }

  return std::nullopt;
}

std::optional<std::string>
CommandLineArgs::ParseShowHelp(
  std::string const& option,
  std::vector<std::string> const& parameters)
{
  if (showHelp) {
    return "Duplicated option: " + option;
  }
  showHelp = true;

  return std::nullopt;
}

std::optional<std::string>
CommandLineArgs::ParseShowSystemConsole(
  std::string const& option,
  std::vector<std::string> const& parameters)
{
  if (showSystemConsole) {
    return "Duplicated option: " + option;
  }
  showSystemConsole = true;

  return std::nullopt;
}

std::optional<std::string>
CommandLineArgs::ParseResolution(
  std::string const& option,
  std::vector<std::string> const& parameters)
{
  if (resolution) {
    return "Duplicated option: " + option + " " + parameters[0];
  }
  assert((1 == parameters.size()) && "Too many parameters");

  auto resolutionParameter = parameters[0];
  std::smatch matches;
  // ^      - a beginning of a line
  // \s*    - zero or more white spaces
  // [0-9]+ - at least one digit
  // x      - a letter 'x'
  // $      - an end of a line
  // ()     - a group, e.g. '([0-0]+)' matches a group of digits
  std::regex resolutionPattern{ R"(^\s*([0-9]+)x([0-9]+)$\s*$)" };
  std::regex_match(resolutionParameter, matches, resolutionPattern);
  // The whole string an two groups should be matched
  if (3 == matches.size()) {
    std::vector<std::string> dimensionStrings;
    for (auto const& dimensionString : matches) {
      dimensionStrings.emplace_back(dimensionString.str());
    }
    System::DeviceTypes::Graphics::Dimensions_t dimensions;
    // The groups start at index [1]
    dimensions.Width = std::stoi(dimensionStrings[1]);
    dimensions.Height = std::stoi(dimensionStrings[2]);
    this->resolution = dimensions;

    return std::nullopt;
  }

  return std::optional{ "Invalid parameter format: " + resolutionParameter +
                        "\n" + "  for option: " + option };
}

NAMESPACE_END(Application)

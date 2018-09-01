// Self
#include "CommandLineArgs.hpp"

// C Standard Library
#include <cassert>
// C++ Standard Library
#include <regex>

NAMESPACE_START(Application)

////////////////////////////////////////////////////////////////////////////////
// Constructors & Destructors
////////////////////////////////////////////////////////////////////////////////

CommandLineArgs::CommandLineArgs()
  : options{ { "--fullscreen",
               { { 0,
                   "",
                   [this](std::string const& option,
                          std::vector<std::string> const& parameters) {
                     return this->ParseFullscreen(option, parameters);
                   } },
                 "Start the applicatin in fullscreen mode." } },
             { "--help",
               { { 0,
                   "",
                   [this](std::string const& option,
                          std::vector<std::string> const& parameters) {
                     return this->ParseShowHelp(option, parameters);
                   } },
                 "Start the applicatin in fullscreen mode." } },
             { "--resolution:",
               { { 1,
                   "<width>x<height>",
                   [this](std::string const& option,
                          std::vector<std::string> const& parameters) {
                     return this->ParseResolution(option, parameters);
                   } },
                 "A valid resolution for the application window." } },
             { "--show-system-console",
               { { 0,
                   "",
                   [this](std::string const& option,
                          std::vector<std::string> const& parameters) {
                     return this->ParseShowSystemConsole(option, parameters);
                   } },
                 "Open a system console on supported systems." } } }
{}

////////////////////////////////////////////////////////////////////////////////
// Properties
////////////////////////////////////////////////////////////////////////////////

std::optional<bool>
CommandLineArgs::Fullscreen() const
{
  return fullscreen;
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

std::optional<System::Dimensions>
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
  // Skip the first argument which is the path of the executable
  for (int argumentIndex = 1; argumentIndex < argc; ++argumentIndex) {
    auto search = options.find(argv[argumentIndex]);
    if (options.end() == search) {
      return std::optional{ "Invalid argument: " +
                            std::string{ argv[argumentIndex] } };
    }
    auto const& optionInfo = search->second;
    assert((0 <= optionInfo.Parameters.Count) &&
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

std::optional<std::string>
CommandLineArgs::ParseFullscreen(std::string const& option,
                                 std::vector<std::string> const& parameters)
{
  if (fullscreen) {
    return "Duplicated option: " + option;
  }
  fullscreen = true;

  return std::nullopt;
}

std::optional<std::string>
CommandLineArgs::ParseShowHelp(std::string const& option,
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
CommandLineArgs::ParseResolution(std::string const& option,
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
    System::Dimensions dimensions;
    // The groups start at index [1]
    dimensions.Width = std::stoi(dimensionStrings[1]);
    dimensions.Height = std::stoi(dimensionStrings[2]);
    this->resolution = dimensions;

    return std::nullopt;
  }

  return std::optional{ "Invalid parameter format: " + resolutionParameter +
                        "\n" + "  for option :" };
}

NAMESPACE_END(Application)

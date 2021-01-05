// Self
#include "CommandLineArgs.hpp"

// C Standard Library
#include <cassert>
// C++ Standard Library
#include <filesystem>
#include <iomanip>
#include <regex>
#include <sstream>

NAMESPACE_BEGIN(Application)

////////////////////////////////////////////////////////////////////////////////
// Constructors & Destructors
////////////////////////////////////////////////////////////////////////////////

CommandLineArgs::CommandLineArgs()
    : options{
          {"--fullscreen",
           {{0, "",
             [this](std::string const &option, std::vector<std::string> const &parameters) {
                 return this->ParseFullscreen(option, parameters);
             }},
            "Starts the application in fullscreen mode."}},
          {"--help",
           {{0, "",
             [this](std::string const &option, std::vector<std::string> const &parameters) {
                 return this->ParseShowHelp(option, parameters);
             }},
            "Displays the command line options."}},
          {"--renderer:",
           {{1, "<Direct3D_12|OpenGL|Vulkan>",
             [this](std::string const &option, std::vector<std::string> const &parameters) {
                 return this->ParseRenderer(option, parameters);
             }},
            "Displays the command line options."}},
          {"--resolution:",
           {{1, "<width>x<height>",
             [this](std::string const &option, std::vector<std::string> const &parameters) {
                 return this->ParseResolution(option, parameters);
             }},
            "A valid resolution for the application window."}},
          {"--show-system-console",
           {{0, "",
             [this](std::string const &option, std::vector<std::string> const &parameters) {
                 return this->ParseShowSystemConsole(option, parameters);
             }},
            "Opens a system console on supported systems."}}}
{
}

////////////////////////////////////////////////////////////////////////////////
// Properties
////////////////////////////////////////////////////////////////////////////////

std::optional<bool> CommandLineArgs::Fullscreen() const
{
    return fullscreen;
}

std::optional<System::DeviceTypes::Graphics::API_t> CommandLineArgs::Renderer() const
{
    return renderer;
}

std::vector<System::DeviceTypes::Graphics::APIFeatures_t> const &CommandLineArgs::RendererFeatures() const
{
    return rendererFeatures;
}

std::optional<bool> CommandLineArgs::ShowHelp() const
{
    return showHelp;
}

std::optional<bool> CommandLineArgs::ShowSystemConsole() const
{
    return showSystemConsole;
}

std::optional<System::DeviceTypes::Graphics::Dimensions_t> CommandLineArgs::Resolution() const
{
    return resolution;
}

////////////////////////////////////////////////////////////////////////////////
// Methods
////////////////////////////////////////////////////////////////////////////////

std::string CommandLineArgs::AsString()
{
    auto const &executableFilename = this->executableFilename.value();
    std::stringstream ss;
    ss << "Usage:\n\n";
    ss << "  " << executableFilename << " <options>\n\n";
    ss << "Options:\n\n";

    auto maxOptionLength = 0ull;
    auto maxParametersLength = 0ull;

    for (auto &option : this->options)
    {
        auto const nameLength = option.first.size();
        auto const parametersLength = option.second.Parameters.Description.size();
        if (nameLength > maxOptionLength)
        {
            maxOptionLength = nameLength;
        }
        if (parametersLength > maxParametersLength)
        {
            maxParametersLength = parametersLength;
        }
    }

    maxOptionLength += 1;
    maxParametersLength += 1;

    ss << std::left << "  " << std::setw(maxOptionLength) << "Name";
    ss << std::setw(maxParametersLength) << "Parameters";
    ss << std::setw(2) << "  Description"
       << "\n\n";

    for (auto &option : this->options)
    {
        auto const &name = option.first;
        auto const &parameters = option.second.Parameters.Description;
        auto const &description = option.second.Description;

        // Name
        ss << std::left << "  " << std::setw(maxOptionLength) << name;
        // Parameters
        ss << std::setw(maxParametersLength) << parameters;
        // Description
        ss << std::setw(2) << "-" << description << "\n";
    }

    return ss.str();
}

std::optional<std::string> CommandLineArgs::Parse(int argc, char *argv[])
{
    std::filesystem::path executablePath{argv[0]};
#if !defined(__ANDROID__)
    this->executableFilename = executablePath.stem().string();
#endif

    // Skip the first argument which is the path of the executable
    for (int argumentIndex = 1; argumentIndex < argc; ++argumentIndex)
    {
        auto search = options.find(argv[argumentIndex]);
        if (options.end() == search)
        {
            return std::optional{"Invalid argument: " + std::string{argv[argumentIndex]}};
        }
        auto const &optionInfo = search->second;
        assert((0 <= optionInfo.Parameters.Count) && "Parameters count cannot be a negative number.");
        std::vector<std::string> parameters;
        for (int parameterIndex = 0; parameterIndex < optionInfo.Parameters.Count; ++parameterIndex)
        {
            parameters.emplace_back(argv[++argumentIndex]);
        }
        auto option = search->first;
        auto hasError = optionInfo.Parameters.Parse(option, parameters);
        if (hasError)
        {
            return hasError;
        }
    }

    return std::nullopt;
}

std::optional<std::string> CommandLineArgs::ParseFullscreen(
    std::string const &option, std::vector<std::string> const &parameters)
{
    if (fullscreen)
    {
        return "Duplicated option: " + option;
    }
    fullscreen = true;

    return std::nullopt;
}

std::optional<std::string> CommandLineArgs::ParseRenderer(
    std::string const &option, std::vector<std::string> const &parameters)
{
    if (renderer)
    {
        return "Duplicated option: " + option + " " + parameters[0];
    }
    assert((1 == parameters.size()) && "Too many parameters");

    using namespace std::string_literals;

    auto const &rendererParameters = parameters[0];
    std::smatch matches;
    // ^      - a beginning of a line
    // \s*    - zero or more white spaces
    // \w+    - at least one alphanumeric character [a-zA-Z0-9_]
    // \[     - a chacater '['
    // \]     - a chacater ']'
    // $      - an end of a line
    // ()     - a group, e.g. '([0-0]+)' matches a group of digits
    // ()?    - an optional group, e.g. '(\[\w+\])?' matches a word in square
    //          brackets if available
    // The following patterns should be matched:
    //   DirectX12
    //   DirectX12[Debug]
    //   OpenGL
    //   Vulkan
    //   Vulkan[Debug]
    auto const rendererPatternString = R"(^\s*(\w+)((\[)(\w+)(\]))?$\s*$)"s;
    // The number of groups that will be matched contained in the above raw string
    auto const rendererPatternStringGroupCount = 6LL;
    std::regex const rendererPattern{rendererPatternString};
    std::regex_match(rendererParameters, matches, rendererPattern);
    // The whole string and two groups should be matched
    if (rendererPatternStringGroupCount == matches.size())
    {
        std::vector<std::string> rendererParameterStrings;
        for (auto const &rendererParameterString : matches)
        {
            rendererParameterStrings.emplace_back(rendererParameterString.str());
        }

        auto const &rendererParameter = rendererParameterStrings[1];

        if ("Direct3D_12"s == rendererParameter)
        {
            renderer = System::DeviceTypes::Graphics::API_t::Direct3D_12;
        }
        else if ("OpenGL"s == rendererParameter)
        {
            renderer = System::DeviceTypes::Graphics::API_t::OpenGL;
        }
        else if ("Vulkan"s == rendererParameter)
        {
            renderer = System::DeviceTypes::Graphics::API_t::Vulkan;
        }
        else
        {
            goto ParseRenderer_Error;
        }

        if (!rendererParameterStrings[4].empty())
        {
            if ("Debug"s == rendererParameterStrings[4])
            {
                rendererFeatures.push_back(System::DeviceTypes::Graphics::APIFeatures_t::Debug);
            }
            else
            {
                goto ParseRenderer_Error;
            }
        }
    }
    else
    {
        goto ParseRenderer_Error;
    }

    return std::nullopt;

ParseRenderer_Error:
    return {"Invalid parameter: " + rendererParameters + "\n" + "  for option: " + option};
}

std::optional<std::string> CommandLineArgs::ParseShowHelp(
    std::string const &option, std::vector<std::string> const &parameters)
{
    if (showHelp)
    {
        return "Duplicated option: " + option;
    }
    showHelp = true;

    return std::nullopt;
}

std::optional<std::string> CommandLineArgs::ParseShowSystemConsole(
    std::string const &option, std::vector<std::string> const &parameters)
{
    if (showSystemConsole)
    {
        return "Duplicated option: " + option;
    }
    showSystemConsole = true;

    return std::nullopt;
}

std::optional<std::string> CommandLineArgs::ParseResolution(
    std::string const &option, std::vector<std::string> const &parameters)
{
    if (resolution)
    {
        return "Duplicated option: " + option + " " + parameters[0];
    }
    assert((1 == parameters.size()) && "Too many parameters");

    auto const &resolutionParameter = parameters[0];
    std::smatch matches;
    // ^      - a beginning of a line
    // \s*    - zero or more white spaces
    // [0-9]+ - at least one digit
    // x      - a letter 'x'
    // $      - an end of a line
    // ()     - a group, e.g. '([0-0]+)' matches a group of digits
    std::regex const resolutionPattern{R"(^\s*([0-9]+)x([0-9]+)$\s*$)"};
    std::regex_match(resolutionParameter, matches, resolutionPattern);
    // The whole string and two groups should be matched
    if (3 == matches.size())
    {
        std::vector<std::string> dimensionStrings;
        for (auto const &dimensionString : matches)
        {
            dimensionStrings.emplace_back(dimensionString.str());
        }
        System::DeviceTypes::Graphics::Dimensions_t dimensions;
        // The groups start at index [1]
        dimensions.Width = std::stoi(dimensionStrings[1]);
        dimensions.Height = std::stoi(dimensionStrings[2]);
        this->resolution = dimensions;

        return std::nullopt;
    }

    return std::optional{"Invalid parameter format: " + resolutionParameter + "\n" + "  for option: " + option};
}

NAMESPACE_END(Application)

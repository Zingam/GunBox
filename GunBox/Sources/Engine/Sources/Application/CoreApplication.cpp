// Self
#include "CoreApplication.hpp"

// Third party libraries
#include <SDL.h>

// C++ Standard library
#include <sstream>

NAMESPACE_START(Application)

////////////////////////////////////////////////////////////////////////////////
// Constructors & Destructors
////////////////////////////////////////////////////////////////////////////////

CoreApplication::ProductInfo::ProductInfo(std::string const& developer,
                                          std::string const& name,
                                          Version_t const& version)
  : Developer{ developer }
  , Name{ name }
  , Version{ version }
{}

CoreApplication::CoreApplication(ProductInfo productInfo)
  : productInfo{ std::move(productInfo) }
{}

CoreApplication::~CoreApplication() {}

////////////////////////////////////////////////////////////////////////////////
// Virtual methods
////////////////////////////////////////////////////////////////////////////////

auto
CoreApplication::Finalize() -> void
{
#if defined(_DEBUG)
  SDL_Log("Finalizing: %s", Name().c_str());

  if (nullptr != commandLineArgs) {
    if (commandLineArgs->ShowSystemConsole()) {
      hostPlatform.HideSystemConsole();
    }
  }
#endif
}

auto
CoreApplication::Initialize() -> void
{
#if defined(_DEBUG)
  if (nullptr != commandLineArgs) {
    if (commandLineArgs->ShowSystemConsole()) {
      hostPlatform.ShowSystemConsole();
    }

    SDL_Log("Initalizing: %s", Name().c_str());

    if (commandLineArgs->Resolution()) {
      auto height = commandLineArgs->Resolution().value().Height;
      auto width = commandLineArgs->Resolution().value().Width;
      SDL_Log("Desired resolution: %dx%d", width, height);
    }
  } else {
    SDL_Log("Initalizing: %s", Name().c_str());
  }
#endif
}

void
CoreApplication::ProcessCommandLineArgs(int argc, char** argv)
{
  commandLineArgs = std::make_unique<CommandLineArgs>();
  auto hasParsingError = commandLineArgs->Parse(argc, argv);
  if (hasParsingError) {
    std::stringstream errorMessage;
    errorMessage << "Error parsing command line arguments.\n";
    errorMessage << hasParsingError.value() << "\n";
    SDL_ShowSimpleMessageBox(
      SDL_MESSAGEBOX_ERROR, "GunBox", errorMessage.str().c_str(), nullptr);

    commandLineArgs.release();
  }
}

////////////////////////////////////////////////////////////////////////////////
// Properties
////////////////////////////////////////////////////////////////////////////////

std::string const&
CoreApplication::Developer() const
{
  return productInfo.Developer;
}

std::string const&
CoreApplication::Name() const
{
  return productInfo.Name;
}

std::string
CoreApplication::VersionString() const
{
  std::stringstream ss;
  ss << VersionNumberMajor() << '.';
  ss << VersionNumberMinor() << '.';
  ss << VersionNumberPatch() << '.';
  ss << VersionNumberBuildNumber();

  return ss.str();
}

CoreApplication::ProductInfo::Version_t
CoreApplication::VersionNumber() const&
{
  return productInfo.Version;
}

CoreApplication::ProductInfo::VersionBuildNumber_t
CoreApplication::VersionNumberBuildNumber() const
{
  return std::get<3>(productInfo.Version);
}

CoreApplication::ProductInfo::VersionMajor_t
CoreApplication::VersionNumberMajor() const
{
  return std::get<0>(productInfo.Version);
}

CoreApplication::ProductInfo::VersionMinor_t
CoreApplication::VersionNumberMinor() const
{
  return std::get<1>(productInfo.Version);
}

CoreApplication::ProductInfo::VersionPatch_t
CoreApplication::VersionNumberPatch() const
{
  return std::get<2>(productInfo.Version);
}

////////////////////////////////////////////////////////////////////////////////
// Virtual methods
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_END(Application)

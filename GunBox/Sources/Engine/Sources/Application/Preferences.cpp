// Self
#include "Preferences.hpp"

// Third party libraries
#include <SDL.h>

// C Standard Library
#include <cassert>
// C++ Standard Library
#include <fstream>
#include <iostream>
#include <sstream>

NAMESPACE_BEGIN(Application)

////////////////////////////////////////////////////////////////////////////////
// Constructors & Destructors
////////////////////////////////////////////////////////////////////////////////

Preferences::Preferences(ApplicationInfo const& applicationInfo)
  : applicationInfo{ applicationInfo }
{
  // struct Data
  // {
  //   size_t hash_1;
  data.hash_1 = 0;
  //   std::string identifier;
  data.identifier = applicationInfo.Title();
  //   size_t version;
  data.version = 1;
  //   size_t offset_2; // of hash_2
  data.offset_2 = sizeof(data.hash_1);
  data.offset_2 += sizeof(char) * data.identifier.size();
  data.offset_2 += sizeof(data.version);
  data.offset_2 += sizeof(data.offset_2);
  // Add each member size individually due to data alignment in structs
  data.offset_2 += sizeof(data.mainWindowMetrics.Coordinate.X);
  data.offset_2 += sizeof(data.mainWindowMetrics.Coordinate.Y);
  data.offset_2 += sizeof(data.mainWindowMetrics.Size.Height);
  data.offset_2 += sizeof(data.mainWindowMetrics.Size.Width);
  data.offset_2 += sizeof(data.fullscreen);
  //   Rectangle2D mainWindowMetrics;
  SetMainWindowDefaultValues();
  //   bool fullscreen;
  data.fullscreen = false;
  //   size_t hash_2;
  data.hash_2 = 0;
  data.rendererApi = System::DeviceTypes::Graphics::API_t::Unknown;
  // };
}

////////////////////////////////////////////////////////////////////////////////
// Properties
////////////////////////////////////////////////////////////////////////////////

bool
Preferences::Fullscreen() const
{
  return data.fullscreen;
}

System::DeviceTypes::Graphics::Rectangle2D&
Preferences::MainWindowMetrics()
{
  return data.mainWindowMetrics;
}

System::DeviceTypes::Graphics::Rectangle2D const&
Preferences::MainWindowMetrics() const
{
  return data.mainWindowMetrics;
}

System::DeviceTypes::Graphics::API_t&
Preferences::RendererAPI()
{
  return data.rendererApi;
}

System::DeviceTypes::Graphics::API_t const&
Preferences::RendererAPI() const
{
  return data.rendererApi;
}

bool
Preferences::SuccesfullyLoaded() const
{
  return successfullyLoaded;
}

////////////////////////////////////////////////////////////////////////////////
// Public methods
////////////////////////////////////////////////////////////////////////////////

const std::optional<std::string>
Preferences::LoadFromFile()
{
  // Open the preferences file from the system location
  auto prefPath = SDL_GetPrefPath(
    applicationInfo.Organization().c_str(), applicationInfo.Title().c_str());
  std::stringstream filepath;
  filepath << prefPath << applicationInfo.Title() << ".preferences";
  SDL_free(prefPath);

  std::fstream preferencesFile;
  preferencesFile.open(
    filepath.str(),
    std::fstream::binary | std::fstream::in | std::fstream::out);
  if (!preferencesFile.is_open()) {
    return { "Unable to open: " + filepath.str() };
  }

  // Read the values from the preferences file
  preferencesFile.read(
    reinterpret_cast<char*>(&data.hash_1), sizeof(data.hash_1));
  const auto hash_1 = CalculateHash(preferencesFile, { 0 });
  if (hash_1 != data.hash_1) {
    return { "Invalid hash value: " + filepath.str() };
  }

  std::string identifier(data.identifier.size(), '\0');
  preferencesFile.read(identifier.data(), identifier.size());
  // Check if this is a preferences file
  if (identifier != data.identifier) {
    preferencesFile.close();

    return { "Invalid file format: " + filepath.str() };
  }

  preferencesFile.read(
    reinterpret_cast<char*>(&data.version), sizeof(data.version));
  preferencesFile.read(
    reinterpret_cast<char*>(&data.offset_2), sizeof(data.offset_2));

  auto returnPos = preferencesFile.tellg();
  // To set the fstream back to the begining a call to fstream::clear() is
  // required to clear the error state fstream::eofbit in case the end of the
  // file has been reached.
  preferencesFile.clear();
  preferencesFile.seekg(data.offset_2, std::fstream::beg);
  preferencesFile.read(
    reinterpret_cast<char*>(&data.hash_2), sizeof(data.hash_2));
  const auto hash_2 = CalculateHash(preferencesFile, { 0, data.offset_2 });
  if (hash_2 != data.hash_2) {
    return { "Invalid hash value: " + filepath.str() };
  }
  preferencesFile.clear();
  preferencesFile.seekg(returnPos, std::fstream::beg);

  // Read each member size individually due to data alignment in structs
  preferencesFile.read(
    reinterpret_cast<char*>(&data.mainWindowMetrics.Coordinate.X),
    sizeof(data.mainWindowMetrics.Coordinate.X));
  preferencesFile.read(
    reinterpret_cast<char*>(&data.mainWindowMetrics.Coordinate.Y),
    sizeof(data.mainWindowMetrics.Coordinate.Y));
  preferencesFile.read(
    reinterpret_cast<char*>(&data.mainWindowMetrics.Size.Height),
    sizeof(data.mainWindowMetrics.Size.Height));
  preferencesFile.read(
    reinterpret_cast<char*>(&data.mainWindowMetrics.Size.Width),
    sizeof(data.mainWindowMetrics.Size.Width));
  preferencesFile.read(
    reinterpret_cast<char*>(&data.fullscreen), sizeof(data.fullscreen));
  // Skip data.hash_2 bytes
  preferencesFile.ignore(sizeof(data.hash_2));
  preferencesFile.read(
    reinterpret_cast<char*>(&data.rendererApi), sizeof(data.rendererApi));

  if (preferencesFile.bad()) {
    return { "Read error: " + filepath.str() };
  }

  successfullyLoaded = true;

  return {};
}

const std::optional<std::string>
Preferences::SaveToFile()
{
  auto prefPath = SDL_GetPrefPath(
    applicationInfo.Organization().data(), applicationInfo.Title().c_str());
  std::stringstream filepath;
  filepath << prefPath << applicationInfo.Title() << ".preferences";
  SDL_free(prefPath);

  std::fstream preferencesFile;
  preferencesFile.open(
    filepath.str(),
    std::fstream::binary | std::fstream::in | std::fstream::out |
      std::fstream::trunc);
  if (!preferencesFile.is_open()) {
    return { "Unable to open: " + filepath.str() };
  }

  preferencesFile.write(
    reinterpret_cast<char const*>(&data.hash_1), sizeof(data.hash_1));
  preferencesFile.write(data.identifier.data(), data.identifier.size());
  preferencesFile.write(
    reinterpret_cast<char const*>(&data.version), sizeof(data.version));
  preferencesFile.write(
    reinterpret_cast<char const*>(&data.offset_2), sizeof(data.offset_2));
  // Read each member size individually due to data alignment in structs
  preferencesFile.write(
    reinterpret_cast<char const*>(&data.mainWindowMetrics.Coordinate.X),
    sizeof(data.mainWindowMetrics.Coordinate.X));
  preferencesFile.write(
    reinterpret_cast<char const*>(&data.mainWindowMetrics.Coordinate.Y),
    sizeof(data.mainWindowMetrics.Coordinate.Y));
  preferencesFile.write(
    reinterpret_cast<char const*>(&data.mainWindowMetrics.Size.Height),
    sizeof(data.mainWindowMetrics.Size.Height));
  preferencesFile.write(
    reinterpret_cast<char const*>(&data.mainWindowMetrics.Size.Width),
    sizeof(data.mainWindowMetrics.Size.Width));
  preferencesFile.write(
    reinterpret_cast<char const*>(&data.fullscreen), sizeof(data.fullscreen));
  preferencesFile.write(
    reinterpret_cast<char const*>(&data.hash_2), sizeof(data.hash_2));
  preferencesFile.write(
    reinterpret_cast<const char*>(&data.rendererApi), sizeof(data.rendererApi));

  preferencesFile.seekp(data.offset_2, std::fstream::beg);
  const auto hash_2 = CalculateHash(preferencesFile, { 0, data.offset_2 });
  preferencesFile.write(reinterpret_cast<char const*>(&hash_2), sizeof(hash_2));

  preferencesFile.seekp(0, std::fstream::beg);
  const auto hash_1 = CalculateHash(preferencesFile, { 0 });
  preferencesFile.write(reinterpret_cast<char const*>(&hash_1), sizeof(hash_1));

  if (preferencesFile.bad()) {
    return { "Write error: " + filepath.str() };
  }

  return {};
}

void
Preferences::SetMainWindowDefaultValues()
{
  data.mainWindowMetrics.Coordinate.X = 0;
  data.mainWindowMetrics.Coordinate.Y = 0;
  data.mainWindowMetrics.Size.Height = 480;
  data.mainWindowMetrics.Size.Width = 640;
  data.rendererApi = System::DeviceTypes::Graphics::API_t::OpenGL;
}

////////////////////////////////////////////////////////////////////////////////
// Private methods
////////////////////////////////////////////////////////////////////////////////

size_t
Preferences::CalculateHash(
  std::fstream& fstream,
  std::vector<size_t> const& hashvalueOffsets)
{
  // Simple hash functions: http://www.cse.yorku.ca/~oz/hash.html
  auto currentInputPosition = fstream.tellg();
  auto currentOutputPosition = fstream.tellp();

  fstream.clear();
  fstream.seekg(0, std::fstream::beg);
  fstream.seekp(0, std::fstream::beg);

  // djb2: hash(i) = hash(i - 1) * 33 ^ str[i]
  size_t hash_djb2 = 5961;
  // sdbm: hash(i) = hash(i - 1) * 65599 + str[i]
  size_t hash_sdbm = 0;

  do {
    if (std::char_traits<char>::eof() == fstream.peek()) {
      break;
    }
    for (auto const& offset : hashvalueOffsets) {
      if ((fstream.tellg() == offset) || (fstream.tellp() == offset)) {
        fstream.ignore(sizeof(Data::hash_t));
      }
    }
    char c = 0;
    fstream.read(&c, 1);
    // hash(i) = (hash(i - 1) * 32 + hash(i - 1)) ^ str[i]
    hash_djb2 = ((hash_djb2 << 5) + hash_djb2) ^ c;
    // hash(i) = (hash(i - 1) * 64 + hash(i - 1) * 65536 - hash(i - 1)) + str[i]
    hash_sdbm = ((hash_sdbm << 6) + (hash_sdbm << 16) - hash_sdbm) + c;
  } while (true);

  fstream.clear();
  fstream.seekg(currentInputPosition, std::fstream::beg);
  fstream.seekp(currentOutputPosition, std::fstream::beg);

  return hash_djb2 + hash_sdbm;
}

NAMESPACE_END(Application)

#pragma once

// BASE MACROS header
#include "Common/Macros/Base.hpp"

// Project headers - Application
#include "Application/ApplicationInfo.hpp"
// Project headers - System
#include "System/DeviceTypes/Graphics/GeometryTypes.hpp"
#include "System/DeviceTypes/Graphics/RendererTypes.hpp"
#include "System/Window.hpp"

// C++ Standard Library
#include <optional>
#include <string>
#include <vector>

NAMESPACE_BEGIN(Application)

class Preferences
{
  struct Data
  {
    // Types
    using hash_t = size_t;
    // Values
    hash_t hash_1;
    std::string identifier;
    size_t version;
    size_t offset_2; // of hash_2
    System::DeviceTypes::Graphics::Rectangle2D mainWindowMetrics;
    bool fullscreen;
    hash_t hash_2;
    System::DeviceTypes::Graphics::API_t rendererApi;
  };

public:
  Preferences(ApplicationInfo const& applicationInfo);

  // Properties
public:
  auto Fullscreen() -> bool&;
  auto MainWindowMetrics() -> System::DeviceTypes::Graphics::Rectangle2D&;
  auto RendererAPI() -> System::DeviceTypes::Graphics::API_t&;
  auto SuccesfullyLoaded() const -> bool;

  // Methods
public:
  auto LoadFromFile() -> const std::optional<std::string>;
  auto SaveToFile() -> const std::optional<std::string>;
  auto SetMainWindowDefaultValues() -> void;

private:
  auto CalculateHash(std::fstream& fstream,
                     std::vector<size_t> const& hashvalueOffsets) -> size_t;

private:
  ApplicationInfo const& applicationInfo;
  Data data;
  bool successfullyLoaded = false;
};

NAMESPACE_END(SYSTEM)

#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

// Project headers - Application
#include "Application/ApplicationInfo.hpp"
// Project headers - System
#include "System/DeviceTypes/Graphics/GeometryTypes.hpp"
#include "System/DeviceTypes/Graphics/RendererTypes.hpp"

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
    hash_t hash_1 = 0;
    std::string identifier{};
    size_t version = 0;
    size_t offset_2 = 0; // of hash_2
    System::DeviceTypes::Graphics::Rectangle2D mainWindowMetrics{ { 0, 0 },
                                                                  { 0, 0 } };
    bool fullscreen = false;
    hash_t hash_2 = 0;
    System::DeviceTypes::Graphics::API_t rendererApi =
      System::DeviceTypes::Graphics::API_t::Unknown;
  };

public:
  Preferences(ApplicationInfo const& applicationInfo);

  // Properties
public:
  auto Fullscreen() const -> bool;
  auto MainWindowMetrics() -> System::DeviceTypes::Graphics::Rectangle2D&;
  auto MainWindowMetrics() const -> System::DeviceTypes::Graphics::Rectangle2D const&;
  auto RendererAPI() -> System::DeviceTypes::Graphics::API_t&;
  auto RendererAPI() const -> System::DeviceTypes::Graphics::API_t const&;
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

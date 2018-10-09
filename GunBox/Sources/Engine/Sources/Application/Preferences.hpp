#pragma once

// Project headers - Common
#include "Common/Macros/Base.hpp"

// Project headers - Application
#include "Application/ApplicationInfo.hpp"
// Project headers - Renderer
#include "Renderer/RendererBase.hpp"
// Project headers - System
#include "System/Geometry.hpp"
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
    System::Rectangle2D mainWindowMetrics;
    bool fullscreen;
    hash_t hash_2;
    System::Renderer::API_t rendererApi;
  };

public:
  Preferences(ApplicationInfo const& applicationInfo);

public:
  auto LoadFromFile() -> const std::optional<std::string>;
  auto SaveToFile() -> const std::optional<std::string>;
  auto SetMainWindowDefaultValues() -> void;

public:
  auto Fullscreen() -> bool&;
  auto MainWindowMetrics() -> System::Rectangle2D&;
  auto RendererAPI() -> System::Renderer::API_t&;

private:
  auto CalculateHash(std::fstream& fstream,
                     std::vector<size_t> const& hashvalueOffsets) -> size_t;

private:
  Data data;
  ApplicationInfo const& applicationInfo;
};

NAMESPACE_END(SYSTEM)

////////////////////////////////////////////////////////////////////////////////
// Inline method implementations
////////////////////////////////////////////////////////////////////////////////

#include "Preferences.inl"

////////////////////////////////////////////////////////////////////////////////

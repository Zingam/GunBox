#pragma once

// Project headers - Common
#include "Common/Macros/Base.hpp"

// Project headers - System
#include "Geometry.hpp"
#include "RendererBase.hpp"
#include "Window.hpp"

// C++ Standard library
#include <optional>
#include <string>
#include <vector>

NAMESPACE_START(System)

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
    Rectangle2D mainWindowMetrics;
    bool fullscreen;
    hash_t hash_2;
    Renderer::API_t rendererApi;
  };

public:
  Preferences(char const* organizationName, char const* applicationaName);

public:
  auto LoadFromFile() -> const std::optional<std::string>;
  auto SaveToFile() -> const std::optional<std::string>;
  auto SetMainWindowDefaultValues() -> void;

public:
  auto Fullscreen() -> bool&;
  auto MainWindowMetrics() -> Rectangle2D&;
  auto RendererAPI() -> Renderer::API_t&;

private:
  auto CalculateHash(std::fstream& fstream,
                     std::vector<size_t> const& hashvalueOffsets) -> size_t;

private:
  char const* applicationName;
  Data data;
  char const* organizationName;
};


inline bool&
Preferences::Fullscreen()
{
  return data.fullscreen;
}

inline Rectangle2D&
Preferences::MainWindowMetrics()
{
  return data.mainWindowMetrics;
}

inline Renderer::API_t&
Preferences::RendererAPI()
{
  return data.rendererApi;
}

NAMESPACE_END(SYSTEM)

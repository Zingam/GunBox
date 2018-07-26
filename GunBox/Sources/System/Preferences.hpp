#pragma once

// Project headers
#include "Geometry.hpp"
// C++ Standard library
#include <optional>
#include <string>
#include <vector>

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
    Rectangle2D window;
    bool fullscreen;
    hash_t hash_2;
  };

public:
  Preferences(char const* organizationName, char const* applicationaName);

public:
  auto LoadFromFile() -> const std::optional<std::string>;
  auto SaveToFile() -> const std::optional<std::string>;
  auto SetDefaultValues() -> void;

private:
  auto CalculateHash(std::fstream& fstream,
                     std::vector<size_t> const& hashvalueOffsets) -> size_t;

private:
  char const* applicationName;
  Data data;
  char const* organizationName;
};

#pragma once

// Project headers - Common
#include "Common/Macros/Base.hpp"

// C Standard Library
#include <cstdint>

NAMESPACE_START(System)

struct Renderer
{
  enum class API_t : std::uint64_t
  {
    Direct3D_12 = 10'000'000'000'000'120'000,
    OpenGL = 10'000'000'040'000'000'000,
    Vulkan = 10'000'010'000'000'000'000,
    Unknown = 18'446'744'073'709'551'615,
  };
};

NAMESPACE_END(System)

#pragma once

// Project headers - Common
#include "Common/Macros/Base.hpp"

// C Standard Library
#include <cstdint>

NAMESPACE_BEGIN(System::DeviceTypes::Graphics)

enum class API_t : std::uint64_t
{
  Direct3D_12 = UINT64_C(10'000'000'000'000'120'000),
  OpenGL = UINT64_C(10'000'000'040'000'000'000),
  Vulkan = UINT64_C(10'000'010'000'000'000'000),
  Unknown = UINT64_C(18'446'744'073'709'551'615),
};

struct OpenGLContextVersion_t
{
  int SupportedMajorVersion;
  int SupportedMinorVersion;
  int MinimalSupportedMajorVersion;
  int MinimalSupportedMinorVersion;
  int ContextProfile;
};

NAMESPACE_END(System::DeviceTypes::Graphics)
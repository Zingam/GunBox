#pragma once

// BASE MACROS header
#include "Common/Macros/Base.hpp"

// Project headers - System
#include "System/DeviceTypes/Graphics/RendererTypes.hpp"

// C++ Standard Library
#include <string>

////////////////////////////////////////////////////////////////////////////////
// Forward declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(System)

class Window;

NAMESPACE_END(System)

////////////////////////////////////////////////////////////////////////////////
// Class declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(System::HostPlatformClasses)

using OpenGLContext = void*;

using OpenGLDevice_Implementation = class OpenGLDevice_SDL
{
public:
  OpenGLDevice_SDL();

  // Properties
public:
  auto GetProcAddress() -> void*;

  // Methods
public:
  auto Finalize() -> void;
  auto Initialize(Window const& window) -> bool;
  auto InitializeContext() -> bool;
  auto SwapBuffer() -> void;

private:
  OpenGLContext openGLContext = nullptr;
  System::DeviceTypes::Graphics::OpenGLContextVersion_t openGLContextVersion;
  std::string platformName;
  Window const* window = nullptr;
};

NAMESPACE_END(System::HostPlatformClasses)

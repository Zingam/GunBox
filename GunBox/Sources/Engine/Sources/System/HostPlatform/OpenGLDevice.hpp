#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

// Project headers - Common
#include "Common/implementedBy.hpp"
// Project headers - System
#include "System/Platforms/OpenGLDevice_Implementation.hpp"
#include "System/GUI/Window.hpp"

NAMESPACE_BEGIN(System::HostPlatformClasses)

class OpenGLDevice : public implementedBy<OpenGLDevice_Implementation>
{
  // Properties
public:
  auto GetProcAddress() -> void*;

  // Methods
public:
  auto Initialize(Window const& window) -> bool;
  auto InitializeContext() -> bool;
  auto SwapBuffer() -> void;
};

NAMESPACE_END(System::HostPlatformClasses)

////////////////////////////////////////////////////////////////////////////////
// Inline method implementations
////////////////////////////////////////////////////////////////////////////////

#include "OpenGLDevice.inl"

////////////////////////////////////////////////////////////////////////////////

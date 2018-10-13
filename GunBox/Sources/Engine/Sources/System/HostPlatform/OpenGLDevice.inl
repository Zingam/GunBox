#include "OpenGLDevice.hpp"
#pragma once

////////////////////////////////////////////////////////////////////////////////
// Inline method implementations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(System::HostPlatformClasses)

////////////////////////////////////////////////////////////////////////////////
// Properties
////////////////////////////////////////////////////////////////////////////////

inline auto
OpenGLDevice::GetProcAddress() -> void*
{
  return o_ptr->GetProcAddress();
}

////////////////////////////////////////////////////////////////////////////////
// Methods
////////////////////////////////////////////////////////////////////////////////

inline void
OpenGLDevice::Finalize()
{
  o_ptr->Finalize();
}

inline bool
OpenGLDevice::Initialize(Window const& window)
{
  return o_ptr->Initialize(window);
}

inline auto
OpenGLDevice::InitializeContext() -> bool
{
  return o_ptr->InitializeContext();
}

inline auto
OpenGLDevice::SwapBuffer() -> void
{
  o_ptr->SwapBuffer();
}

NAMESPACE_END(System::HostPlatformClasses)

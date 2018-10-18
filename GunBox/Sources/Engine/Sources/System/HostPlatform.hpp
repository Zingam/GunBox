#pragma once

// Project headers - BASE
#include "Common/Macros/Base.hpp"

// Project headers - Common
#include "Common/implementedBy.hpp"
// Project headers - System
#include "System/HostPlatform/OpenGLDevice.hpp"
#include "System/HostPlatform/SubSystems.hpp"
#include "System/HostPlatform/SystemConsole.hpp"

NAMESPACE_BEGIN(System)

class HostPlatform
{
public:
  HostPlatformClasses::OpenGLDevice& OpenGLDevice();
  HostPlatformClasses::SubSystems& SubSystems();
  HostPlatformClasses::SystemConsole& SystemConsole();

private:
  HostPlatformClasses::OpenGLDevice openGLDevice;
  HostPlatformClasses::SubSystems subSystems;
  HostPlatformClasses::SystemConsole systemConsole;
};

NAMESPACE_END(System)

////////////////////////////////////////////////////////////////////////////////
// Inline method implementations
////////////////////////////////////////////////////////////////////////////////

#include "HostPlatform.inl"

////////////////////////////////////////////////////////////////////////////////

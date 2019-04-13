#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

// Project headers - Common
#include "Common/implementedBy.hpp"
// Project headers - System
#include "System/HostPlatform/FileSystem.hpp"
#include "System/HostPlatform/OpenGLDevice.hpp"
#include "System/HostPlatform/SubSystems.hpp"
#include "System/HostPlatform/SystemConsole.hpp"
#include "System/HostPlatform/SystemInfo.hpp"

NAMESPACE_BEGIN(System)

class HostPlatform
{
public:
  HostPlatformClasses::FileSystem& FileSystem();
  HostPlatformClasses::OpenGLDevice& OpenGLDevice();
  HostPlatformClasses::SubSystems& SubSystems();
  HostPlatformClasses::SystemConsole& SystemConsole();
  HostPlatformClasses::SystemInfo& SystemInfo();

private:
  HostPlatformClasses::FileSystem fileSystem;
  HostPlatformClasses::OpenGLDevice openGLDevice;
  HostPlatformClasses::SubSystems subSystems;
  HostPlatformClasses::SystemConsole systemConsole;
  HostPlatformClasses::SystemInfo systemInfo;
};

NAMESPACE_END(System)

////////////////////////////////////////////////////////////////////////////////
// Inline method implementations
////////////////////////////////////////////////////////////////////////////////

#include "HostPlatform.inl"

////////////////////////////////////////////////////////////////////////////////

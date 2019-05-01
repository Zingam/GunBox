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
#include "System/HostPlatform/VulkanDevice.hpp"

////////////////////////////////////////////////////////////////////////////////
// Class declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(System)

class HostPlatform
{
  // Properties
public:
  HostPlatformClasses::FileSystem& FileSystem();
  HostPlatformClasses::OpenGLDevice& OpenGLDevice();
  HostPlatformClasses::SubSystems& SubSystems();
  HostPlatformClasses::SystemConsole& SystemConsole();
  HostPlatformClasses::SystemInfo& SystemInfo();
  HostPlatformClasses::VulkanDevice& VulkanDevice();

  // Data members
private:
  HostPlatformClasses::FileSystem fileSystem;
  HostPlatformClasses::OpenGLDevice openGLDevice;
  HostPlatformClasses::SubSystems subSystems;
  HostPlatformClasses::SystemConsole systemConsole;
  HostPlatformClasses::SystemInfo systemInfo;
  HostPlatformClasses::VulkanDevice vulkanDevice;
};

NAMESPACE_END(System)

////////////////////////////////////////////////////////////////////////////////
// Inline implementations
////////////////////////////////////////////////////////////////////////////////

#include "HostPlatform.inl"

////////////////////////////////////////////////////////////////////////////////

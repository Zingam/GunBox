#pragma once

////////////////////////////////////////////////////////////////////////////////
// Inline method implementations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(System)

////////////////////////////////////////////////////////////////////////////////
// Properties
////////////////////////////////////////////////////////////////////////////////

inline HostPlatformClasses::FileSystem&
HostPlatform::FileSystem()
{
  return fileSystem;
}

inline HostPlatformClasses::OpenGLDevice&
HostPlatform::OpenGLDevice()
{
  return openGLDevice;
}

inline HostPlatformClasses::SubSystems&
HostPlatform::SubSystems()
{
  return subSystems;
}

inline HostPlatformClasses::SystemConsole&
HostPlatform::SystemConsole()
{
  return systemConsole;
}

inline HostPlatformClasses::SystemInfo&
HostPlatform::SystemInfo()
{
  return systemInfo;
}

NAMESPACE_END(System)

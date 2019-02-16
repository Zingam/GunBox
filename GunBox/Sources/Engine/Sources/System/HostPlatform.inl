#pragma once

////////////////////////////////////////////////////////////////////////////////
// Inline method implementations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(System)

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

NAMESPACE_END(System)

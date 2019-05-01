#pragma once

////////////////////////////////////////////////////////////////////////////////
// Inline implementations
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

inline HostPlatformClasses::GPUDevice_OpenGL&
HostPlatform::GPUDevice_OpenGL()
{
  return gpuDevice_OpenGL;
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

inline HostPlatformClasses::GPUDevice_Vulkan&
HostPlatform::GPUDevice_Vulkan()
{
  return gpuDevice_Vulkan;
}

NAMESPACE_END(System)

#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

// Project headers - Common
#include "Common/implementedBy.hpp"
// Project headers - System
#include "System/HostPlatform/FileSystem.hpp"
#include "System/HostPlatform/GPUDevice_OpenGL.hpp"
#include "System/HostPlatform/GPUDevice_Vulkan.hpp"
#include "System/HostPlatform/SubSystems.hpp"
#include "System/HostPlatform/SystemConsole.hpp"
#include "System/HostPlatform/SystemInfo.hpp"

////////////////////////////////////////////////////////////////////////////////
// Class declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(System)

class HostPlatform
{
  // Properties
public:
  HostPlatformClasses::FileSystem& FileSystem();
  HostPlatformClasses::GPUDevice_OpenGL& GPUDevice_OpenGL();
  HostPlatformClasses::GPUDevice_Vulkan& GPUDevice_Vulkan();
  HostPlatformClasses::SubSystems& SubSystems();
  HostPlatformClasses::SystemConsole& SystemConsole();
  HostPlatformClasses::SystemInfo& SystemInfo();

  // Data members
private:
  HostPlatformClasses::FileSystem fileSystem;
  HostPlatformClasses::GPUDevice_OpenGL gpuDevice_OpenGL;
  HostPlatformClasses::GPUDevice_Vulkan gpuDevice_Vulkan;
  HostPlatformClasses::SubSystems subSystems;
  HostPlatformClasses::SystemConsole systemConsole;
  HostPlatformClasses::SystemInfo systemInfo;
};

NAMESPACE_END(System)

////////////////////////////////////////////////////////////////////////////////
// Inline implementations
////////////////////////////////////////////////////////////////////////////////

#include "HostPlatform.inl"

////////////////////////////////////////////////////////////////////////////////

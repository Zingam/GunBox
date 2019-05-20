#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

// C++ Standard Library
#include <vector>

////////////////////////////////////////////////////////////////////////////////
// Class declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(System::HostPlatformClasses)

using GPUDevice_Vulkan_Base = class GPUDevice_Vulkan_Base_Common
{
  // Constructors & Destructors
protected:
  GPUDevice_Vulkan_Base_Common();

  // Data members
protected:
  std::vector<char const*> validationLayerNames;
};

NAMESPACE_END(System::HostPlatformClasses)

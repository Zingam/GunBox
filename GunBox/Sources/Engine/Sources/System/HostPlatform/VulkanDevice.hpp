#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

// Project headers - System
#include "System/Platforms/SystemInfo_Implementation.hpp"

// Project headers - Common
#include "Common/implementedBy.hpp"

NAMESPACE_BEGIN(System::HostPlatformClasses)

class VulkanDevice : public implementedBy<SystemInfo_Implementation>
{
  // Methods
public:
  auto Initialize() const -> void;
};

NAMESPACE_END(System::HostPlatformClasses)

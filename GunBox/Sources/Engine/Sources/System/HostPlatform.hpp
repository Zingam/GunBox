#pragma once

// Project headers - Common
#include "Common/Macros/Base.hpp"
#include "Common/implementedBy.hpp"

// Project headers - System
#include "System/HostPlatform/SubSystems.hpp"
#include "System/HostPlatform/SystemConsole.hpp"

NAMESPACE_BEGIN(System)

class HostPlatform
{
public:
  HostPlatformClasses::SubSystems& SubSystems();
  HostPlatformClasses::SystemConsole& SystemConsole();

private:
  HostPlatformClasses::SubSystems subSystems;
  HostPlatformClasses::SystemConsole systemConsole;
};

NAMESPACE_END(System)

////////////////////////////////////////////////////////////////////////////////
// Inline method implementations
////////////////////////////////////////////////////////////////////////////////

#include "HostPlatform.inl"

////////////////////////////////////////////////////////////////////////////////

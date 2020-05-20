#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

// Project headers - System
#include "System/Platforms/ProcessSingleton_Implementation.hpp"

// Project headers - Common
#include "Common/implementedBy.hpp"

// C++ Standard Library
#include <string>

////////////////////////////////////////////////////////////////////////////////
// Class declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(System::HostPlatformClasses)

class ProcessSingleton : public implementedBy<ProcessSingleton_Implementation>
{
  // Properties
public:
  auto Initialized() -> bool;
  auto Running() -> bool;

  // Methods
public:
  auto Initialize(std::string const& applicationGUID) -> void;
};

NAMESPACE_END(System::HostPlatformClasses)

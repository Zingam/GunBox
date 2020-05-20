#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

// C++ Standard Library
#include <string>

////////////////////////////////////////////////////////////////////////////////
// Class declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(System::HostPlatformClasses)

using ProcessSingleton_Implementation = class ProcessSingleton_Windows
{
  // Properties
public:
  auto Initialized() -> bool;
  auto Running() -> bool;

public:
  auto Initialize(std::string const& applicationGUID) -> void;
  auto Finalize() -> void;

private:
  bool isInitalized = false;
  bool isRunning = false;
};

NAMESPACE_END(System::HostPlafroms)

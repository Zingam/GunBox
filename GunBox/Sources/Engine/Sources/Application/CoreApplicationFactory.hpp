#pragma once

// Project headers - Common
#include "Common/Macros/Base.hpp"

// Project headers - Application
#include "CommandLineArgs.hpp"
#include "CoreApplication.hpp"

NAMESPACE_START(Application)

////////////////////////////////////////////////////////////////////////////////
// Factory functions
////////////////////////////////////////////////////////////////////////////////

/// Creates an instance of a child class.
/// <remarks>
///   This method should be defined by the user externally as required.
///   <example>
///     std::unique_ptr<CoreApplication>*
///     CoreApplication::Create(std::string const& name,
///                         CommandLineArgs const& commandLineArgs)
///     {
///       return new Game("NewGame", commandLineArgs);
///     }
///   </example>
/// </<remarks>
extern auto
Create(std::string const& name, CommandLineArgs const& commandLineArgs)
  -> CoreApplication&;

////////////////////////////////////////////////////////////////////////////////

NAMESPACE_END(Application)

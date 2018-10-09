#pragma once

// Project headers - Common
#include "Common/Macros/Base.hpp"

// Project headers - Application
#include "CommandLineArgs.hpp"
#include "CoreApplication.hpp"

NAMESPACE_BEGIN(Application)

////////////////////////////////////////////////////////////////////////////////
// Factory functions
////////////////////////////////////////////////////////////////////////////////

/// <summary>
///   Creates a new specialized application object.
///   <para>
///   This is an interface factory function called by the <b>Engine</b> library
///   automatically. The user needs to provide a concrete specialized
///   implementation by subclassing the abstract
///   <code>class Application::CoreApplication</code>.
///   </para>
/// </summary>
/// <remarks>
///   This method allows calling of the concrete class instance from an abstract
///   base reference to <code>Application::CoreApplication</code>.
/// </remarks>
/// <example>
///   <code>
///   <![CDATA[
///   std::unique_ptr<CoreApplication>*
///   CoreApplication::Create(std::string const& name,
///                       CommandLineArgs const& commandLineArgs)
///   {
///     return new Game("NewGame", commandLineArgs);
///   }]]>
///   </code>
/// </example>
extern auto
Create()
  -> CoreApplication&;

////////////////////////////////////////////////////////////////////////////////

NAMESPACE_END(Application)

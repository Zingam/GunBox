// Self
#include "Commander_Interface.hpp"

// Project headers
#include "EventHandling/Commands/Command_Null.hpp"
#include "EventHandling/Commands/Command_UpdateApplicationState.hpp"

NAMESPACE_BEGIN(GunBox)

////////////////////////////////////////////////////////////////////////////////
// Constructors & Destructors
////////////////////////////////////////////////////////////////////////////////

Commander_Interface::Commander_Interface()
  : command_Null{ std::make_shared<Command_Null>() }
{}

Commander_Interface::~Commander_Interface() {}

NAMESPACE_END(GunBox)

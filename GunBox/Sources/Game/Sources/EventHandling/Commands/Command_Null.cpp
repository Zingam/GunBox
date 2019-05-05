// Self
#include "Command_Null.hpp"

// C++ Standard Library
#include <any>

NAMESPACE_BEGIN(GunBox)

Command_Null::~Command_Null() {}

void
Command_Null::Execute(std::any const& value)
{}

NAMESPACE_END(GunBox)

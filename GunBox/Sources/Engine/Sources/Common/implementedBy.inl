#pragma once

////////////////////////////////////////////////////////////////////////////////
// Inline method implementations
////////////////////////////////////////////////////////////////////////////////

template<typename Class>
implementedBy<Class>::implementedBy()
  : o_ptr{ std::make_unique<Class>() }
{}

template<typename Class>
bool
implementedBy<Class>::Initialize()
{
  return this->o_ptr->Initialize();
}

template<typename Class>
void
implementedBy<Class>::Finalize()
{
  this->o_ptr->Finalize();
}

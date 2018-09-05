#pragma once

// Project headers - Common
#include "Common/Macros/Base.hpp"

// C++ Standard Library
#include <memory>

template<typename Class>
class implementedBy
{
protected:
  implementedBy();

protected:
  std::unique_ptr<Class> o_ptr;
};

#include "implementeBy.inl"
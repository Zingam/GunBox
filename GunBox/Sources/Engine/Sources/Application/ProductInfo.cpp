// Self
#include "ProductInfo.hpp"

NAMESPACE_BEGIN(Application)

////////////////////////////////////////////////////////////////////////////////
// Constructors & Destructors
////////////////////////////////////////////////////////////////////////////////

ProductInfo::ProductInfo(std::string const& developer,
                         std::string const& name,
                         Version_t const& version)
  : developer{ developer }
  , name{ name }
  , version{ version }
{}

NAMESPACE_END(Application)

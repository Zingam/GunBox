// Self
#include "ApplicationInfo.hpp"

NAMESPACE_BEGIN(Application)

////////////////////////////////////////////////////////////////////////////////
// Constructors & Destructors
////////////////////////////////////////////////////////////////////////////////

ApplicationInfo::ApplicationInfo(std::string const& organization,
                                 std::string const& title,
                                 Version_t const& version)
  : organization{ organization }
  , title{ title }
  , version{ version }
{}

NAMESPACE_END(Application)

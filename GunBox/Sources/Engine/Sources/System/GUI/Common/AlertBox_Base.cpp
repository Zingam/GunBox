// Self
#include "AlertBox_Base.hpp"

NAMESPACE_BEGIN(System::GUI::Common)

AlertBox_Base::AlertBox_Base()
  : alertType{ AlertType_t::Error } {};

AlertBox_Base::AlertBox_Base(
  std::string const& caption,
  std::string const& content,
  AlertType_t alertType)
  : alertType{ alertType }
  , caption{ caption }
  , content{ content }
{}

NAMESPACE_END(System::GUI::Common)

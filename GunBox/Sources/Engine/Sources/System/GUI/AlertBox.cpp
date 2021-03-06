// Self
#include "AlertBox.hpp"

NAMESPACE_BEGIN(System::GUI)

////////////////////////////////////////////////////////////////////////////////
// Constructors & Destructors
////////////////////////////////////////////////////////////////////////////////

AlertBox::AlertBox(
  std::string const& caption,
  std::string const& content,
  System::GUI::Common::AlertBox_Base::AlertType_t alertType)
{
  this->o_ptr->Initialize(caption, content, alertType);
}

////////////////////////////////////////////////////////////////////////////////
// Methods
////////////////////////////////////////////////////////////////////////////////

void
AlertBox::Show()
{
  this->o_ptr->Show();
}

NAMESPACE_END(System::GUI)

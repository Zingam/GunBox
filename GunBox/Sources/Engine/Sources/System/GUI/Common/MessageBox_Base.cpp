// Self
#include "MessageBox_Base.hpp"

NAMESPACE_BEGIN(System::GUI::Common)

MessageBox_Base::MessageBox_Base(){};

MessageBox_Base::MessageBox_Base(
  std::string const& caption,
  std::string const& content,
  MessageType_t messageType)
  : caption{ caption }
  , content{ content }
  , messageType{ messageType }
{}

NAMESPACE_END(System::GUI::Common)

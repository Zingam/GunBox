#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

// Project headers - Common
#include "Common/implementedBy.hpp"
// Project headers - System
#include "System/Platforms/MessageBox_Implementation.hpp"

// C++ Standard Library
#include <string>

////////////////////////////////////////////////////////////////////////////////
// Class declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(System::GUI)

class MessageBox
  : public implementedBy<System::GUI::MessageBox_Implementation>
{
public:
  MessageBox(
    std::string const& caption,
    std::string const& content,
    System::GUI::Common::MessageBox_Base::MessageType_t messageType);

public:
  auto Show() -> void;
};

NAMESPACE_END(System::GUI)

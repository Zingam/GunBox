#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

// Project headers - Common
#include "Common/implementedBy.hpp"
// Project headers - System
#include "System/Platforms/AlertBox_Implementation.hpp"

// C++ Standard Library
#include <string>

////////////////////////////////////////////////////////////////////////////////
// Class declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(System::GUI)

class AlertBox
  : public implementedBy<System::GUI::AlertBox_Implementation>
{
public:
  AlertBox(
    std::string const& caption,
    std::string const& content,
    System::GUI::Common::AlertBox_Base::AlertType_t alertType);

public:
  auto Show() -> void;
};

NAMESPACE_END(System::GUI)

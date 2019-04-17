#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

// C++ Standard Library
#include <string>

////////////////////////////////////////////////////////////////////////////////
// Class declarations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(System::GUI::Common)

class AlertBox_Base
{
  // Types
public:
  enum class AlertType_t
  {
    Error,
    Info,
    Warning
  };

  // Constructors & Destructors
protected:
  AlertBox_Base();
  AlertBox_Base(
    std::string const& caption,
    std::string const& content,
    AlertType_t alertType);

  // Variables
protected:
  AlertType_t alertType;
  std::string caption;
  std::string content;
};

NAMESPACE_END(System::GUI::Common)

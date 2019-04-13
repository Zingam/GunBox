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

class MessageBox_Base
{
  // Types
public:
  enum class MessageType_t
  {
    Error,
    Info,
    Warning
  };

  // Constructors & Destructors
protected:
  MessageBox_Base();
  MessageBox_Base(
    std::string const& caption,
    std::string const& content,
    MessageType_t messageType);

  // Variables
protected:
  std::string caption;
  std::string content;
  MessageType_t messageType;
};

NAMESPACE_END(System::GUI::Common)

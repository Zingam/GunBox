// Self
#include "MessageBox_SDL2.hpp"

// Project headers - System
#include "System/Platforms/SDL2/SDL2_ErrorChecking.hpp"

// Third party libraries
#include <SDL.h>

NAMESPACE_BEGIN(System::GUI)

////////////////////////////////////////////////////////////////////////////////
// Methods
////////////////////////////////////////////////////////////////////////////////

void
MessageBox_SDL::Initialize(
  std::string const& caption,
  std::string const& content,
  System::GUI::Common::MessageBox_Base::MessageType_t messageType)
{
  this->caption = caption;
  this->content = content;
  this->messageType = messageType;
}

void
MessageBox_SDL::Show()
{
  using namespace System::GUI::Common;

  auto messageType = SDL_MESSAGEBOX_ERROR;
  switch (this->messageType) {
    case MessageBox_Base::MessageType_t::Error: {
      messageType = SDL_MESSAGEBOX_ERROR;
      break;
    }
    case MessageBox_Base::MessageType_t::Info: {
      messageType = SDL_MESSAGEBOX_INFORMATION;
    }
    case MessageBox_Base::MessageType_t::Warning: {
      messageType = SDL_MESSAGEBOX_WARNING;
      break;
    }
  }

  SDL_ShowSimpleMessageBox(
    messageType, caption.c_str(), content.c_str(), nullptr);
}

NAMESPACE_END(System::GUI)

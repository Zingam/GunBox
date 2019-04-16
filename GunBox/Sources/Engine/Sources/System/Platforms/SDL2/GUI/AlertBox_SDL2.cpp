// Self
#include "AlertBox_SDL2.hpp"

// Project headers - System
#include "System/Platforms/SDL2/SDL2_ErrorChecking.hpp"

// Third party libraries
#include <SDL.h>

NAMESPACE_BEGIN(System::GUI)

////////////////////////////////////////////////////////////////////////////////
// Methods
////////////////////////////////////////////////////////////////////////////////

void
AlertBox_SDL::Initialize(
  std::string const& caption,
  std::string const& content,
  System::GUI::Common::AlertBox_Base::AlertType_t alertType)
{
  this->caption = caption;
  this->content = content;
  this->alertType = alertType;
}

void
AlertBox_SDL::Show()
{
  using namespace System::GUI::Common;

  auto alertType = SDL_MESSAGEBOX_WARNING;
  switch (this->alertType) {
    case AlertBox_Base::AlertType_t::Error: {
      alertType = SDL_MESSAGEBOX_ERROR;
      break;
    }
    case AlertBox_Base::AlertType_t::Info: {
      alertType = SDL_MESSAGEBOX_INFORMATION;
      break;
    }
    case AlertBox_Base::AlertType_t::Warning: {
      [[fallthrough]];
    }
    default: {}
  }

  SDL_ShowSimpleMessageBox(
    alertType, caption.c_str(), content.c_str(), nullptr);
}

NAMESPACE_END(System::GUI)

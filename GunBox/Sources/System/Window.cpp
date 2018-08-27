// Self
#include "Window.hpp"

// Third party
#include <SDL_video.h>

// C Standard Library
#include <cassert>
// C++ Standard Library
#include <sstream>

NAMESPACE_START(System)

////////////////////////////////////////////////////////////////////////////////
// Constructors & Destructors
////////////////////////////////////////////////////////////////////////////////

Window::Window(std::string title, Properties properties)
  : handle{ nullptr }
  , properties{ properties }
  , title{ title }
{}

Window::~Window()
{
  Destroy();
}

////////////////////////////////////////////////////////////////////////////////
// Properties
////////////////////////////////////////////////////////////////////////////////

Point2D
Window::Position()
{
  Point2D coordinate;
  SDL_GetWindowPosition(handle, &coordinate.X, &coordinate.Y);
  return coordinate;
}

////////////////////////////////////////////////////////////////////////////////
// Methods
////////////////////////////////////////////////////////////////////////////////

void
Window::Destroy()
{
  if (nullptr != handle) {
    // Current window state
    properties.Coordinate = Position();
    properties.Location = Properties::Location_t::Custom;
    // Clean up
    SDL_DestroyWindow(handle);
    handle = nullptr;
  }
}

void
Window::Hide()
{
  if (nullptr != handle) {
    SDL_HideWindow(handle);
  }
}

bool
Window::Show()
{
  if (nullptr != handle) {
    SDL_ShowWindow(handle);
  } else {
    Uint32 windowFlags = 0;

    switch (properties.Fullscreen) {
      case Properties::FullscreenState_t::Custom: {
        windowFlags |= SDL_WINDOW_FULLSCREEN;
        break;
      }
      case Properties::FullscreenState_t::Desktop: {
        windowFlags |= SDL_WINDOW_FULLSCREEN_DESKTOP;
        break;
      }
      case Properties::FullscreenState_t::Windowed: {
        break;
      }
    }

    switch (properties.Location) {
      case Properties::Location_t::Centered: {
        properties.Coordinate.X = SDL_WINDOWPOS_CENTERED;
        properties.Coordinate.Y = SDL_WINDOWPOS_CENTERED;
        break;
      }
      case Properties::Location_t::Custom: {
        break;
      }
      case Properties::Location_t::Default: {
        properties.Coordinate.X = SDL_WINDOWPOS_UNDEFINED;
        properties.Coordinate.Y = SDL_WINDOWPOS_UNDEFINED;
        break;
      }
    }

    switch (properties.RendererAPI) {
      case Renderer::API_t::Direct3D_12: {
        break;
      }
      case Renderer::API_t::OpenGL: {
        windowFlags |= SDL_WINDOW_OPENGL;
        break;
      }
      case Renderer::API_t::Vulkan: {
        windowFlags |= SDL_WINDOW_VULKAN;
        break;
      }
      default: {
        assert(false && "Unsupported rendering API!");
      }
    }

    handle = SDL_CreateWindow(title.c_str(),
                              properties.Coordinate.X,
                              properties.Coordinate.Y,
                              properties.Size.Width,
                              properties.Size.Height,
                              windowFlags);

    if (nullptr == handle) {
      std::stringstream ss;
      ss << SDL_GetError();
      return false;
    }
  }

  return true;
}

NAMESPACE_END(System)

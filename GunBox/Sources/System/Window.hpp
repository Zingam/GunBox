#pragma once

// Project headers - Common
#include "Common/Macros/Base.hpp"

// Project headers - System
#include "Geometry.hpp"
#include "RendererBase.hpp"

// C++ Standard Library
#include <string>

struct SDL_Window;

NAMESPACE_START(System)

class Window
{

public:
  struct Properties
  {
    enum class FullscreenState_t
    {
      Custom,
      Desktop,
      Windowed
    };

    enum class Location_t
    {
      Centered,
      Custom,
      Default
    };

    Point2D Coordinate;
    FullscreenState_t Fullscreen;
    Location_t Location;
    Renderer::API_t RendererAPI;
    Dimensions Size;
  };

public:
  Window(std::string title, Properties properties);
  ~Window();

public:
  Point2D Position();

public:
  auto Destroy() -> void;
  auto Hide() -> void;
  auto Show() -> bool;
  auto Id() -> SDL_Window* { return handle; };

private:
  SDL_Window* handle;
  Properties properties;
  std::string title;
};

NAMESPACE_END(System)

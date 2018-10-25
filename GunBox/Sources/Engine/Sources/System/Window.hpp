#pragma once

// BASE MACROS header
#include "Common/Macros/Base.hpp"

// Project headers - System
#include "System/DeviceTypes/Graphics/GeometryTypes.hpp"
#include "System/DeviceTypes/Graphics/RendererTypes.hpp"

// C++ Standard Library
#include <string>

struct SDL_Window;

NAMESPACE_BEGIN(System)

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

    DeviceTypes::Graphics::Point2D Coordinate;
    FullscreenState_t Fullscreen;
    Location_t Location;
    DeviceTypes::Graphics::API_t RendererAPI;
    DeviceTypes::Graphics::Dimensions Size;
  };

public:
  Window(std::string const& title, Properties const& properties);
  ~Window();

public:
  auto Id() const -> SDL_Window*;
  DeviceTypes::Graphics::Point2D Position();

public:
  auto Destroy() -> void;
  auto Hide() -> void;
  auto Show() -> bool;

private:
  SDL_Window* handle;
  Properties properties;
  std::string title;
};

NAMESPACE_END(System)

////////////////////////////////////////////////////////////////////////////////
// Inline method implementations
////////////////////////////////////////////////////////////////////////////////

#include "Window.inl"

////////////////////////////////////////////////////////////////////////////////

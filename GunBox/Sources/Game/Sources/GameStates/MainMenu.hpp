#pragma once

// BASE MACROS header
#include "Common/Macros/Base.hpp"

// Project headers
#include "GameStates/GameStateTypes.hpp"

// Engine headers - Renderer
//#include "Renderer/Graphics/GraphicsRenderer_Interface.hpp"

// C++ Standard Library
#include <memory>

NAMESPACE_BEGIN(Renderer::Graphics)

class GraphicsRenderer_Interface;

NAMESPACE_END(Renderer::Graphics)

NAMESPACE_BEGIN(GunBox)

class MainMenu
{
public:
  auto Initialize(
    std::shared_ptr<Renderer::Graphics::GraphicsRenderer_Interface>
      graphicsRenderer) -> void;
  auto Update() -> GameState_t;

  // Command actions
public:
  auto Accept() -> void;
  auto Back() -> void;
  auto MoveDown() -> void;
  auto MoveLeft() -> void;
  auto MoveRight() -> void;
  auto MoveUp() -> void;
  auto Quit() -> void;

private:
  std::shared_ptr<Renderer::Graphics::GraphicsRenderer_Interface>
    graphicsRenderer;
  bool isQuitting = false;
  bool isRequestingToQuit = false;
  GameState_t nextGameState = GameState_t::MainMenu;
};

NAMESPACE_END(GunBox)

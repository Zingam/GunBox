#pragma once

// Engine headers - BASE
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
  auto Initialize(std::shared_ptr<Renderer::Graphics::GraphicsRenderer_Interface>
             graphicsRenderer) -> void;
  auto Update() -> GameState_t;

private:
  std::shared_ptr<Renderer::Graphics::GraphicsRenderer_Interface>
    graphicsRenderer;
  GameState_t nextGameState = GameState_t::MainMenu;
  bool isQuitting = false;
};

NAMESPACE_END(GunBox)

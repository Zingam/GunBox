#pragma once

// Project headers - Common
#include "Common/Macros/Base.hpp"

// C Standard Library
#include <cstdint>

// C++ Standard Library
#include <map>

struct _SDL_GameController;
using SDL_GameController = _SDL_GameController;

NAMESPACE_BEGIN(System)

class InputProcessor
{
public:
  using GameControllerId = std::int32_t;

public:
  ~InputProcessor();

public:
  auto AddGameController(GameControllerId const gameControllerId) -> void;
  auto RemoveGameController(GameControllerId const gameControllerId) -> void;

private:
  std::map<GameControllerId const, SDL_GameController*> gameControllers;
};

NAMESPACE_END(System)

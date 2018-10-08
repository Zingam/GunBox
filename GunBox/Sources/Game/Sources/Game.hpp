#pragma once

// Project headers - Common
#include "Common/Macros/Base.hpp"

// Engine headers - Application
#include "Application/CommandLineArgs.hpp"
#include "Application/CoreApplication.hpp"

// C++ Standard Library
#include <string>

NAMESPACE_START(GunBox)

class Game : public Application::CoreApplication
{
public:
  Game(ProductInfo name);
  ~Game() final;

  // Pure virtual methods
public:
  auto Execute() -> ExitCode final;
};

NAMESPACE_END(GunBox)

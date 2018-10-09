#pragma once

// Project headers - Common
#include "Common/Macros/Base.hpp"

// Engine headers - Application
#include "Application/ApplicationInfo.hpp"
#include "Application/CommandLineArgs.hpp"
#include "Application/CoreApplication.hpp"

// C++ Standard Library
#include <string>

NAMESPACE_BEGIN(GunBox)

class Game : public Application::CoreApplication
{
public:
  Game(Application::ProductInfo name);
  ~Game() final;

  // Pure virtual methods
public:
  auto Execute() -> ExitCode final;
};

NAMESPACE_END(GunBox)

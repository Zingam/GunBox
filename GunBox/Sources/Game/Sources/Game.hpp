#pragma once

// BASE MACROS header
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
  Game(Application::ApplicationInfo title);
  ~Game() final;

  // Virtual methods
public:
  auto Execute() -> Application::ExitCode final;
};

NAMESPACE_END(GunBox)

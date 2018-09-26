// Project headers - Common
#include "Common/Constants/GpuPreferences.hpp"
#include "Common/Macros/Base.hpp"
#include "Common/Macros/SDL2_ErrorChecking.hpp"

#if defined(WIN32_LEAN_AND_MEAN)
// clang-format off
#  pragma message(pragma_message_FileInfo(                                     \
  "Compiling project with \"WIN32_LEAN_AND_MEAN\""))
// clang-format on
#endif

// Project headers - Application
#include "Application/CommandLineArgs.hpp"
#include "Application/CoreApplication.hpp"
#include "Application/CoreApplicationFactory.hpp"
// Project headers - Renderer
#include "Renderer/OpenGL/OpenGL.hpp"
#include "Renderer/RendererBase.hpp"
// Project headers - System
#include "System/Monitor.hpp"
#include "System/Preferences.hpp"
#include "System/Window.hpp"

// Third party libraries
#include <SDL.h>

// C Standard library
#include <cassert>
// C++ Standard library
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>

int
main(int argc, char* argv[])
{
  Application::CommandLineArgs commandLineArgs;
  auto hasParsingError = commandLineArgs.Parse(argc, argv);
  if (hasParsingError) {
    std::stringstream errorMessage;
    errorMessage << "Error parsing command line arguments.\n";
    errorMessage << hasParsingError.value() << "\n";

    SDL_ShowSimpleMessageBox(
      SDL_MESSAGEBOX_ERROR, "GunBox", errorMessage.str().c_str(), nullptr);
    return -1;
  }

  auto& application = Application::Create("GunBox", commandLineArgs);
  SDL_Log("Initalizing: %s", application.Name().c_str());
  application.Execute();

  System::Preferences preferences{ "RMM", "GunBox" };
  auto hasLoadingError = preferences.LoadFromFile();
  if (hasLoadingError) {
    std::stringstream errorMessage;
    errorMessage << "Error loading preferences from file:\n";
    errorMessage << "    " << hasLoadingError.value() << "\n";
    errorMessage << "Using default values!";

    SDL_ShowSimpleMessageBox(
      SDL_MESSAGEBOX_ERROR, "GunBox", errorMessage.str().c_str(), nullptr);

    // Main window
    preferences.SetMainWindowDefaultValues();
  }

  SDL_IfFailed(
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_GAMECONTROLLER))
  {
    SDL_LogError("Unable to initialize SDL: %s", SDL_GetError());
    return -1;
  }
  // Clean up
  atexit(SDL_Quit);

  auto monitors = System::EnumerateMonitors();

  System::Window::Properties properties{};
  properties.Coordinate.X = preferences.MainWindowMetrics().Coordinate.X;
  properties.Coordinate.Y = preferences.MainWindowMetrics().Coordinate.Y;
  if (preferences.Fullscreen()) {
    properties.Fullscreen =
      System::Window::Properties::FullscreenState_t::Desktop;
  } else {
    properties.Fullscreen =
      System::Window::Properties::FullscreenState_t::Windowed;
  }
  if (hasLoadingError) {
    properties.Location = System::Window::Properties::Location_t::Centered;
  } else {
    properties.Location = System::Window::Properties::Location_t::Custom;
  }
  properties.RendererAPI = preferences.RendererAPI();
  properties.Size.Height = preferences.MainWindowMetrics().Size.Height;
  properties.Size.Width = preferences.MainWindowMetrics().Size.Width;

  SDL_GL_LoadLibrary(NULL);
  System::Window window{ "GunBox", properties };
  window.Show();

  SDL_GLContext glContext = nullptr;
  SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
  // Search for the highest possible context version
  for (int version = 6; 0 <= version; --version) {
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, version);
    glContext = SDL_GL_CreateContext(window.Id());
    if (nullptr == glContext) {
      continue;
    }
    break;
  }
  if (nullptr == glContext) {
    SDL_LogError("Unable to create OpenGL context: %s", SDL_GetError());
    return -1;
  }

  auto version = InitializeOpenGL((GLADloadfunc)SDL_GL_GetProcAddress);
  if (0 != version) {
    auto vendor = glGetString(GL_VENDOR);
    auto renderer = glGetString(GL_RENDERER);
    auto version = glGetString(GL_VERSION);
    auto glslVersion = glGetString(GL_SHADING_LANGUAGE_VERSION);

    SDL_Log("OpenGL:");
    SDL_Log("  Vendor:       %s", vendor);
    SDL_Log("  Renderer:     %s", renderer);
    SDL_Log("  Version:      %s", version);
    SDL_Log("  GLSL version: %s", glslVersion);

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    SDL_GL_SwapWindow(window.Id());
  } else {
    SDL_GL_DeleteContext(glContext);
    SDL_LogError("Failed to load OpenGL functions pointers.");
    return -1;
  }

  std::map<Sint32, SDL_GameController*> gameControllers;

  bool isRunning = true;
  bool isQuitting = false;

  float r = 0.0f;
  float g = 0.0f;
  float b = 0.0f;

  // Event handler
  SDL_Event e;
  // While application is running
  while (isRunning) {
    // Handle events on queue
    while (SDL_PollEvent(&e) != 0) {
      // User requests quit
      if (e.type == SDL_QUIT) {
        isQuitting = true;
      }
      if (e.type == SDL_CONTROLLERDEVICEADDED) {
        auto deviceId = e.cdevice.which;
        auto gameController = SDL_GameControllerOpen(deviceId);
        if (gameController == nullptr) {
          SDL_LogError("Unable to open game controller");
        } else {
          gameControllers[deviceId] = gameController;
        }
      }
      if (e.type == SDL_CONTROLLERDEVICEREMOVED) {
        auto deviceId = e.cdevice.which;
        auto gameController = gameControllers[deviceId];
        SDL_GameControllerClose(gameController);
        gameControllers[deviceId] = nullptr;
      }
      if (e.type == SDL_CONTROLLERBUTTONDOWN) {
        if (e.cbutton.button == SDL_CONTROLLER_BUTTON_BACK) {
          if (isQuitting) {
            isRunning = false;
          }
        }
        if (e.cbutton.button == SDL_CONTROLLER_BUTTON_START) {
          isQuitting = false;
        }
      }
    }

    r = (1.0f < r) ? (0.0f) : (r + 0.01f);
    g = (1.0f < g) ? (0.0f) : (g + 0.02f);
    b = (1.0f < b) ? (0.0f) : (b + 0.03f);

    GL__(glClearColor, r, g, b, 0.0f);
    GL__(glClear, GL_COLOR_BUFFER_BIT);

    SDL_GL_SwapWindow(window.Id());
  }

  for (auto [id, gameController] : gameControllers) {
    SDL_GameControllerClose(gameController);
    gameControllers[id] = nullptr;
  }

  SDL_GL_DeleteContext(glContext);

  auto position = window.Position();
  preferences.MainWindowMetrics().Coordinate.X = position.X;
  preferences.MainWindowMetrics().Coordinate.Y = position.Y;

  auto hasSaveError = preferences.SaveToFile();
  if (hasSaveError) {
    std::string errorMessage{ "Unable to save preferences!\n"
                              "    Error:\n" };
    errorMessage += hasSaveError.value();
    SDL_ShowSimpleMessageBox(
      SDL_MESSAGEBOX_ERROR, "GunBox", errorMessage.c_str(), nullptr);
  }

  return 0;
}

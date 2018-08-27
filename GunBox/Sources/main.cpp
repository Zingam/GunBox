// Project headers
#include "System/Preferences.hpp"
#include "System/Window.hpp"

// Third party libraries
#if defined(_WIN32)
// Defining APIENTRY manually will prevent 'glad' from including "Windows.h"
#  define APIENTRY __stdcall
#endif
#include <glad/glad.h>
#if defined(_WINDOWS_)
#  error Windows.h was included!
#endif
#include <SDL.h>

// C Standard library
#include <cassert>
// C++ Standard library
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>

#if !defined(SDL_IfFailed)
#  define SDL_IfFailed(function_call) if (0 > function_call)
#else
#  error SDL_IfFailed is already defined
#endif

#if !defined(SDL_LogError)
#  define SDL_LogError(...)                                                    \
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, __VA_ARGS__)
#else
#  error SDL_LogError is already defined
#endif

#define USE_INTEGRATED_GPU

#if !defined(USE_INTEGRATED_GPU)
// NVIDIA
extern "C"
{
  __declspec(dllexport) unsigned long NvOptimusEnablement = 0x00000001;
}
// AMD
extern "C"
{
  __declspec(dllexport) int AmdPowerXpressRequestHighPerformance = 1;
}
#endif

int
main(int argc, char* argv[])
{
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

  auto videoDriverCount = SDL_GetNumVideoDrivers();
  SDL_IfFailed(videoDriverCount)
  {
    SDL_LogError("Unable to get video driver count: %s", SDL_GetError());
    return -1;
  }

  SDL_Log("Video:");
  for (auto i = 0; i < videoDriverCount; ++i) {
    SDL_Log("  Video driver: %s", SDL_GetVideoDriver(i));
  }

  auto videoDisplayCount = SDL_GetNumVideoDisplays();
  SDL_IfFailed(videoDisplayCount)
  {
    SDL_LogError("Unable to get video display count: %s", SDL_GetError());
    return -1;
  }

  std::vector<SDL_Rect> displayBounds(videoDisplayCount);
  for (auto i = 0; i < videoDisplayCount; ++i) {
    SDL_GetDisplayBounds(i, &displayBounds[i]);
    SDL_Log("  Video display name: %s", SDL_GetDisplayName(i));
  }

  System::Window::Properties properties;
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

  if (gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
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
    glClearColor(r, g, b, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
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

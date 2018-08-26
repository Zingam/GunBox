// Project headers
#include "System/Preferences.hpp"

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

#define SDL_IfFailed(function_call) if (0 > function_call)

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
    // Set default position
    preferences.MainWindowMetrics().Coordinate.X = SDL_WINDOWPOS_CENTERED;
    preferences.MainWindowMetrics().Coordinate.Y = SDL_WINDOWPOS_CENTERED;
    preferences.RendererType() = System::RendererType::OpenGL;
  }

  SDL_IfFailed(
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_GAMECONTROLLER))
  {
    SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
    return -1;
  }

  auto videoDriverCount = SDL_GetNumVideoDrivers();
  SDL_IfFailed(videoDriverCount)
  {
    SDL_Log("Unable to get video driver count: %s", SDL_GetError());
    return -1;
  }

  for (auto i = 0; i < videoDriverCount; ++i) {
    SDL_Log("  Video driver: %s", SDL_GetVideoDriver(i));
  }

  auto videoDisplayCount = SDL_GetNumVideoDisplays();
  SDL_IfFailed(videoDisplayCount)
  {
    SDL_Log("Unable to get video display count: %s", SDL_GetError());
    return -1;
  }

  std::vector<SDL_Rect> displayBounds(videoDisplayCount);
  for (auto i = 0; i < videoDisplayCount; ++i) {
    SDL_GetDisplayBounds(i, &displayBounds[i]);
    SDL_Log("  Video display name: %s", SDL_GetDisplayName(i));
  }

  Uint32 windowFlags = 0;
  switch (preferences.RendererType()) {
    case System::RendererType::OpenGL: {
      windowFlags |= SDL_WINDOW_OPENGL;
      break;
    }
    case System::RendererType::Vulkan: {
      windowFlags |= SDL_WINDOW_VULKAN;
      break;
    }
    default:
    {
      // Unsupported renderer
      assert(0 != windowFlags);
    }
  }

  SDL_Window* window =
    SDL_CreateWindow("GunBox",
                     preferences.MainWindowMetrics().Coordinate.X,
                     preferences.MainWindowMetrics().Coordinate.Y,
                     preferences.MainWindowMetrics().Size.Width,
                     preferences.MainWindowMetrics().Size.Height,
                     windowFlags);

  std::map<Sint32, SDL_GameController*> gameControllers;

  bool isRunning = true;
  bool isQuitting = false;

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
          SDL_Log("Unable to open game controller");
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
  }

  for (auto [id, gameController] : gameControllers) {
    SDL_GameControllerClose(gameController);
    gameControllers[id] = nullptr;
  }

  SDL_GetWindowPosition(window,
                        &preferences.MainWindowMetrics().Coordinate.X,
                        &preferences.MainWindowMetrics().Coordinate.Y);

  SDL_DestroyWindow(window);

  auto hasSaveError = preferences.SaveToFile();
  if (hasSaveError) {
    std::string errorMessage{ "Unable to save preferences!\n"
                              "Error:\n" };
    errorMessage += hasSaveError.value();
    SDL_ShowSimpleMessageBox(
      SDL_MESSAGEBOX_ERROR, "GunBox", errorMessage.c_str(), nullptr);
  }

  // Clean up
  SDL_Quit();

  return 0;
}

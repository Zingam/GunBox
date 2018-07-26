// Project headers
#include "System/Preferences.hpp"
// Third party libraries
#include <SDL.h>
// C++ Standard library
#include <filesystem>
#include <fstream>
#include <iostream>
#include <vector>

#define SDL_IfFail(function_call) if (0 > function_call)

int
main(int argc, char* argv[])
{
  SDL_IfFail(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO))
  {
    SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
    return -1;
  }

  auto videoDriverCount = SDL_GetNumVideoDrivers();
  SDL_IfFail(videoDriverCount)
  {
    SDL_Log("Unable to get video driver count: %s", SDL_GetError());
    return -1;
  }

  for (auto i = 0; i < videoDriverCount; ++i) {
    SDL_Log("  Video driver: %s", SDL_GetVideoDriver(i));
  }

  auto videoDisplayCount = SDL_GetNumVideoDisplays();
  SDL_IfFail(videoDisplayCount)
  {
    SDL_Log("Unable to get video display count: %s", SDL_GetError());
    return -1;
  }

  std::vector<SDL_Rect> displayBounds(videoDisplayCount);
  for (auto i = 0; i < videoDisplayCount; ++i) {
    SDL_GetDisplayBounds(i, &displayBounds[i]);
    SDL_Log("  Video display name: %s", SDL_GetDisplayName(i));
  }

  SDL_Window* window = SDL_CreateWindow("GunBox",
                                        SDL_WINDOWPOS_CENTERED,
                                        SDL_WINDOWPOS_CENTERED,
                                        640,
                                        480,
                                        SDL_WINDOW_OPENGL);
  SDL_DestroyWindow(window);

  Preferences preferences{ "RMM", "GunBox" };
  auto hasLoadingError = preferences.LoadFromFile();
  if (hasLoadingError) {
    std::string errorMessage{ "Unable to load preferences!\n"
                              "Using defaults...\n"
                              "Error:\n" };
    errorMessage += hasLoadingError.value();
    SDL_ShowSimpleMessageBox(
      SDL_MESSAGEBOX_ERROR, "GunBox", errorMessage.c_str(), nullptr);
    preferences.SetDefaultValues();
  }

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

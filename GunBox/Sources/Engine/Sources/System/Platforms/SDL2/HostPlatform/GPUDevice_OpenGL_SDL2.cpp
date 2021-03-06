// Self
#include "GPUDevice_OpenGL_SDL2.hpp"

// Project headers - Logger
#include "Logger/LogAPI.hpp"
// Project headers - System
#include "System/Platforms/SDL2/SDL2_ErrorChecking.hpp"
#include "System/GUI/Window.hpp"

// Third party libraries
#include <SDL_video.h>

// C Standard Library
#include <cassert>

NAMESPACE_BEGIN(System::HostPlatformClasses)

////////////////////////////////////////////////////////////////////////////////
// Constructors & Destructors
////////////////////////////////////////////////////////////////////////////////

GPUDevice_OpenGL_SDL::GPUDevice_OpenGL_SDL()
  : openGLContextVersion{ 0, 0, 0, 0, 0 }
{}

////////////////////////////////////////////////////////////////////////////////
// Properties
////////////////////////////////////////////////////////////////////////////////

auto
GPUDevice_OpenGL_SDL::GetProcAddress() -> void*
{
  return reinterpret_cast<void*>(SDL_GL_GetProcAddress);
}

////////////////////////////////////////////////////////////////////////////////
// Methods
////////////////////////////////////////////////////////////////////////////////

void
GPUDevice_OpenGL_SDL::Finalize()
{
  assert((nullptr != openGLContext) && "Invalid OpenGL context");

  if (nullptr != openGLContext) {
    SDL_GL_DeleteContext(openGLContext);
    openGLContext = nullptr;
  }
}

bool
GPUDevice_OpenGL_SDL::Initialize(Window const& window)
{
  openGLContextVersion.ContextProfile = SDL_GL_CONTEXT_PROFILE_CORE;
  openGLContextVersion.SupportedMajorVersion = 4;
  openGLContextVersion.SupportedMinorVersion = 6;
  openGLContextVersion.MinimalSupportedMajorVersion = 3;
  openGLContextVersion.MinimalSupportedMinorVersion = 0;

  platformName = SDL_GetPlatform();

  if ("Android" == platformName) {
    openGLContextVersion.ContextProfile = SDL_GL_CONTEXT_PROFILE_ES;
    openGLContextVersion.SupportedMajorVersion = 3;
    openGLContextVersion.SupportedMinorVersion = 2;
  }

  this->window = &window;

  SDL_IfFailed(SDL_GL_LoadLibrary(nullptr))
  {
    reLogE("Unable to load OpenGL library: ", SDL_GetError());

    return false;
  }

  return true;
}

bool
GPUDevice_OpenGL_SDL::InitializeContext()
{
  assert((!platformName.empty()) && "GPUDevice_OpenGL is not initialized");

  SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
  SDL_GL_SetAttribute(
    SDL_GL_CONTEXT_PROFILE_MASK, openGLContextVersion.ContextProfile);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
  for (int majorVersion = openGLContextVersion.SupportedMajorVersion;
       openGLContextVersion.MinimalSupportedMajorVersion <= majorVersion;
       --majorVersion) {
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, majorVersion);
    // Search for the highest possible context version
    for (int minorVersion = openGLContextVersion.SupportedMinorVersion;
         openGLContextVersion.MinimalSupportedMinorVersion <= minorVersion;
         --minorVersion) {
      SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, minorVersion);
      openGLContext = SDL_GL_CreateContext(window->Id());
      if (nullptr != openGLContext) {
        // Get out of the nested loops
        majorVersion = -1;
        break;
      }
    }
  }
  if (nullptr == openGLContext) {
    // TODO: Replace with a message box
    reLogE("Unable to create OpenGL context: ", SDL_GetError());

    return false;
  }

  return true;
}

auto
GPUDevice_OpenGL_SDL::SwapBuffer() -> void
{
  SDL_GL_SwapWindow(window->Id());
}

NAMESPACE_END(System::HostPlatformClasses)

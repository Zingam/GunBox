// Self
#include "GraphicsRenderer_OpenGL.hpp"

// Project headers - Logger
#include "Logger/LogAPI.hpp"
// Project headers - Renderer
#include "Renderer/Graphics/OpenGL/OpenGL.hpp"
// Project headers - System
#include "System/HostPlatform.hpp"

// C Standard Library
#include <cassert>

NAMESPACE_BEGIN(Renderer::Graphics)

////////////////////////////////////////////////////////////////////////////////
// Constructors & Destructors
////////////////////////////////////////////////////////////////////////////////

GraphicsRenderer_OpenGL::GraphicsRenderer_OpenGL(
  Application::ApplicationInfo const& info,
  Application::Preferences& preferences,
  System::HostPlatform& hostPlatform)
  : GraphicsRenderer_Interface{ info, preferences, hostPlatform }
{}

GraphicsRenderer_OpenGL::~GraphicsRenderer_OpenGL() {}

bool
GraphicsRenderer_OpenGL::Initialize()
{
  assert(!isInitialized && "Renderer is already initialized!");

  auto& openGLDevice = hostPlatform.OpenGLDevice();
  auto isSuccess = openGLDevice.Initialize(*window);
  if (isSuccess) {
    isSuccess = GraphicsRenderer_Interface::Initialize();
    if (isSuccess) {
      isSuccess = openGLDevice.InitializeContext();
      if (isSuccess) {
        auto getProcAddress = openGLDevice.GetProcAddress();
        auto version = InitializeOpenGL((GLADloadfunc)getProcAddress);
        if (0 != version) {
          auto vendor = glGetString(GL_VENDOR);
          auto renderer = glGetString(GL_RENDERER);
          auto version = glGetString(GL_VERSION);
          auto glslVersion = glGetString(GL_SHADING_LANGUAGE_VERSION);

          reLogI("Graphics Renderer: OpenGL");
          reLogI("  Vendor:          ", vendor);
          reLogI("  Renderer:        ", renderer);
          reLogI("  Version:         ", version);
          reLogI("  GLSL version:    ", glslVersion);

          isInitialized = true;

          return isInitialized;
        }
      }
    }
  }

  isInitialized = false;

  return isInitialized;
}

void
GraphicsRenderer_OpenGL::Finalize()
{
  hostPlatform.OpenGLDevice().Finalize();

  GraphicsRenderer_Interface::Finalize();
}

void
GraphicsRenderer_OpenGL::Render()
{
  gl_(glClearColor, 0.1f, 0.1f, 1.0f, 0.0f);
  gl_(glClear, GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  hostPlatform.OpenGLDevice().SwapBuffer();
}

NAMESPACE_END(Renderer::Graphics)

// Self
#include "GraphicsRenderer_OpenGL.hpp"

// Project headers - Common
#include "Common/Macros/Logging.hpp"
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

  auto isSuccess = hostPlatform.OpenGLDevice().Initialize(*window);
  if (isSuccess) {
    isSuccess = GraphicsRenderer_Interface::Initialize();
    if (isSuccess) {
      isSuccess = hostPlatform.OpenGLDevice().InitializeContext();
      if (isSuccess) {
        auto getProcAddress = hostPlatform.OpenGLDevice().GetProcAddress();
        auto version = InitializeOpenGL((GLADloadfunc)getProcAddress);
        if (0 != version) {
          auto vendor = glGetString(GL_VENDOR);
          auto renderer = glGetString(GL_RENDERER);
          auto version = glGetString(GL_VERSION);
          auto glslVersion = glGetString(GL_SHADING_LANGUAGE_VERSION);

          LogInfo("Graphics Renderer: OpenGL");
          LogInfo("  Vendor:          %s", vendor);
          LogInfo("  Renderer:        %s", renderer);
          LogInfo("  Version:         %s", version);
          LogInfo("  GLSL version:    %s", glslVersion);

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

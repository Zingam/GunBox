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
  Application::CoreApplication const& coreApplication,
  Application::Preferences& preferences,
  System::HostPlatform& hostPlatform)
  : GraphicsRenderer_Interface{ coreApplication, preferences, hostPlatform }
{}

GraphicsRenderer_OpenGL::~GraphicsRenderer_OpenGL() {}

////////////////////////////////////////////////////////////////////////////////
// Methods
////////////////////////////////////////////////////////////////////////////////

bool
GraphicsRenderer_OpenGL::Initialize()
{
  assert(!isInitialized && "Renderer is already initialized!");

  using namespace std::string_literals;

  ELogI("Initializing: OpenGL Renderer"s);

  auto& GPUDevice_OpenGL = hostPlatform.GPUDevice_OpenGL();
  auto isSuccess = GPUDevice_OpenGL.Initialize(*window);
  if (isSuccess) {
    isSuccess = GraphicsRenderer_Interface::Initialize();
    if (isSuccess) {
      isSuccess = GPUDevice_OpenGL.InitializeContext();
      if (isSuccess) {
        auto getProcAddress = GPUDevice_OpenGL.GetProcAddress();
        auto version = InitializeOpenGL((GLADloadfunc)getProcAddress);
        if (0 != version) {
          [[maybe_unused]] auto const vendor = glGetString(GL_VENDOR);
          [[maybe_unused]] auto const renderer = glGetString(GL_RENDERER);
          [[maybe_unused]] auto const version = glGetString(GL_VERSION);
          [[maybe_unused]] auto const glslVersion =
            glGetString(GL_SHADING_LANGUAGE_VERSION);

          ELogI("  Vendor:          "s, vendor);
          ELogI("  Renderer:        "s, renderer);
          ELogI("  Version:         "s, version);
          ELogI("  GLSL version:    "s, glslVersion);

          isInitialized = true;
        }
      }
    }
  }

  return isInitialized;
}

void
GraphicsRenderer_OpenGL::Finalize()
{
  hostPlatform.GPUDevice_OpenGL().Finalize();

  GraphicsRenderer_Interface::Finalize();
}

void
GraphicsRenderer_OpenGL::Render()
{
  gl_(glClearColor, 0.1f, 0.1f, 1.0f, 0.0f);
  gl_(glClear, GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  hostPlatform.GPUDevice_OpenGL().SwapBuffer();
}

NAMESPACE_END(Renderer::Graphics)

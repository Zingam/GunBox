#pragma once

// Project headers - BASE
#include "Common/Macros/Base.hpp"

// Project headers - Common
#include "Common/Macros/Logging.hpp"
// Project headers - Renderer
#include "Renderer/Graphics/OpenGL/OpenGL_Loader.hpp"

// C++ Standard Library
#include <type_traits>

#define OPENGL_CHECK_CALLS

#if defined(_DEBUG) && defined(OPENGL_CHECK_CALLS)
#  if !defined(OPENGL_CHECK_ERROR__)
#    define OPENGL_CHECK_ERROR__
#  else
#    error OPENGL_CHECK_ERROR__ is already defined
#  endif
#endif

NAMESPACE_BEGIN(Renderer::OpenGL)

////////////////////////////////////////////////////////////////////////////////
// Macros
////////////////////////////////////////////////////////////////////////////////

#if defined(OPENGL_CHECK_ERROR__)
/// <summary>
/// Performs error checking for OpenGL function calls in debug mode if the
/// preprocessor macro <c>OPENGL_CHECK_CALLS</c> is defined.
/// </summary>
#  define gl_(...)                                                             \
    Renderer::OpenGL::gl__(                                                    \
      "'gl_(" #__VA_ARGS__ ")'", __LINE__, __FILE__, __VA_ARGS__)
#else
#  define gl_(...) Renderer::OpenGL::gl__(__VA_ARGS__)
#endif

////////////////////////////////////////////////////////////////////////////////
// Functions
////////////////////////////////////////////////////////////////////////////////

#if defined(OPENGL_CHECK_ERROR__)
inline auto
PrintOpenGLError(char const* call, int line, char const* filename) -> void
{
  auto glErrorCode = glGetError();
  if (GL_NO_ERROR != glErrorCode) {
    char const* glErrorString = nullptr;
    switch (glErrorCode) {
      case GL_INVALID_OPERATION:
        glErrorString = "INVALID_OPERATION";
        break;
      case GL_INVALID_ENUM:
        glErrorString = "INVALID_ENUM";
        break;
      case GL_INVALID_VALUE:
        glErrorString = "INVALID_VALUE";
        break;
      case GL_OUT_OF_MEMORY:
        glErrorString = "OUT_OF_MEMORY";
        break;
      case GL_INVALID_FRAMEBUFFER_OPERATION:
        glErrorString = "INVALID_FRAMEBUFFER_OPERATION";
        break;
    }
    LogError("OpenGL error \'%s\' (code: 0x0%X)\n"
                 "       in call %s\n"
                 "           at line %d\n"
                 "           in file '%s'",
                 glErrorString,
                 glErrorCode,
                 call,
                 line,
                 filename);
  }
}
#endif

////////////////////////////////////////////////////////////////////////////////
// Template functions
////////////////////////////////////////////////////////////////////////////////

template<typename GL_Function, typename... Args>
inline auto
#if defined(OPENGL_CHECK_ERROR__)
gl__(char const* call,
     int line,
     char const* filename,
     GL_Function glFunction,
     Args... args)
#else
gl__(GL_Function glFunction, Args... args)
#endif
  -> std::enable_if_t<std::is_same_v<void, decltype(glFunction(args...))>,
                      decltype(glFunction(args...))>
{
  glFunction(std::forward<Args>(args)...);
#if defined(OPENGL_CHECK_ERROR__)
  PrintOpenGLError(call, line, filename);
#endif
}

template<typename GL_Function, typename... Args>
inline auto
#if defined(OPENGL_CHECK_ERROR__)
gl__(char const* call,
     int line,
     char const* filename,
     GL_Function glFunction,
     Args... args)
#else
gl__(GL_Function glFunction, Args... args)
#endif
  -> std::enable_if_t<!std::is_same_v<void, decltype(glFunction(args...))>,
                      decltype(glFunction(args...))>
{
  auto result = glFunction(std::forward<Args>(args)...);
#if defined(OPENGL_CHECK_ERROR__)
  PrintOpenGLError(call, line, filename);
#endif

  return result;
}

NAMESPACE_END(Renderer::OpenGL)

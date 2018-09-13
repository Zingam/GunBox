#pragma once

// Project headers - Common
#include "Common/Macros/Base.hpp"
#include "Common/Macros/SDL2_ErrorChecking.hpp"

// Third party libraries
#if defined(_WIN32) && !defined(APIENTRY)
// Defining APIENTRY manually will prevent 'glad' from including "Windows.h"
#  define APIENTRY __stdcall
#  define APIENTRY_DEFINED_BY_GLAD
#endif
#include <glad/glad.h>
#if defined(APIENTRY_DEFINED_BY_GLAD)
#  if !defined(_WINDOWS_)
#    undef APIENTRY
#  else
#    error Windows.h was included!
#  endif
#endif

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

NAMESPACE_START(Renderer::OpenGL)

#if defined(OPENGL_CHECK_ERROR__)
#  define GL__(...)                                                            \
    Renderer::OpenGL::gl__(                                                    \
      "'GL__(" #__VA_ARGS__##")'", __LINE__, __FILE__, __VA_ARGS__)
#else
#  define GL__(...) Renderer::OpenGL::gl__(__VA_ARGS__)
#endif

#if defined(OPENGL_CHECK_ERROR__)
auto
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
    SDL_LogError("OpenGL error \'%s\' (code: 0x0%X)\n"
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

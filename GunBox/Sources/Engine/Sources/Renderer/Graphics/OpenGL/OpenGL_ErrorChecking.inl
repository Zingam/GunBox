#pragma once

// C++ Standard Library
#include <utility>

NAMESPACE_BEGIN(Renderer::OpenGL)

////////////////////////////////////////////////////////////////////////////////
// Functions
////////////////////////////////////////////////////////////////////////////////

#if defined(OPENGL_CHECK_ERROR__)
auto
PrintOpenGLError(char const* call, int line, char const* filename) -> void;
#  if !defined(OPENGL_CHECK_CALLS_DO_NOT_PRINT_ERRORS_INLINE__)
// Include the implementation of 'PrintOpenGLError()'
#    include "OpenGL_ErrorChecking_FuncImpl.inl"
#  endif
#endif

template<typename GL_Function, typename... Args>
auto
#if defined(OPENGL_CHECK_ERROR__)
gl__(
  char const* call,
  int line,
  char const* filename,
  GL_Function glFunction,
  Args... args)
#else
gl__(GL_Function glFunction, Args... args)
#endif
  -> std::enable_if_t<
    std::is_same_v<void, decltype(glFunction(args...))>,
    decltype(glFunction(args...))>
{
  glFunction(std::forward<Args>(args)...);
#if defined(OPENGL_CHECK_ERROR__)
  PrintOpenGLError(call, line, filename);
#endif
}

template<typename GL_Function, typename... Args>
auto
#if defined(OPENGL_CHECK_ERROR__)
gl__(
  char const* call,
  int line,
  char const* filename,
  GL_Function glFunction,
  Args... args)
#else
gl__(GL_Function glFunction, Args... args)
#endif
  -> std::enable_if_t<
    !std::is_same_v<void, decltype(glFunction(args...))>,
    decltype(glFunction(args...))>
{
  auto result = glFunction(std::forward<Args>(args)...);
#if defined(OPENGL_CHECK_ERROR__)
  PrintOpenGLError(call, line, filename);
#endif

  return result;
}

NAMESPACE_END(Renderer::OpenGL)

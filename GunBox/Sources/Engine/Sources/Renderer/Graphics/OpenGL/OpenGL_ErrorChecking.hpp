#pragma once
////////////////////////////////////////////////////////////////////////////////
#include <Engine/Base>
////////////////////////////////////////////////////////////////////////////////

// Project headers - Common
#include "Common/Macros/Logging.hpp"
// Project headers - Renderer
#include "Renderer/Graphics/OpenGL/OpenGL_Loader.hpp"

// C++ Standard Library
#include <type_traits>

////////////////////////////////////////////////////////////////////////////////
// Defines
////////////////////////////////////////////////////////////////////////////////

// To enable error checking define:

#if !defined(OPENGL_CHECK_CALLS)
/// <summary>
///   Enables error checking of OpenGL calls.
/// </summary>
/// <remarks>
///   You need to pass this preprocessor definition on the command line.
/// </remarks>
#  define OPENGL_CHECK_CALLS

#  define OPENG_CHECK_CALLS_NOT_DEFINED
#endif

#if !defined(OPENGL_CHECK_CALLS_DO_NOT_PRINT_ERRORS_INLINE)
/// <summary>
///   The error printing function won't be inlined, which may lower the
///   performance.
/// </summary>
/// <remarks>
///   You need to pass this preprocessor definition on the command line.
/// </remarks>
#  define OPENGL_CHECK_CALLS_DO_NOT_PRINT_ERRORS_INLINE

#  defined(OPENGL_CHECK_CALLS_DO_NOT_PRINT_ERRORS_INLINE_NOT_DEFINED)
#endif

#if defined(OPENG_CHECK_CALLS_NOT_DEFINED)
#  undef OPENGL_CHECK_CALLS
#endif

#if defined(OPENGL_CHECK_CALLS_DO_NOT_PRINT_ERRORS_INLINE_NOT_DEFINED)
#  undef OPENGL_CHECK_CALLS_DO_NOT_PRINT_ERRORS_INLINE
#endif

#if defined(_DEBUG) && defined(OPENGL_CHECK_CALLS)
#  if !defined(OPENGL_CHECK_ERROR__)
#    define OPENGL_CHECK_ERROR__
#  else
#    error OPENGL_CHECK_ERROR__ is already defined
#  endif
#  if defined(OPENGL_CHECK_CALLS_DO_NOT_PRINT_ERRORS_INLINE)
#    if !defined(OPENGL_CHECK_CALLS_DO_NOT_PRINT_ERRORS_INLINE__)
#      define OPENGL_CHECK_CALLS_DO_NOT_PRINT_ERRORS_INLINE__
#    else
#      error OPENGL_CHECK_CALLS_DO_NOT_PRINT_ERRORS_INLINE__ is already defined
#    endif
#  endif
#endif

NAMESPACE_BEGIN(Renderer::OpenGL)

////////////////////////////////////////////////////////////////////////////////
// Macros
////////////////////////////////////////////////////////////////////////////////

#if defined(OPENGL_CHECK_ERROR__)
/// <summary>
///   Performs error checking for OpenGL function calls in debug mode if the
///   preprocessor macro <c>OPENGL_CHECK_CALLS</c> is defined.
/// </summary>
#  define gl_(...)                                                             \
    Renderer::OpenGL::gl__(                                                    \
      "'gl_(" #__VA_ARGS__ ")'", __LINE__, __FILE__, __VA_ARGS__)
#else
#  define gl_(...) Renderer::OpenGL::gl__(__VA_ARGS__)
#endif

////////////////////////////////////////////////////////////////////////////////
// Template functions
////////////////////////////////////////////////////////////////////////////////

#if !defined(OPENGL_CHECK_ERROR__)
template<typename GL_Function, typename... Args>
auto
gl__(GL_Function glFunction, Args... args) -> std::enable_if_t<
  std::is_same_v<void, decltype(glFunction(args...))>,
  decltype(glFunction(args...))>;
#endif

#if !defined(OPENGL_CHECK_ERROR__)
template<typename GL_Function, typename... Args>
auto
gl__(GL_Function glFunction, Args... args) -> std::enable_if_t<
  !std::is_same_v<void, decltype(glFunction(args...))>,
  decltype(glFunction(args...))>;
#endif

NAMESPACE_END(Renderer::OpenGL)

////////////////////////////////////////////////////////////////////////////////
// Inline method implementations
////////////////////////////////////////////////////////////////////////////////

#include "OpenGL_ErrorChecking.inl"

////////////////////////////////////////////////////////////////////////////////

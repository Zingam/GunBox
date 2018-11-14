// Self
#include "OpenGL_ErrorChecking.hpp"

NAMESPACE_BEGIN(Renderer::OpenGL)

#if defined(OPENGL_CHECK_CALLS_DO_NOT_PRINT_ERRORS_INLINE__)
// Include the implementation of 'PrintOpenGLError()'
#  include "OpenGL_ErrorChecking_FuncImpl.inl"
#endif

NAMESPACE_END(Renderer::OpenGL)

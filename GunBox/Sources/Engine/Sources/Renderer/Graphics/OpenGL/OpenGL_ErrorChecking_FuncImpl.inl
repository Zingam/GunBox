#pragma once

////////////////////////////////////////////////////////////////////////////////
// Function implementations
////////////////////////////////////////////////////////////////////////////////

#if defined(OPENGL_CHECK_ERROR__)

#  if !defined(OPENGL_CHECK_CALLS_DO_NOT_PRINT_ERRORS_INLINE__)
#    define INLINE_SPECIFIER inline
#  else
#    define INLINE_SPECIFIER
#  endif

INLINE_SPECIFIER auto
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
    
    reLogE(
      "OpenGL error \'", glErrorString,"\' (code: ", glErrorCode,")\n"
      "       in call ", call, "\n"
      "           at line ", line, "\n"
      "           in file '", filename, "'");
  }
}

#endif

#pragma once

// Third party libraries
#if defined(__ANDROID__)
#  include <glad/gles2.h>
#  define InitializeOpenGL gladLoadGLES2
#else
#  include <glad/gl.h>
#  define InitializeOpenGL gladLoadGL
#endif

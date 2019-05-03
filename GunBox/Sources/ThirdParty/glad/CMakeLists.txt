################################################################################
cmake_minimum_required (VERSION 3.10)
################################################################################

project (glad)

add_library (${PROJECT_NAME} STATIC
  $<$<NOT:$<PLATFORM_ID:Android>>:include/glad/gl.h>
  $<$<PLATFORM_ID:Android>:include/glad/gles2.h>
  "include/glad/vulkan.h"
  "include/KHR/khrplatform.h"
  "include/vk_platform.h"
  $<$<NOT:$<PLATFORM_ID:Android>>:src/gl.c>
  $<$<PLATFORM_ID:Android>:src/gles2.c>
  "src/vulkan.c"
)
set_property (TARGET ${PROJECT_NAME}
  PROPERTY
    POSITION_INDEPENDENT_CODE YES
)

target_include_directories (${PROJECT_NAME}
  PUBLIC
    "include/"
)

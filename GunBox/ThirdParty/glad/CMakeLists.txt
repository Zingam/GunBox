################################################################################
cmake_minimum_required (VERSION 3.11)
################################################################################

project(glad)

add_library (${PROJECT_NAME} STATIC
  "include/glad/glad.h"
  "include/KHR/khrplatform.h"
  "src/glad.c"
)

target_include_directories (${PROJECT_NAME}
  PUBLIC
    "include/"
)

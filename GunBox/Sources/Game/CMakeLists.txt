################################################################################
cmake_minimum_required (VERSION 3.10)
################################################################################

################################################################################
# Project name
################################################################################
project ("GunBox_Game")
################################################################################

include (Game_SourceFiles.cmake)
if (ANDROID)
  add_library (${PROJECT_NAME} SHARED
    # Source files
    ${Game_SourceFiles}
  )
else ()
  add_executable (${PROJECT_NAME}
    # Platform resources (Windows)
    $<$<PLATFORM_ID:Windows>:Resources/Windows/DpiAwareness.manifest>
    $<$<AND:$<PLATFORM_ID:Windows>,$<CXX_COMPILER_ID:MSVC>>:Resources/Windows/GunBox.rc>
    # Source files
    ${Game_SourceFiles}
  )
endif ()

target_include_directories (${PROJECT_NAME}
  PRIVATE
    "Sources"
)

if (WIN32)
  set_property (TARGET ${PROJECT_NAME}
    PROPERTY
      WIN32_EXECUTABLE FALSE
  )
endif ()

target_link_libraries (${PROJECT_NAME}
  GunBox_Engine
  # Prevent SDL_main from being stripped when linked in a static library
  $<$<PLATFORM_ID:Android>:-Wl,--whole-archive>
  GunBox_Engine_main
  $<$<PLATFORM_ID:Android>:-Wl,--no-whole-archive>
)

################################################################################

################################################################################
# Installation
################################################################################

if (NOT ANDROID)
  # Set installation path
  set (InstallationPath ${CMAKE_INSTALL_PREFIX})

  # Install targets
  install (
    TARGETS
      ${PROJECT_NAME}
    RUNTIME DESTINATION
      ${InstallationPath}
  )
endif ()

################################################################################

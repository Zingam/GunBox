################################################################################
cmake_minimum_required (VERSION 3.11)
################################################################################
message ("CMake version: " ${CMAKE_VERSION})
################################################################################

################################################################################
# Project properties
################################################################################
# find_package () modules
list (APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/__cmake/Modules")
################################################################################

################################################################################
# Project name
################################################################################
project ("GunBox")
################################################################################

################################################################################
# Targets
################################################################################

add_subdirectory ("ThirdParty")

add_executable (${PROJECT_NAME}
  # Platform resources (Windows)
  $<$<PLATFORM_ID:Windows>:Resources/Windows/DpiAwareness.manifest>
  $<$<PLATFORM_ID:Windows>:Resources/Windows/GunBox.rc>
  # Source files
  "Sources/Common/Macros/Base.cpp"
  "Sources/Common/Macros/Base.hpp"
  "Sources/System/Geometry.cpp"
  "Sources/System/Geometry.hpp"
  "Sources/System/Monitor.cpp"
  "Sources/System/Monitor.hpp"
  "Sources/System/Preferences.cpp"
  "Sources/System/Preferences.hpp"
  "Sources/System/RendererBase.cpp"
  "Sources/System/RendererBase.hpp"
  "Sources/System/Window.cpp"
  "Sources/System/Window.hpp"
  "Sources/main.cpp"
)

# Enable C++17 standard complience
set_property (TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)
target_compile_options (${PROJECT_NAME}
  PRIVATE
    # Enable the standard compliant C preprocessor
    $<$<CXX_COMPILER_ID:MSVC>:/experimental:preprocessor>
    # Enable Just My Code debugging
    $<$<CXX_COMPILER_ID:MSVC>:/JMC>
    # Enable C++ Standard compliance
    $<$<CXX_COMPILER_ID:MSVC>:/permissive->
)
target_include_directories (${PROJECT_NAME}
  PRIVATE
    "Sources"
)

# Find external libraries
find_package (SDL2 REQUIRED)
if (NOT SDL2_FOUND)
  message ("ERROR: SDL2 SDK was not found in the search path!")
endif()
list (APPEND SharedLibraries ${SDL2_SHARED_LIBRARY})

find_package (OpenGL REQUIRED)
if (NOT OPENGL_FOUND)
  message ("ERROR: OpenGL was not found in the search path!")
endif()

target_link_libraries (${PROJECT_NAME}
  REngine::SDL2
  OpenGL::GL
  glad
)

################################################################################

################################################################################
# Installation
################################################################################

message ("Shared libraries to install:")
foreach (SharedLibrary ${SharedLibraries})
  message ("    ${SharedLibrary}")
endforeach ()

# Set installation path
set (InstallationPath ${CMAKE_INSTALL_PREFIX})

# Install targets
install (
  TARGETS
    ${PROJECT_NAME}
  RUNTIME DESTINATION
    ${InstallationPath}
)

# Install required files
install (
  FILES
    ${SharedLibraries}
  DESTINATION
    ${InstallationPath}
)

################################################################################

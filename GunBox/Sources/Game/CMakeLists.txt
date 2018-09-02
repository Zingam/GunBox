################################################################################
cmake_minimum_required (VERSION 3.11)
################################################################################

################################################################################
# Project name
################################################################################
project ("GunBox")
################################################################################

add_executable (${PROJECT_NAME}
  # Platform resources (Windows)
  $<$<PLATFORM_ID:Windows>:Resources/Windows/DpiAwareness.manifest>
  $<$<PLATFORM_ID:Windows>:Resources/Windows/GunBox.rc>
  # Source files
  "Sources/Game.cpp"
  "Sources/Game.hpp"
  "Sources/GameFactory.cpp"
)

if (WIN32)
  set_property (TARGET ${PROJECT_NAME} PROPERTY WIN32_EXECUTABLE TRUE)
endif ()

target_link_libraries (${PROJECT_NAME}
  GunBox_Engine_main
)

################################################################################

################################################################################
# Installation
################################################################################

# Set installation path
set (InstallationPath ${CMAKE_INSTALL_PREFIX})

# Install targets
install (
  TARGETS
    ${PROJECT_NAME}
  RUNTIME DESTINATION
    ${InstallationPath}
)

################################################################################

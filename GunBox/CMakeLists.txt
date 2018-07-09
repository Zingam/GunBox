################################################################################
cmake_minimum_required (VERSION 3.10)
################################################################################

################################################################################
# Modules: find_package () modules
################################################################################
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

find_package (SDL2 REQUIRED)
if (NOT SDL2_FOUND)
  message ("ERROR: SDL2 SDK was not found in the search path!")
endif()
list (APPEND SharedLibraries ${SDL2_SHARED_LIBRARY})

add_executable (${PROJECT_NAME}
  "Sources/main.cpp"
)
target_link_libraries (${PROJECT_NAME}
  REngine::SDL2
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
get_filename_component (InstallationPath
  "${InstallationFolder}" ABSOLUTE
)

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

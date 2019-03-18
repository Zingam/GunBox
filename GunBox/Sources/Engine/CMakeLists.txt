################################################################################
cmake_minimum_required (VERSION 3.10)
################################################################################

################################################################################
# Project name
################################################################################

project ("GunBox_Engine")

################################################################################

################################################################################
# Project settings
################################################################################

# Library options:

# Build the targets as STATIC libraries by default
option (option_EngineLibraryAs_SHARED
  "Build the library as a shared?"
  NO
)

set (.EngineLibraryType "STATIC")
if (option_EngineLibraryAs_SHARED)
  set (.EngineLibraryType "SHARED")
endif ()

# Graphics API options:

# Specifies if error checking should be performed on graphics API calls
option (option_CheckGraphicsApiCalls
  "Perform error checking on graphics API calls?"
  NO
)

# Specifies if error printing function should be inlined for better performance
option (option_CheckGraphicsApiCalls_DoNotPrintErrorsInline
  "Disallow inlining of the error printing function?"
  YES
)

################################################################################
# Third party libraries
################################################################################

add_subdirectory (
  "${CMAKE_SOURCE_DIR}/Sources/ThirdParty"
  "${PROJECT_BINARY_DIR}/../ThirdParty"
)

################################################################################

################################################################################
# Target: ${PROJECT_NAME}_Base
################################################################################

include ("Engine_Base.cmake")

################################################################################

################################################################################
# Target: ${PROJECT_NAME}
################################################################################

# Engine library target
include ("Engine_SourceFiles.cmake")
add_library (${PROJECT_NAME} ${.EngineLibraryType}
  # Source files
  ${.Engine_SourceFiles}
)

if (WIN32 AND option_EngineLibraryAs_SHARED)
  set_property (TARGET ${PROJECT_NAME}
    PROPERTY
      WINDOWS_EXPORT_ALL_SYMBOLS TRUE
  )
endif ()

if (option_CheckGraphicsApiCalls)
  target_compile_definitions (${PROJECT_NAME}
    PUBLIC
      "OPENGL_CHECK_CALLS"
  )
endif ()

if (option_CheckGraphicsApiCalls_DoNotPrintErrorsInline)
  target_compile_definitions (${PROJECT_NAME}
    PUBLIC
      "OPENGL_CHECK_CALLS_DO_NOT_PRINT_ERRORS_INLINE"
  )
endif ()

target_include_directories (${PROJECT_NAME}
  PUBLIC
    "Sources"
)

# External libraries search paths and find_package variables
if (ANDROID)
  set (__VariantSubdir "${CMAKE_BUILD_TYPE}/${ANDROID_ABI}")

  # FreeType2 find_package configuration
  set (.ANDROID_AddLibraryAs_SHARED_FreeType2
    ${.UseSharedLibrary_FreeType2}
  )
  set (.ANDROID_LibraryArtifactsPath_FreeType2
    "${.LibraryArtifactsPath_FreeType2}/${__VariantSubdir}"
  )
  set (.ANDROID_SourcePath_FreeType2
    "${.ExternalLibrariesRootDir}/FreeType2/FreeType2"
  )
  # SDL2 find_package configuration
  set (.ANDROID_AddLibraryAs_SHARED_SDL2
    ${.UseSharedLibrary_SDL2}
  )
  set (.ANDROID_LibraryArtifactsPath_SDL2
    "${.LibraryArtifactsPath_SDL2}/${__VariantSubdir}"
  )
  set (.ANDROID_SourcePath_SDL2
    "${.ExternalLibrariesRootDir}/SDL2/SDL2"
  )

  # Keep variables local
  unset (__VariantSubdir)
endif ()

# Find the required packages
if (WIN32)
  set (.UsePostfixedDebugLibrary_FreeType2 NO)
endif ()
find_package(FreeType2 REQUIRED)
list (APPEND .SharedLibraries "${FreeType2_SHARED_LIBRARY}")

find_package (SDL2 REQUIRED)
list (APPEND .SharedLibraries "${SDL2_SHARED_LIBRARY}")

if (NOT ANDROID)
  find_package (OpenGL REQUIRED
    COMPONENTS
      OpenGL 
  )
endif ()

# Link the packages
target_link_libraries (${PROJECT_NAME}
  PUBLIC
    ${PROJECT_NAME}_Base
    glad
    REngine::FreeType2
    REngine::SDL2
)
if (UNIX AND option_EngineLibraryAs_SHARED)
  target_link_libraries (${PROJECT_NAME}
    PRIVATE
      ${CMAKE_DL_LIBS}
  )
endif ()
if (ANDROID)
  target_link_libraries (${PROJECT_NAME}
    PUBLIC
      # Links the target library to the libraries included in the NDK.
      "android"
      "GLESv3"
      "log"
  )
else ()
  target_link_libraries (${PROJECT_NAME}
    INTERFACE
      OpenGL::GL
  )
endif ()

################################################################################
# Target: ${PROJECT_NAME}_main
################################################################################

# Main library target
add_library (${PROJECT_NAME}_main STATIC
  "Sources/main.cpp"
)
target_compile_definitions (${PROJECT_NAME}_main
  PRIVATE
    $<$<PLATFORM_ID:Windows>:PREFER_DISCRETE_GPU>
)
target_link_libraries (${PROJECT_NAME}_main
  PRIVATE
    ${PROJECT_NAME}
)

################################################################################

################################################################################
# Installation
################################################################################

if (WIN32 OR UNIX)
  set (__AreTargetsInstallable YES)
elseif (ANDROID)
  set (__AreTargetsInstallable NO)
else ()
  message (FATAL_ERROR "Unsupported platform ${}")
endif ()

if (__AreTargetsInstallable)
  message ("Shared libraries to install:")
  foreach (__SharedLibrary ${.SharedLibraries})
    message ("    ${__SharedLibrary}")
  endforeach ()

  # Set installation path
  set (InstallationPath ${CMAKE_INSTALL_PREFIX})

  if (option_EngineLibraryAs_SHARED)
    # Install targets
    install (
      TARGETS
        ${PROJECT_NAME}
      RUNTIME DESTINATION
        "${InstallationPath}"
      LIBRARY DESTINATION
        "${InstallationPath}"
    )
  endif ()

  # Install required files
  install (
    FILES
      ${.SharedLibraries}
    DESTINATION
      "${InstallationPath}"
  )
endif ()

unset (__AreTargetsInstallable)

################################################################################

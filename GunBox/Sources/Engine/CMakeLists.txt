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

# -- Library options:

# Build the targets as STATIC libraries by default
option (option_EngineLibraryAs_SHARED
  "Build the library as a shared?"
  NO
)

set (.EngineLibraryType "STATIC")
if (option_EngineLibraryAs_SHARED)
  set (.EngineLibraryType "SHARED")
endif ()

# -- Logging options:

# Specifies if all messages should be logged
option (option_EnableLoggingLevel_Verbose
  "Log all messages?"
  NO
)

# Specifies if "INFO" prefixed informational messages should be logged
option (option_EnableLoggingLevel_Info
  "Log info messages?"
  NO
)

# Specifies if non-prefixed informational messages should be logged
option (option_EnableLoggingLevel_None
  "Log non-prefixed info messages?"
  NO
)

# -- Graphics API options:

# Specifies if error checking should be performed on graphics API calls
option (option_Graphics_CheckGraphicsApiCalls
  "Perform error checking on graphics API calls?"
  NO
)

# Specifies if error printing function should be inlined for better performance
option (option_Graphics_CheckGraphicsApiCalls_DoNotPrintErrorsInline
  "Disallow inlining of the error printing function?"
  YES
)

# Specifies if an integrated GPU should be used for OpenGL rendering
option (option_Graphics_OpenGL_PreferIntegratedGPU
  "Prefer an integrated GPU for OpenGL rendering if available?"
  NO
)


################################################################################
# Third party libraries
################################################################################

# When specifying an out-of-tree source a binary directory must be explicitly
# specified.
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

# Source files
include ("Engine_SourceFiles.cmake")

# Engine library target
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

# Compile definitions
if (option_EnableLoggingLevel_Verbose)
  target_compile_definitions (${PROJECT_NAME}
    PUBLIC
      "LOGGING_LEVEL_VERBOSE"
  )
endif ()
if (option_EnableLoggingLevel_Info)
  target_compile_definitions (${PROJECT_NAME}
    PUBLIC
      "LOGGING_LEVEL_INFO"
  )
endif ()
if (option_EnableLoggingLevel_None)
  target_compile_definitions (${PROJECT_NAME}
    PUBLIC
      "LOGGING_LEVEL_NONE"
  )
endif ()
if (option_Graphics_CheckGraphicsApiCalls)
  target_compile_definitions (${PROJECT_NAME}
    PUBLIC
      "OPENGL_CHECK_CALLS"
  )
endif ()
if (option_Graphics_CheckGraphicsApiCalls_DoNotPrintErrorsInline)
  target_compile_definitions (${PROJECT_NAME}
    PUBLIC
      "OPENGL_CHECK_CALLS_DO_NOT_PRINT_ERRORS_INLINE"
  )
endif ()
if (option_Graphics_OpenGL_PreferIntegratedGPU)
  target_compile_definitions (${PROJECT_NAME}
    PUBLIC
      "PREFER_INTEGRATED_GPU"
  )
endif ()

# Include directories
target_include_directories (${PROJECT_NAME}
  PUBLIC
    "Sources"
)

# External libraries search paths and find_package variables
if (ANDROID)
  include("${.ExternalLibrariesRootDir}/__cmake/ExternalLibraries.cmake")

  set (__VariantSubdir "${CMAKE_BUILD_TYPE}/${ANDROID_ABI}")

  # Set find_package configuration variables:
  #   .ANDROID_AddLibraryAs_SHARED_FreeType2
  #   .ANDROID_LibraryArtifactsPath_FreeType2
  #   .ANDROID_SourcePath_FreeType2
  SetFindPackageConfiguration ("FreeType2")
  #   .ANDROID_AddLibraryAs_SHARED_SDL2
  #   .ANDROID_LibraryArtifactsPath_SDL2
  #   .ANDROID_SourcePath_SDL2
  SetFindPackageConfiguration ("SDL2")

  string (APPEND __AndroidConfigurationMessage
    "Android find_package configuration variables:\n")
  string (APPEND __ErrorMessage
    "  - .ANDROID_AddLibraryAs_SHARED_FreeType2:  ${.ANDROID_AddLibraryAs_SHARED_FreeType2}\n")
  string (APPEND __ErrorMessage
    "  - .ANDROID_LibraryArtifactsPath_FreeType2: ${.ANDROID_LibraryArtifactsPath_FreeType2}\n")
  string (APPEND __ErrorMessage
    "  - .ANDROID_SourcePath_FreeType2:           ${.ANDROID_SourcePath_FreeType2}\n")
  string (APPEND __ErrorMessage
    "  - .ANDROID_AddLibraryAs_SHARED_SDL2:       ${.ANDROID_AddLibraryAs_SHARED_SDL2}\n")
  string (APPEND __ErrorMessage
    "  - .ANDROID_LibraryArtifactsPath_SDL2:      ${.ANDROID_LibraryArtifactsPath_SDL2}\n")
  string (APPEND __ErrorMessage
    "  .ANDROID_SourcePath_SDL2:                  ${.ANDROID_SourcePath_SDL2}\n")
  message ("${__AndroidConfigurationMessage}")
  unset (__AndroidConfigurationMessage)

  if (FALSE)
  set (.ANDROID_AddLibraryAs_SHARED_FreeType2
    ${.UseSharedLibrary_FreeType2}
  )
  set (.ANDROID_LibraryArtifactsPath_FreeType2
    "${.LibraryArtifactsPath_FreeType2}/${__VariantSubdir}"
  )
  set (__FreeType2_RootDir "${.ExternalLibrariesRootDir}/FreeType2")
  GetLibraryDirectory(__LibraryDirectory "${__FreeType2_RootDir}" "FreeType2")
  set (.ANDROID_SourcePath_FreeType2
    "${__FreeType2_RootDir}/${__LibraryDirectory}"
  )
  unset (__FreeType2_RootDir)

  # SDL2 find_package configuration
  set (.ANDROID_AddLibraryAs_SHARED_SDL2
    ${.UseSharedLibrary_SDL2}
  )
  set (.ANDROID_LibraryArtifactsPath_SDL2
    "${.LibraryArtifactsPath_SDL2}/${__VariantSubdir}"
  )
  set (__SDL2_RootDir "${.ExternalLibrariesRootDir}/SDL2")
  GetLibraryDirectory(__LibraryDirectory "${__SDL2_RootDir}" "SDL2")
  set (.ANDROID_SourcePath_SDL2
    "${__SDL2_RootDir}/${__LibraryDirectory}"
  )
  unset (__SDL2_RootDir)
  endif ()
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
  # Source files
  ${.main_SourceFiles}
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
  message (FATAL_ERROR "Unsupported target OS: ${CMAKE_SYSTEM_NAME}")
endif ()

if (__AreTargetsInstallable)
  message ("Shared third party libraries to install:")
  foreach (__SharedLibrary ${.SharedLibraries})
    message ("    ${__SharedLibrary}")
  endforeach ()

  # Set installation path
  set (__InstallationPath ${CMAKE_INSTALL_PREFIX})
  if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    string (APPEND __InstallationPath "/lib")
  endif ()

  if (option_EngineLibraryAs_SHARED)
    # Install targets
    if (WIN32)
      install (
        TARGETS
          ${PROJECT_NAME}
        RUNTIME DESTINATION
          ${__InstallationPath}
      )
    elseif (UNIX)
      install (
        TARGETS
          ${PROJECT_NAME}
        LIBRARY DESTINATION
          ${__InstallationPath}
      )
    endif ()
  endif ()

  # Install required files
  install (
    FILES
      ${.SharedLibraries}
    DESTINATION
      ${__InstallationPath}
  )
endif ()

unset (__AreTargetsInstallable)

################################################################################

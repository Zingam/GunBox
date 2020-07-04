################################################################################
# Module: FindFreeType2
################################################################################
# Common input variables
#    .UsePostfixedDebugLibrary_FreeType2     - such as "libfreetyped.so",
#                                              linking against the postfixed
#                                              postfixed version is default
# Android input variables
#  Library type:
#    .ANDROID_AddLibraryAs_SHARED_FreeType2  - "YES" will search for a shared
#                                              library
#  The following search paths need to be set for Android:
#    .ANDROID_SourcePath_FreeType2           - Location of the SDL2 sources
#    .ANDROID_LibraryArtifactsPath_FreeType2 - Location of the SDL2 binaries
#
################################################################################
# Defines:
#   * Imported targets:
#       REngine::FreeType2
#   * Variables:
#       FreeType2_FOUND          - If false, do not try to link to FreeType2
#       FreeType2_LIBRARY        - The name of the library to link against
#       FreeType2_LIBRARIES      -
#       FreeType2_INCLUDE_DIR    - The location of FreeType2 header files
#       FreeType2_SHARED_LIBRARY - The name of the shared library (if available)
#       FreeType2_VERSION_STRING - String containing the version of FreeType2
################################################################################
# Search paths:
#   * Environment variables (only one must be defined):
#       VCPKG_ROOT
#       __EXTERNAL_LIBS
#   * System paths
################################################################################

################################################################################
# Function definitions
################################################################################

function (AddImportedLibrary
  .ImportedTargetName
  .LibraryType
  .LibraryName
  .LibrarySearchPath
)
  list (APPEND options "SHARED" "STATIC")
  if (NOT ${.LibraryType} IN_LIST options)
    message (FATAL_ERROR
      "Parameter SHARED or STATIC is required, found: ${.LibraryType}"
    )
  endif ()

  add_library (${.ImportedTargetName} ${.LibraryType} IMPORTED)
  file (TO_CMAKE_PATH
    ${.LibrarySearchPath}/${.LibraryName}
    __ImportedLibraryFile
  )
  set_property (TARGET ${.ImportedTargetName}
    PROPERTY
      IMPORTED_LOCATION
        "${__ImportedLibraryFile}"
  )
endfunction()

################################################################################
# Main module entry point
################################################################################

if (DEFINED ENV{VCPKG_ROOT}
  AND NOT ANDROID
)
  if (DEFINED ENV{__EXTERNAL_LIBS})
    message (FATAL_ERROR
      "Both environment variables are defined: VCPKG_ROOT and __EXTERNAL_LIBS"
      "Please, undefine one of them."
    )
  endif ()

  set (.InstalledLibraryPathHints "$ENV{VCPKG_ROOT}/installed")

  # Target CPU architecture
  if (CMAKE_SYSTEM_PROCESSOR MATCHES "^arm|^aarch64")
    string (APPEND .InstalledLibraryPathHints "/arm")
  elseif ((CMAKE_SYSTEM_PROCESSOR MATCHES "^AMD64")
    OR (CMAKE_SYSTEM_PROCESSOR MATCHES "^x86_64")
  )
    string (APPEND .InstalledLibraryPathHints "/x")
  else ()
    message (FATAL_ERROR
      "Unknown CPU architecture: ${CMAKE_SYSTEM_PROCESSOR}"
    )
  endif ()
  if (CMAKE_SIZEOF_VOID_P EQUAL 8)
    # If compile target is 64bit
    string (APPEND .InstalledLibraryPathHints "64")
  else ()
    # If compile target is 32bit
    string (APPEND .InstalledLibraryPathHints "86")
  endif ()
  # Target OS
  if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    string (APPEND .InstalledLibraryPathHints "-linux")
  elseif (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    string (APPEND .InstalledLibraryPathHints "-windows")
  else ()
    message (FATAL_ERROR
      "Unsupported target OS: ${CMAKE_SYSTEM_NAME}"
    )
  endif ()

  set (.InstalledLibraryHeaderPathHints ${.InstalledLibraryPathHints})

  if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    string (APPEND .InstalledLibraryPathHints "/debug")
    set (.UsePostfixedDebugLibrary_FreeType2 YES)
  endif ()
endif ()

################################################################################
# Header files
################################################################################

if (ANDROID)
  if (NOT DEFINED .ANDROID_SourcePath_FreeType2)
    message (FATAL_ERROR ".ANDROID_SourcePath_FreeType2 is not set")
  endif ()
  if ("${.ANDROID_SourcePath_FreeType2}" STREQUAL "")
    message (FATAL_ERROR ".ANDROID_SourcePath_FreeType2 is empty")
  endif ()

  file (TO_CMAKE_PATH
    ${.ANDROID_SourcePath_FreeType2}
    __LibrarySourcePath
  )
  list (APPEND .FreeType2_find_path_Hints
    ${__LibrarySourcePath}
  )
  unset (__LibrarySourcePath)

  # NO_CMAKE_FIND_ROOT_PATH tells CMake not to use the CMAKE_FIND_ROOT_PATH
  # variable, which is a list of root paths to search on the filesystem. Instead
  # CMake should search in the provided alternative paths. This is required when
  # cross-compiling for Android.
  set (NO_CMAKE_FIND_ROOT_PATH "NO_CMAKE_FIND_ROOT_PATH")
else ()
  list (APPEND .FreeType2_find_path_Hints
    ${FreeType2_DIR}
    "$ENV{__EXTERNAL_LIBS}/FreeType2"
    ${.InstalledLibraryHeaderPathHints}
  )
endif ()

find_path (FreeType2_INCLUDE_DIR
  NAMES
    "ft2build.h"
  HINTS
    ${.FreeType2_find_path_Hints}
  PATH_SUFFIXES
    "/include/freetype2"
    "/include"
  ${NO_CMAKE_FIND_ROOT_PATH}
)

unset (.FreeType2_find_path_Hints)

################################################################################
# Library files
################################################################################

if (NOT DEFINED .UsePostfixedDebugLibrary_FreeType2)
  # Link against the postfixed library by default
  if (ANDROID
      OR (CMAKE_SYSTEM_NAME STREQUAL "Windows")
  )
    set (.UsePostfixedDebugLibrary_FreeType2 YES)
  else ()
    set (.UsePostfixedDebugLibrary_FreeType2 NO)
  endif ()
endif ()
if (NOT CMAKE_BUILD_TYPE STREQUAL "Debug"
  # If linking against a debug version but without the postfix "d"
  OR NOT .UsePostfixedDebugLibrary_FreeType2
)
  set (.BaseLibraryName "freetype")
else ()
  set (.BaseLibraryName "freetyped")
  unset (.UsePostfixedDebugLibrary_FreeType2)
endif ()

if (ANDROID)
  if (NOT .ANDROID_LibraryArtifactsPath_FreeType2)
    message (FATAL_ERROR ".ANDROID_LibraryArtifactsPath_FreeType2 is not set")
  endif ()
  list (APPEND .FreeType2_LibraryFileHints
    ${.ANDROID_LibraryArtifactsPath_FreeType2}
  )
else ()
  list (APPEND .FreeType2_LibraryFileHints
    $ENV{FREETYPE_DIR}
    ${FreeType2_DIR}
    "$ENV{__EXTERNAL_LIBS}/FreeType2"
    ${.InstalledLibraryPathHints}
  )
endif ()

if (ANDROID)
  string (PREPEND .BaseLibraryName "lib")

  if (.ANDROID_AddLibraryAs_SHARED_FreeType2)
    string (APPEND .BaseLibraryName ".so")
    AddImportedLibrary (FreeType2 SHARED
      ${.BaseLibraryName}
      ${.ANDROID_LibraryArtifactsPath_FreeType2}
    )
  else ()
    string (APPEND .BaseLibraryName ".a")
    AddImportedLibrary (FreeType2 STATIC
      ${__BaseLibraryName}
      ${.ANDROID_LibraryArtifactsPath_FreeType2}
    )
  endif ()
else ()
    # Set search path sufficies
  if (CMAKE_SIZEOF_VOID_P EQUAL 8)
    # If compile target is 64bit
    set (.MSVC_binPathSuffix "bin/x64")
    set (.MSVC_libPathSuffix "lib/x64")
  else ()
    # If compile target is 32bit
    set (.MSVC_binPathSuffix "bin/x86")
    set (.MSVC_libPathSuffix "lib/x86")
  endif ()

  find_library (FreeType2_LIBRARY
    NAMES
      ${.BaseLibraryName}
    HINTS
      ${.FreeType2_LibraryFileHints}
    PATH_SUFFIXES
      "lib"
      ${.MSVC_libPathSuffix}
  )
endif ()

if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
  set (__LibraryFile "${.BaseLibraryName}.dll")

  find_file (FreeType2_SHARED_LIBRARY
    NAMES
      "${__LibraryFile}"
    HINTS
      "$ENV{__EXTERNAL_LIBS}/FreeType2"
      ${.InstalledLibraryPathHints}
    PATH_SUFFIXES
      "bin"
      ${.MSVC_binPathSuffix}
      ${.MSVC_libPathSuffix}
    # Look only in the specified HINTS
    NO_DEFAULT_PATH
  )

  if (NOT FreeType2_SHARED_LIBRARY)
    message (FATAL_ERROR "Unable to find library file: \"${__LibraryFile}\"")
  endif ()
   # Hide internal implementation details from user
  set_property (CACHE FreeType2_SHARED_LIBRARY PROPERTY TYPE INTERNAL)

  unset (__LibraryFile)
endif ()

unset (.MSVC_libPathSuffix)
unset (.BaseLibraryName)
unset (.InstalledLibraryPathHints)

################################################################################
# find_package arguments
################################################################################

list (APPEND .PackageVariables
  FreeType2_INCLUDE_DIR
)
if (NOT ANDROID)
  list (APPEND .PackageVariables
    ${.PackageVariables}
    FreeType2_LIBRARY
  )
  if (FreeType2_SHARED_LIBRARY)
    list (APPEND .PackageVariables
      FreeType2_SHARED_LIBRARY
    )
  endif ()
endif ()

include (FindPackageHandleStandardArgs)
find_package_handle_standard_args (FreeType2
  REQUIRED_VARS
    ${.PackageVariables}
)

mark_as_advanced (${.PackageVariables})

unset (.PackageVariables)

################################################################################
# Imported target
################################################################################

if (FreeType2_FOUND AND NOT TARGET REngine::FreeType2)
  if (ANDROID)
    add_library (REngine::FreeType2 INTERFACE IMPORTED)
    set_property (TARGET REngine::FreeType2
      PROPERTY
        INTERFACE_INCLUDE_DIRECTORIES
          "${FreeType2_INCLUDE_DIR}"
    )
    target_link_libraries(REngine::FreeType2
      INTERFACE
        FreeType2
    )
  else ()
    add_library (REngine::FreeType2 UNKNOWN IMPORTED)
    set_target_properties (REngine::FreeType2
      PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES
          "${FreeType2_INCLUDE_DIR}"
        IMPORTED_LOCATION
          "${FreeType2_LIBRARY}"
    )
  endif ()
endif ()

################################################################################

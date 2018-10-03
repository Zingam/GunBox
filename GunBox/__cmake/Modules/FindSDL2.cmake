################################################################################
# Module: FindSDL2
################################################################################
# Android - input variables
#  Library type:
#    .ANDROID_AddLibraryAs_SHARED_SDL2  - "YES" will search for a shared library
#  The following search paths need to be set for Android:
#    .ANDROID_SourcePath_SDL2           - Location of the SDL2 sources
#    .ANDROID_LibraryArtifactsPath_SDL2 - Location of the SDL2 binaries
#
################################################################################
# Defines:
#   * Imported targets:
#       REngine::SDL2
#   * Variables:
#       SDL2_FOUND          - If false, do not try to link to SDL2
#       SDL2_LIBRARY        - The name of the library to link against
#       SDL2_LIBRARIES      -
#       SDL2_INCLUDE_DIR    - The location of SDL.h
#       SDL2_SHARED_LIBRARY - The name of the shared library (if available)
#       SDL2_VERSION_STRING - String containing the version of SDL2
################################################################################
#
# Flags:
#   SDL2_BUILDING_LIBRARY
#
# If this is defined, then no SDL2_main will be linked in because only
# applications need main(). Otherwise, it is assumed you are building an
# application and this module will attempt to locate and set the proper link
# flags as part of the returned SDL2_LIBRARY variable.
#
# Don't forget to include SDLmain.h and SDLmain.m your project for the
# OS X framework based version. (Other versions link to -lSDLmain which
# this module will try to find on your behalf.) Also for OS X, this
# module will automatically add the -framework Cocoa on your behalf.
#
# Additional Note: If you see an empty SDL2_LIBRARY_TEMP in your
# configuration and no SDL2_LIBRARY, it means CMake did not find your SDL
# library (SDL.dll, libsdl.so, SDL.framework, etc). Set
# SDL2_LIBRARY_TEMP to point to your SDL library, and configure again.
# Similarly, if you see an empty SDLMAIN_LIBRARY, you should set this
# value as appropriate. These values are used to generate the final
# SDL2_LIBRARY variable, but when these values are unset, SDL2_LIBRARY
# does not get created.
#
# $SDLDIR is an environment variable that would correspond to the
# ./configure --prefix=$SDLDIR used in building SDL. l.e.galup 9-20-02
#
# Modified by Eric Wing. Added code to assist with automated building
# by using environmental variables and providing a more
# controlled/consistent search behavior. Added new modifications to
# recognize OS X frameworks and additional Unix paths (FreeBSD, etc).
# Also corrected the header search path to follow "proper" SDL
# guidelines. Added a search for SDLmain which is needed by some
# platforms. Added a search for threads which is needed by some
# platforms. Added needed compile switches for MinGW.
#
# On OSX, this will prefer the Framework version (if found) over others.
# People will have to manually change the cache values of SDL2_LIBRARY to
# override this selection or set the CMake environment
# CMAKE_INCLUDE_PATH to modify the search paths.
#
# Note that the header path has changed from SDL/SDL.h to just SDL.h
# This needed to change because "proper" SDL convention is #include
# "SDL.h", not <SDL/SDL.h>. This is done for portability reasons
# because not all systems place things in SDL/ (see FreeBSD).
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

if (NOT SDL2_DIR)
  set (SDL2_DIR "" CACHE PATH "SDL2 directory")
endif ()

################################################################################
# Header files
################################################################################

if (ANDROID)
  if (NOT .ANDROID_SourcePath_SDL2)
    message (FATAL_ERROR ".ANDROID_SourcePath_SDL2 is not set")
  endif ()

  file (TO_CMAKE_PATH
    ${.ANDROID_SourcePath_SDL2}
    __LibrarySourcePath
  )
  list (APPEND .SDL2_IncludeDirHints
    "${__LibrarySourcePath}"
  )
  unset (__SDL2_SourcePath)

  # NO_CMAKE_FIND_ROOT_PATH tells CMake not to use the CMAKE_FIND_ROOT_PATH
  # variable, which is a list of root paths to search on the filesystem. Instead
  # CMake should search in the provided alternative paths. This is required when
  # cross-compiling for Android.
  set (NO_CMAKE_FIND_ROOT_PATH "NO_CMAKE_FIND_ROOT_PATH")
else ()
  list (APPEND .SDL2_IncludeDirHints
    $ENV{SDLDIR}
    "${SDL2_DIR}"
    "$ENV{__EXTERNAL_LIBS}/SDL2"
  )
endif ()

find_path (SDL2_INCLUDE_DIR
  NAMES
    "SDL.h"
  HINTS
    ${.SDL2_IncludeDirHints}
  PATH_SUFFIXES
    "/SDL2"
    # path suffixes to search inside ENV{SDLDIR}
    "/include/SDL2"
    "/include"
  ${NO_CMAKE_FIND_ROOT_PATH}
)

unset (.SDL2_IncludeDirHints)

################################################################################
# Library files
################################################################################

if (ANDROID)
  if (NOT .ANDROID_LibraryArtifactsPath_SDL2)
    message (FATAL_ERROR ".ANDROID_LibraryArtifactsPath_SDL2 is not set")
  endif ()
  list (APPEND .SDL2_LibraryFileHints
    "${.ANDROID_LibraryArtifactsPath_SDL2}"
  )
else ()
  list (APPEND .SDL2_LibraryFileHints
    "$ENV{SDLDIR}"
    "${SDL2_DIR}"
    "$ENV{__EXTERNAL_LIBS}/SDL2"
  )
endif ()

if (ANDROID)
  if (.ANDROID_AddLibraryAs_SHARED_SDL2)
    AddImportedLibrary (SDL2 SHARED
      "libSDL2.so"
      "${.SDL2_LibraryFileHints}"
    )
  else ()
    AddImportedLibrary (SDL2 STATIC
      "libSDL2.a"
      "${.SDL2_LibraryFileHints}"
    )
  endif ()
else ()
  # SDL-1.1 is the name used by FreeBSD ports...
  # don't confuse it for the version number.
  set (.LibraryFile "SDL2")

    # Set search path sufficies
  if (CMAKE_SIZEOF_VOID_P EQUAL 8)
    # If compile target is 64bit
    set (.MSVC_libPathSuffix lib/x64)
  else ()
    # If compile target is 32bit
    set (.MSVC_libPathSuffix lib/x86)
  endif ()

  find_library (SDL2_LIBRARY
    NAMES
      "${.LibraryFile}"
    HINTS
      ${.SDL2_LibraryFileHints}
    PATH_SUFFIXES
      "lib"
      "${.MSVC_libPathSuffix}"
  )
endif ()

set (SDL2_LIBRARY_TEMP ${SDL2_LIBRARY})
if ("${CMAKE_SYSTEM_NAME}" STREQUAL "Windows")
  set (__LibraryFile "${.LibraryFile}.dll")

  find_file (SDL2_SHARED_LIBRARY
    NAMES
      "${__LibraryFile}"
    HINTS
      "$ENV{__EXTERNAL_LIBS}/SDL2"
    PATH_SUFFIXES
      ${.MSVC_libPathSuffix}
    NO_DEFAULT_PATH
  )

  # Hide internal implementation details from user
  set_property (CACHE SDL2_SHARED_LIBRARY PROPERTY TYPE INTERNAL)
  if (NOT SDL2_SHARED_LIBRARY)
    message (FATAL_ERROR "Unable to find library file: \"${__LibraryFile}\"")
  endif ()

  unset (__LibraryFile)
endif ()

if (NOT SDL2_BUILDING_LIBRARY)
  if (NOT SDL2_INCLUDE_DIR MATCHES ".framework")
    # Non-OS X framework versions expect you to also dynamically link to
    # SDLmain. This is mainly for Windows and OS X. Other (Unix) platforms
    # seem to provide SDLmain for compatibility even though they don't
    # necessarily need it.
    if (NOT ANDROID)
      set (.LibraryFile "SDL2main")
      find_library (SDL2MAIN_LIBRARY
        NAMES
          "${.LibraryFile}"
        HINTS
          ${.SDL2_LibraryFileHints}
        PATH_SUFFIXES
          "lib"
          "${.MSVC_libPathSuffix}"
        PATHS
        "/sw"
        "/opt/local"
        "/opt/csw"
        "/opt"
      )
    endif ()
  endif ()
endif()

unset (.MSVC_libPathSuffix)
unset (.SDL2_LibraryFileHints)

# SDL may require threads on your system.
# The Apple build may not need an explicit flag because one of the
# frameworks may already provide it.
# But for non-OSX systems, I will use the CMake Threads package.
if (NOT APPLE)
  find_package (Threads)
endif ()

# MinGW needs an additional link flag, -mwindows
# It's total link flags should look like -lmingw32 -lSDLmain -lSDL -mwindows
if (MINGW)
  set (MINGW32_LIBRARY mingw32 "-mwindows" CACHE STRING "link flags for MinGW")
endif ()

if (SDL2_LIBRARY_TEMP)
  # For SDLmain
  if (SDL2MAIN_LIBRARY AND NOT SDL2_BUILDING_LIBRARY)
    list (FIND SDL2_LIBRARY_TEMP "${SDL2MAIN_LIBRARY}" __SDL2_MAIN_INDEX)
    if (__SDL2_MAIN_INDEX EQUAL -1)
      set (SDL2_LIBRARY_TEMP "${SDL2MAIN_LIBRARY}" ${SDL2_LIBRARY_TEMP})
    endif ()
    unset (__SDL2_MAIN_INDEX)
  endif ()

  # For OS X, SDL uses Cocoa as a backend so it must link to Cocoa.
  # CMake doesn't display the -framework Cocoa string in the UI even
  # though it actually is there if I modify a pre-used variable.
  # I think it has something to do with the CACHE STRING.
  # So I use a temporary variable until the end so I can set the
  # "real" variable in one-shot.
  if (APPLE)
    set (SDL2_LIBRARY_TEMP ${SDL2_LIBRARY_TEMP} "-framework Cocoa")
  endif ()

  # For threads, as mentioned Apple doesn't need this.
  # In fact, there seems to be a problem if I used the Threads package
  # and try using this line, so I'm just skipping it entirely for OS X.
  if (NOT APPLE)
    set (SDL2_LIBRARY_TEMP ${SDL2_LIBRARY_TEMP} ${CMAKE_THREAD_LIBS_INIT})
  endif ()

  # For MinGW library
  if (MINGW)
    set (SDL2_LIBRARY_TEMP ${MINGW32_LIBRARY} ${SDL2_LIBRARY_TEMP})
  endif ()

  # Set the final string here so the GUI reflects the final state.
  set (SDL2_LIBRARIES ${SDL2_LIBRARY_TEMP} CACHE STRING
    "Where the SDL2 Library can be found"
  )
endif ()

if (SDL2_INCLUDE_DIR AND EXISTS "${SDL2_INCLUDE_DIR}/SDL2_version.h")
  file (STRINGS "${SDL2_INCLUDE_DIR}/SDL2_version.h" SDL2_VERSION_MAJOR_LINE
    REGEX "^#define[ \t]+SDL2_MAJOR_VERSION[ \t]+[0-9]+$"
  )
  file (STRINGS "${SDL2_INCLUDE_DIR}/SDL2_version.h" SDL2_VERSION_MINOR_LINE
    REGEX "^#define[ \t]+SDL2_MINOR_VERSION[ \t]+[0-9]+$"
  )
  file (STRINGS "${SDL2_INCLUDE_DIR}/SDL2_version.h" SDL2_VERSION_PATCH_LINE
    REGEX "^#define[ \t]+SDL2_PATCHLEVEL[ \t]+[0-9]+$"
  )
  string (REGEX REPLACE "^#define[ \t]+SDL2_MAJOR_VERSION[ \t]+([0-9]+)$" "\\1"
    SDL2_VERSION_MAJOR "${SDL2_VERSION_MAJOR_LINE}"
  )
  string (REGEX REPLACE "^#define[ \t]+SDL2_MINOR_VERSION[ \t]+([0-9]+)$" "\\1"
    SDL2_VERSION_MINOR "${SDL2_VERSION_MINOR_LINE}"
  )
  string (REGEX REPLACE "^#define[ \t]+SDL2_PATCHLEVEL[ \t]+([0-9]+)$" "\\1"
    SDL2_VERSION_PATCH "${SDL2_VERSION_PATCH_LINE}"
  )
  set (SDL2_VERSION_STRING
    ${SDL2_VERSION_MAJOR}.${SDL2_VERSION_MINOR}.${SDL2_VERSION_PATCH}
  )
  unset (SDL2_VERSION_MAJOR_LINE)
  unset (SDL2_VERSION_MINOR_LINE)
  unset (SDL2_VERSION_PATCH_LINE)
  unset (SDL2_VERSION_MAJOR)
  unset (SDL2_VERSION_MINOR)
  unset (SDL2_VERSION_PATCH)
endif ()

################################################################################
# find_package arguments
################################################################################

list (APPEND .PackageVariables
  SDL2_INCLUDE_DIR
)
if (NOT ANDROID)
  list (APPEND .PackageVariables
    ${.PackageVariables}
    SDL2_LIBRARY
    SDL2_LIBRARIES
  )
  if (SDL2_SHARED_LIBRARY)
    list (APPEND .PackageVariables
      SDL2_SHARED_LIBRARY
    )
  endif ()
endif ()

include (FindPackageHandleStandardArgs)
find_package_handle_standard_args (SDL2
  REQUIRED_VARS
    ${.PackageVariables}
  VERSION_VAR
    SDL2_VERSION_STRING
)

mark_as_advanced (${.PackageVariables})

unset (.PackageVariables)

################################################################################
# Imported target
################################################################################

if (SDL2_FOUND AND NOT TARGET REngine::SDL2)
  if (ANDROID)
    add_library (REngine::SDL2 INTERFACE IMPORTED)
    set_property (TARGET REngine::SDL2
      PROPERTY
        INTERFACE_INCLUDE_DIRECTORIES
          "${SDL2_INCLUDE_DIR}"
    )
    target_link_libraries(REngine::SDL2
      INTERFACE
        SDL2
    )
  else ()
    add_library (REngine::SDL2 UNKNOWN IMPORTED)
    set (.InterfaceLinkLibraries ${SDL2_LIBRARIES})
    list (REMOVE_ITEM .InterfaceLinkLibraries ${SDL2_LIBRARY})
    set_target_properties (REngine::SDL2
      PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES
          "${SDL2_INCLUDE_DIR}"
        IMPORTED_LOCATION
          "${SDL2_LIBRARY}"
        INTERFACE_LINK_LIBRARIES
          "${.InterfaceLinkLibraries}"
    )
  endif ()
endif ()

################################################################################

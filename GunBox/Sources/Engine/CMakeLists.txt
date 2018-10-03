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

 # Build the targets as STATIC libraries by default
option (option_EngineLibraryAs_SHARED NO)

set (.EngineLibraryType "STATIC")
if (option_EngineLibraryAs_SHARED)
  set (.EngineLibraryType "SHARED")
endif ()

################################################################################

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

add_library (${PROJECT_NAME}_Base INTERFACE)
target_compile_definitions (${PROJECT_NAME}_Base
  INTERFACE
    # Enable stricter type declarations and usage
    $<$<PLATFORM_ID:Windows>:STRICT>
    ############################################################################
    # Exclude APIs from "Windows.h" for faster builds
    #   1. Define WIN32_LEAN_AND_MEAN to exclude APIs such as Cryptography, DDE,
    #      RPC, Shell, and Windows Sockets.
    #   2. Define one or more of the NOapi symbols to exclude the API. For
    #      example, NOCOMM excludes the serial communication API. For a list of
    #      support NOapi symbols, see Windows.h.
    ############################################################################
    # Cryptography, DDE, RPC, Shell, and Windows Sockets
    $<$<PLATFORM_ID:Windows>:WIN32_LEAN_AND_MEAN>
    # *  NOGDICAPMASKS     - CC_*, LC_*, PC_*, CP_*, TC_*, RC_
    $<$<PLATFORM_ID:Windows>:NOGDICAPMASKS>
    # *  NOVIRTUALKEYCODES - VK_*
    $<$<PLATFORM_ID:Windows>:NOVIRTUALKEYCODES>
    # *  NOWINMESSAGES     - WM_*, EM_*, LB_*, CB_*
    $<$<PLATFORM_ID:Windows>:NOWINMESSAGES>
    # *  NOWINSTYLES       - WS_*, CS_*, ES_*, LBS_*, SBS_*, CBS_*
    $<$<PLATFORM_ID:Windows>:NOWINSTYLES>
    # *  NOSYSMETRICS      - SM_*
    $<$<PLATFORM_ID:Windows>:NOSYSMETRICS>
    # *  NOMENUS           - MF_*
    $<$<PLATFORM_ID:Windows>:NOMENUS>
    # *  NOICONS           - IDI_*
    $<$<PLATFORM_ID:Windows>:NOICONS>
    # *  NOKEYSTATES       - MK_*
    $<$<PLATFORM_ID:Windows>:NOKEYSTATES>
    # *  NOSYSCOMMANDS     - SC_*
    $<$<PLATFORM_ID:Windows>:NOSYSCOMMANDS>
    # *  NORASTEROPS       - Binary and Tertiary raster ops
    $<$<PLATFORM_ID:Windows>:NORASTEROPS>
    # *  NOSHOWWINDOW      - SW_*
    $<$<PLATFORM_ID:Windows>:NOSHOWWINDOW>
    # *  OEMRESOURCE       - OEM Resource values
    $<$<PLATFORM_ID:Windows>:OEMRESOURCE>
    # *  NOATOM            - Atom Manager routines
    $<$<PLATFORM_ID:Windows>:NOATOM>
    # *  NOCLIPBOARD       - Clipboard routines
    $<$<PLATFORM_ID:Windows>:NOCLIPBOARD>
    # *  NOCOLOR           - Screen colors
    $<$<PLATFORM_ID:Windows>:NOCOLOR>
    # *  NOCTLMGR          - Control and Dialog routines
    $<$<PLATFORM_ID:Windows>:NOCTLMGR>
    # *  NODRAWTEXT        - DrawText() and DT_*
    $<$<PLATFORM_ID:Windows>:NODRAWTEXT>
    # *  NOGDI             - All GDI defines and routines
    $<$<PLATFORM_ID:Windows>:NOGDI>
    # *  NOKERNEL          - All KERNEL defines and routines
    $<$<PLATFORM_ID:Windows>:NOKERNEL>
    # *  NOUSER            - All USER defines and routines
    $<$<PLATFORM_ID:Windows>:NOUSER>
    # *  NONLS             - All NLS defines and routines
    $<$<PLATFORM_ID:Windows>:NONLS>
    # *  NOMB              - MB_* and MessageBox()
    $<$<PLATFORM_ID:Windows>:NOMB>
    # *  NOMEMMGR          - GMEM_*, LMEM_*, GHND, LHND, associated routines
    $<$<PLATFORM_ID:Windows>:NOMEMMGR>
    # *  NOMETAFILE        - typedef METAFILEPICT
    $<$<PLATFORM_ID:Windows>:NOMETAFILE>
    # *  NOMINMAX          - Macros min(a,b) and max(a,b)
    $<$<PLATFORM_ID:Windows>:NOMINMAX>
    # *  NOMSG             - typedef MSG and associated routines
    $<$<PLATFORM_ID:Windows>:NOMSG>
    # *  NOOPENFILE        - OpenFile(), OemToAnsi, AnsiToOem, and OF_*
    $<$<PLATFORM_ID:Windows>:NOOPENFILE>
    # *  NOSCROLL          - SB_* and scrolling routines
    $<$<PLATFORM_ID:Windows>:NOSCROLL>
    # *  NOSERVICE         - All Service Controller routines, SERVICE_ equates, etc.
    $<$<PLATFORM_ID:Windows>:NOSERVICE>
    # *  NOSOUND           - Sound driver routines
    $<$<PLATFORM_ID:Windows>:NOSOUND>
    # *  NOTEXTMETRIC      - typedef TEXTMETRIC and associated routines
    $<$<PLATFORM_ID:Windows>:NOTEXTMETRIC>
    # *  NOWH              - SetWindowsHook and WH_*
    $<$<PLATFORM_ID:Windows>:NOWH>
    # *  NOWINOFFSETS      - GWL_*, GCL_*, associated routines
    $<$<PLATFORM_ID:Windows>:NOWINOFFSETS>
    # *  NOCOMM            - COMM driver routines
    $<$<PLATFORM_ID:Windows>:NOCOMM>
    # *  NOKANJI           - Kanji support stuff.
    $<$<PLATFORM_ID:Windows>:NOKANJI>
    # *  NOHELP            - Help engine interface.
    $<$<PLATFORM_ID:Windows>:NOHELP>
    # *  NOPROFILER        - Profiler interface.
    $<$<PLATFORM_ID:Windows>:NOPROFILER>
    # *  NODEFERWINDOWPOS  - DeferWindowPos routines
    $<$<PLATFORM_ID:Windows>:NODEFERWINDOWPOS>
    # *  NOMCX             - Modem Configuration Extensions
    $<$<PLATFORM_ID:Windows>:NOMCX>
)
target_compile_features (${PROJECT_NAME}_Base
  INTERFACE
    # Enable C++17 standard complience
    cxx_std_17
)
target_compile_options (${PROJECT_NAME}_Base
  INTERFACE
    # Enable Just My Code debugging
    $<$<CXX_COMPILER_ID:MSVC>:/JMC>
    # Enable C++ Standard compliance
    $<$<CXX_COMPILER_ID:MSVC>:/permissive->
    $<$<AND:$<PLATFORM_ID:Windows>,$<CXX_COMPILER_ID:Clang>>:/std:c++latest>
    $<$<AND:$<PLATFORM_ID:Windows>,$<CXX_COMPILER_ID:Clang>>:-Wno-pragma-pack>
    $<$<AND:$<PLATFORM_ID:Windows>,$<CXX_COMPILER_ID:Clang>>:-Wno-\#pragma-messages>
)

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
  find_package (OpenGL REQUIRED)
endif ()

# Link the packages
target_link_libraries (${PROJECT_NAME}
  PUBLIC
    ${PROJECT_NAME}_Base
    REngine::FreeType2
    REngine::SDL2
  PUBLIC
    glad
)
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
  "Sources/Common/Constants/GpuPreferences.hpp"
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

if (NOT ANDROID)
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

################################################################################

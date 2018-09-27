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
option (option_ENGINE_LIBRARY_AS_SHARED NO)

set (ENGINE_LIBRARY_TYPE "STATIC")
if (option_ENGINE_LIBRARY_AS_SHARED)
  set (ENGINE_LIBRARY_TYPE "SHARED")
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
# Targets
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

include ("Engine_SourceFiles.cmake")
add_library (${PROJECT_NAME} ${ENGINE_LIBRARY_TYPE}
  # Source files
  ${Engine_SourceFiles}
)

if (WIN32 AND option_ENGINE_LIBRARY_AS_SHARED)
  set_property (TARGET ${PROJECT_NAME} PROPERTY WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
endif ()

target_include_directories (${PROJECT_NAME}
  PUBLIC
    "Sources"
)

# Find external libraries
if (ANDROID)
  set (ANDROID_SDL2_LIBRARY_AS_STATIC "UseStaticSDL2Library")
  set (SDL2_LIBRARY_BINARY_PATH "${NativeLibraryArtifactsOutputDir}/sdl2lib")
  set (SDL2_SOURCE_PATH "${ExternalLibrariesRootDir}/SDL2")
endif ()
find_package (SDL2 REQUIRED)
if (NOT SDL2_FOUND)
  message ("ERROR: SDL2 SDK was not found in the search path!")
endif()
list (APPEND SharedLibraries ${SDL2_SHARED_LIBRARY})

if (NOT ANDROID)
  find_package (OpenGL REQUIRED)
  if (NOT OPENGL_FOUND)
    message ("ERROR: OpenGL was not found in the search path!")
  endif()
endif ()

target_link_libraries (${PROJECT_NAME}
  PUBLIC
    ${PROJECT_NAME}_Base
    glad
    REngine::SDL2
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
    PUBLIC
    OpenGL::GL
  )
endif ()

add_library (${PROJECT_NAME}_main STATIC
  "Sources/Common/Constants/GpuPreferences.hpp"
  "Sources/main.cpp"
)
target_compile_definitions (${PROJECT_NAME}_main
  PRIVATE
    $<$<PLATFORM_ID:Windows>:PREFER_DISCRETE_GPU>
)
target_link_libraries (${PROJECT_NAME}_main
  PUBLIC
    ${PROJECT_NAME}
)

################################################################################

################################################################################
# Installation
################################################################################

if (NOT ANDROID)
  message ("Shared libraries to install:")
  foreach (SharedLibrary ${SharedLibraries})
    message ("    ${SharedLibrary}")
  endforeach ()

  # Set installation path
  set (InstallationPath ${CMAKE_INSTALL_PREFIX})

  if (option_ENGINE_LIBRARY_AS_SHARED)
    # Install targets
    install (
      TARGETS
        ${PROJECT_NAME}
      RUNTIME DESTINATION
        ${InstallationPath}
    )
  endif ()

  # Install required files
  install (
    FILES
      ${SharedLibraries}
    DESTINATION
      ${InstallationPath}
  )
endif ()

################################################################################

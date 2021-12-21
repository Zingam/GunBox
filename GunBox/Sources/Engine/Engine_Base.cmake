################################################################################
include_guard ()
################################################################################

################################################################################
# Build/Configuration types
################################################################################

# Check for allowed build/configuration types
if (CMAKE_BUILD_TYPE)
  # Specifies the build type on single-configuration generators.
  if (NOT (("Debug" STREQUAL "${CMAKE_BUILD_TYPE}")
    OR ("Release" STREQUAL "${CMAKE_BUILD_TYPE}")
    OR ("RelWithDebInfo" STREQUAL "${CMAKE_BUILD_TYPE}"))
  )
    message (FATAL_ERROR
      "Unsupported build type: ${CMAKE_BUILD_TYPE}"
    )
  endif ()
endif ()

if (CMAKE_CONFIGURATION_TYPES)
  # Specifies the available build types on multi-config generators.
  if (NOT (("Debug" STREQUAL "${CMAKE_CONFIGURATION_TYPES}")
    OR ("Release" STREQUAL "${CMAKE_CONFIGURATION_TYPES}")
    OR ("RelWithDebInfo" STREQUAL "${CMAKE_CONFIGURATION_TYPES}"))
  )
    message (FATAL_ERROR
      "Unsupported configuration type: ${CMAKE_CONFIGURATION_TYPES}"
    )
  endif ()
endif ()

if (NOT (CMAKE_BUILD_TYPE OR CMAKE_CONFIGURATION_TYPES))
  message (FATAL_ERROR
    "No build or configuration type is set!"
  )
endif ()

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
    # Enable C++23 Standard compliance
    cxx_std_23
)
target_compile_options (${PROJECT_NAME}_Base
  INTERFACE
    # (MSVC) Enable Just My Code debugging
    $<$<AND:$<CXX_COMPILER_ID:MSVC>,$<NOT:$<CONFIG:Release>>>:/JMC>
    # (MSVC) Enable C++ Standard compliance
    $<$<CXX_COMPILER_ID:MSVC>:/permissive->
    # (Clang/Windows) Enable (latest) C++ Standard compliance
    $<$<AND:$<PLATFORM_ID:Windows>,$<CXX_COMPILER_ID:Clang>>:/std:c++latest>
    $<$<AND:$<PLATFORM_ID:Windows>,$<CXX_COMPILER_ID:Clang>>:-Wno-pragma-pack>
    $<$<AND:$<PLATFORM_ID:Windows>,$<CXX_COMPILER_ID:Clang>>:-Wno-\#pragma-messages>
)
target_link_libraries(${PROJECT_NAME}_Base
  INTERFACE
    # (GCC) Enable <filesystem>
    $<$<CXX_COMPILER_ID:GNU>:-lstdc++fs>
)

target_include_directories (${PROJECT_NAME}_Base
  INTERFACE
    "Include"
)

################################################################################

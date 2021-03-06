# GunBox

A game programming exercise with **SDL2**, **OpenGL**, **Vulkan**...

[![Build status](https://ci.appveyor.com/api/projects/status/beo40x7kkylor8r5?svg=true)](https://ci.appveyor.com/project/Zingam/gunbox)

## Prerequisites
### Software
1. C++17 compiler (or newer)
2. CMake 3.10 (or newer)
3. vcpkg (optional)

### Third Party Library
1. FreeType 2.9.1 (or newer)
2. SDL 2.0.12 (or newer)
3. Vulkan SDK

### How to Install Third Party Libraries with `vcpkg`

* To install a library `library_name` with enabled feature `[feature]` for platform `x64-windows` use the command syntax:
```bat
.\vcpkg.exe install library_name[feature] --triplet x64-windows`
```
* To install the required libraries:
```bat
.\vcpkg.exe install freetype sdl2[vulkan] --triplet x64-windows
```

### How to Install Third Party Libraries on Linux - Ubuntu 19.10+

* Mesa development libraries:
```bash
sudo apt-get install libgl1-mesa-dev
```
* Vulkan SDK:
  * Install from LunarG web site:
    
    https://vulkan.lunarg.com/sdk/home#linux
  * Set environment variable ```VULKAN_SDK```:
    ```bash
    export VULKAN_SDK="\usr"
    ```

* Third party libraries with ```vcpkg``` on Linux:
  * Install command:
    ```bash
    ./vcpkg install freetype sdl2[vulkan]
    ```
  * Set environment variable ```VCPKG_ROOT```:
    ```bash
    export VCPKG_ROOT="$HOME\Tools\vcpkg"
    ```
    Set the proper location if necessary.

## Notes

* Markdown (*.md)
  * Documentation uses the Markdown format
  * Recommended editor: **Visual Studio Code**'s extension Markdown Preview Enhanced
* UML (*.puml)
  * UML diagrams use PlantUML syntax
  * Recomended editor: **Visual Studio Code**'s extension: PlantUML
  
## Code Formatting

- Use **ClangFormat** to apply the format definitions from: `.clang-format`.
- Use `// clang-format off` and `// clang-format on` if necessary to prevent **ClangFormat** from changing the desired code formatting.

## Code Style

### Header Files

* Use *trailing return type syntax* in header files for function and method declarations.

### Header Files Include Oder

1. Related .cpp file header
2. Current project headers
3. Other projects' headers
4. Third party libraries' headers
5. System headers
6. C Standard Library headers
7. C++ Standard Library headers

### CMake

* Identation is done by two space characters:
  ```CMake
  if (NOT DEFINED .MyVariable)
    set (.MyVariable "...")
  endif ()
  ```
* Function/Macro names start with a capital letter and use camel case names:
  ```CMake
  function (MyFunction ...)
  ```
* Function call syntax:
  ```CMake
  add_subdirectory ("SDL2")
  set_target_properties (SDL2
    PROPERTIES
      ARCHIVE_OUTPUT_DIRECTORY
       "${LibraryArtifactsOutputDirectory}/${CMAKE_BUILD_TYPE}/${ANDROID_ABI}"
      LIBRARY_OUTPUT_DIRECTORY
       "${LibraryArtifactsOutputDirectory}/${CMAKE_BUILD_TYPE}/${ANDROID_ABI}"
  )
  ```
* Variable names start with `.` followed by a capital letter and use camel case names:
  ```CMake
  set (.MyVariable ...)
  ```
* LocalVariables start with `__` followed by a capital letter and use camel case names and need to be unset when going out of scope:
  ```CMake
  set (__MyLocalVariable ...)
  ...
  unset (_MyLocalVariable)
  ```
* Variables represinting a string are allways quoted:
  ```CMake
  set (.MyVariable "...")
  if ("${.MyVariable}" STREQUAL "...")
  ```
* Use `if (DEFINED <variable>)` to check if a variable is set:
  ```CMake
  if (DEFINED .MyVariable)
  ...
  endif ()
  ```
* Use `if (<variable>)` to check if a variable has a non-empty value:
  ```CMake
  if (.MyVariable)
  endif ()
  ```

## Configuring IDEs

### Visual Studio Code / C/C++ for Visual Studio Code

1. Required **Visual Studio Code** extensions:
   + **C/C++ for Visual Studio Code**
   + **CMake Tools**
   + **CMake For VisualStudio Code**
2. Configuring **Visual Studio Code** and the extensions:
   + Select *File->Preferences->Settings* then search for the appropriate options, e.g. "cmake", etc.
3. **CMake Tools** settings:
   + Recommended *User/Workspace settings*:

    ```json5
    {
        // The value to use in a configuration if "configurationProvider" is 
        // either not specified or set to "${default}".
        "C_Cpp.default.configurationProvider": "vector-of-bool.cmake-tools",
        // The directory where CMake build files will go
        "cmake.buildDirectory": "${workspaceRoot}/../__build-output-${workspaceRootFolderName}/${generator}-${buildType}",
        // CMake variables to set on the command line
        "cmake.configureSettings": {
            "option_ENGINE_LIBRARY_AS_SHARED:BOOL": "YES"
        },
        // The CMake generator to use
        "cmake.generator": "Ninja",
        // The directory where CMake installed files will go
        "cmake.installPrefix": "${workspaceRoot}/../__install-output-${workspaceRootFolderName}/${generator}-${buildType}",
        // The directory of the root CMakeLists.txt file
        "cmake.sourceDirectory": "${workspaceRoot}/${workspaceRootFolderName}",
        // Zoom the font of the editor when using mouse wheel and holding 
        // `Ctrl`.
        "editor.mouseWheelZoom": true,
        // Render vertical rulers after a certain number of monospace 
        // characters. Use multiple values for multiple rulers. No rulers are 
        // drawn if array is empty.
        "editor.rulers": [
            80,
            120
        ],
        // Control the visibility of the menu bar. A setting of 'toggle' means 
        // that the menu bar is hidden and a single press of the Alt key will 
        // show it. By default, the menu bar will be visible, unless the window
        // is full screen.
        //  - default: Menu is only hidden in full screen mode.
        //  - visible: Menu is always visible even in full screen mode.
        //  - toggle: Menu is hidden but can be displayed via Alt key.
        "window.menuBarVisibility": "toggle"
    }
    ```
   + To execute **CMake** commands open the **Command panel** (*CTRL + SHIFT + P*) and search or the required command, e.g. *"cmake"*, *"cpp"* or press *F1*.
    ```json5
    {
        "C_Cpp.default.configurationProvider": "vector-of-bool.cmake-tools",
        "cmake.buildDirectory": "${workspaceRoot}/../__build-output-${workspaceRootFolderName}/${generator}-${buildType}",
        "cmake.configureSettings": {
            "option_ENGINE_LIBRARY_AS_SHARED:BOOL": "YES"
        },
        "cmake.generator": "Ninja",
        "cmake.installPrefix": "${workspaceRoot}/../__install-output-${workspaceRootFolderName}/${generator}-${buildType}",
        "cmake.sourceDirectory": "${workspaceRoot}/${workspaceRootFolderName}",
        "editor.mouseWheelZoom": true,
        "editor.rulers": [
            80,
            120
        ],
        "window.menuBarVisibility": "toggle"
    }
    ```

## Passing Command Line Arguments

### Visual Studio 2017

To pass command line arguments to the executing program in a **CMake/Open Folder** based project:
1. In **Solution Explorer** right-click the top `CMakeLists.txt` and select *Debug and Launch Settings->GunBox_Game.exe (Install)* which will open `launch.vs.json`
2. In `launch.vs.json` add `"args": [ "--show-system-console", "--resolution: 640x480" ]` to `"configurations"`:
3. Available command line options:
   + --fullscreen
   + --help
   + --renderer: <OpenGL|Vulkan>[Debug]
   + --resolution: &lt;width>x&lt;height>
   + --show-system-console

Example:
```json5
{
  "version": "0.2.1",
  "defaults": {},
  "configurations": [
    {
      "type": "default",
      "name": "GunBox_Game.exe (Install)",
      "project": "CMakeLists.txt",
      "projectTarget": "GunBox_Game.exe (Install)",
      "args": [
        //"--renderer: OpenGL",
        //"--renderer: Vulkan",
        "--renderer: Vulkan[Debug]",
        "--resolution: 640x480",
        "--show-system-console"
      ]
    }
  ]
}
```
**Note:** In case Visual Studio 2019 is used to open the project root folder and the root *"CMakeLists.txt"* is located in *"GunBox/GunBox/CMakeLists.txt"* it maybe necessary to change the project path as follows:
```json5
      "project": "GunBox/CMakeLists.txt",
```

## Configuring Debug

### Visual Studio Code

**"program"** points to the executable file, which could be set as:
- "program": "${command:cmake.launchTargetPath}"
- "program": "${workspaceRoot}/../__install-output-GunBox/Ninja-Debug/GunBox_Game"

Example (`launch.json`):
```json5
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "(gdb) Launch",
            "type": "cppdbg",
            "request": "launch",
            // Resolved by CMake Tools:
            "program": "${command:cmake.launchTargetPath}",
            "args": [
                //"--renderer:", "OpenGL",
                //"--renderer:", "OpenGL[Debug]",
                //"--renderer:", "Vulkan",
                "--renderer:", "Vulkan[Debug]",
                "--resolution:", "640x480",
                "--show-system-console"
            ],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ]
        }
    ]
}
```
*Note: `"args": []` need to be passed as separate array elements.*

Example (`settings.json`):
```json5
{
    "cmake.buildDirectory": "${workspaceFolder}/../__build-output-${workspaceRootFolderName}",
    "cmake.installPrefix": "${workspaceFolder}/../__install-output-${workspaceRootFolderName}",
    "cmake.sourceDirectory": "${workspaceFolder}/GunBox",
    "cmake.configureArgs": [
        "-Doption_EngineLibraryAs_SHARED:BOOL=YES",
        "-Doption_EnableLoggingLevel_Verbose:BOOL=YES",
    ],
}
```

## Building on the Command Line

### On Linux:
```bash
mkdir output-build
mkdir output-install
cd output-build
cmake -G"Ninja" -DCMAKE_BUILD_TYPE=Debug -D"option_EngineLibraryAs_SHARED:BOOL=YES" -D"option_EnableLoggingLevel_Verbose:BOOL=YES" -D"CMAKE_INSTALL_PREFIX:STRING=$(dirname `pwd`)/output-install" ../GunBox/GunBox
cmake --build .
cmake --install .
```
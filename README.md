# GunBox

An exercise in **SDL2 API** programming...

## Notes

* Markdown (*.md)
  * Documentation uses the Markdown format
  * Recommended editor: **Visual Studio Code**'s extension Markdown Preview Enhanced
* UML (*.puml)
  * UML diagrams use PlantUML syntax
  * Recomended editor: **Visual Studio Code**'s extension: PlantUML
  
## Code Formatting

- Use **ClangFormat** to apply the format definitions from: `.clang-format`.
- Use `// clang-format on` and `clang-format off` Wherever appropriate to prevent **ClangFormat** from changing the desired code formatting.

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

## Configuring an IDE

### Visual Studio Code / C/C++ for Visual Studio Code

1. Required **Visual Studio Code** extensions:
1.1 **C/C++ for Visual Studio Code**
1.2 **CMake Tools**
1.3. **CMake For VisualStudio Code**
2. Configuring **Visual Studio Code** and the extensions:
   + Select *File->Preferences->Settings* then search for the appropriate options, e.g. "cmake", etc.
3. **CMake Tools** settings:
   + Recommended *User/Workspace settings*:

    ```json
    {
        // The directory where CMake build files will go
        "cmake.buildDirectory": "${workspaceRoot}/../__build-output-${workspaceRootFolderName}/${generator}-${buildType}",
        // CMake variables to set on the command line
        "cmake.configureSettings": {
            "option_ENGINE_LIBRARY_AS_SHARED:BOOL": "YES"
        },
        // The CMake generator to use
        "cmake.generator": "Ninja",
        // The directory where CMake installed files will go
        "cmake.installPrefix": "${workspaceRoot}/../__install/${generator}-${buildType}",
        // The value to use in a configuration if "configurationProvider" is 
        // either not specified or set to "${default}".
        "C_Cpp.default.configurationProvider": "vector-of-bool.cmake-tools",
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
    ```json
    {
        "cmake.buildDirectory": "${workspaceRoot}/../__build-output-${workspaceRootFolderName}/${generator}-${buildType}",
        "cmake.configureSettings": {
            "option_ENGINE_LIBRARY_AS_SHARED:BOOL": "YES"
        },
        "cmake.generator": "Ninja",
        "cmake.installPrefix": "${workspaceRoot}/../__install/${generator}-${buildType}",
        "C_Cpp.default.configurationProvider": "vector-of-bool.cmake-tools",
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
1. In **Solution Explorer** right-click the top `CMakeLists.txt` and select *Debug* and *Launch Settings->GunBox.exe(Install)* which will open `launch.vs.json`
2. In `launch.vs.json` add `"args": [ "--show-system-console", "--resolution: 640x480" ]` to `"configurations"`:

Example:
``` json
{
  "version": "0.2.1",
  "defaults": {},
  "configurations": [
    {
      "type": "default",
      "project": "CMakeLists.txt",
      "projectTarget": "GunBox.exe (Install)",
      "name": "GunBox.exe (Install)",
      "args": [ "--show-system-console", "--resolution: 640x480" ]
    }
  ]
}
```

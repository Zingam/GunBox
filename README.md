# GunBox

An exercise in SDL2 API programming...

## Notes
* Markdown (*.md)
  * Documentation uses the Markdown format
  * Recommended editor: Visual Studio Code's extension Markdown Preview Enhanced
* UML (*.puml)
  * UML diagrams use PlantUML syntax
  * Recomended editor: Visual Studio Code's extension: PlantUML
  
## Code Formatting
- Use **ClangFormat** to apply the format definitions from: **.clang-format**.
- Use `// clang-format on` and `clang-format off` Wherever appropriate to
prevent **ClangFormat** from changing the desired code formatting.

## Code Style

### Header Files

* Use *trailing return type syntax* in header files for function and method 
declarations.

### Header Files Include Oder

1. Related .cpp file header
2. Current project headers
3. Other projects' headers
4. Third party libraries' headers
5. System headers
6. C Standard Library headers
7. C++ Standard Library headers

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


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

include_guard ()

set (.Engine_SourceFiles
  "Sources/Application/ApplicationInfo.cpp"
  "Sources/Application/ApplicationInfo.hpp"
  "Sources/Application/CommandLineArgs.cpp"
  "Sources/Application/CommandLineArgs.hpp"
  "Sources/Application/CoreApplication.cpp"
  "Sources/Application/CoreApplication.hpp"
  "Sources/Application/CoreApplicationFactory.cpp"
  "Sources/Application/CoreApplicationFactory.hpp"
  "Sources/Application/Preferences.cpp"
  "Sources/Application/Preferences.hpp"
  "Sources/Common/Macros/Base.cpp"
  "Sources/Common/Macros/Base.hpp"
  "Sources/Common/Macros/Logging.cpp"
  "Sources/Common/Macros/Logging.hpp"
  "Sources/Common/implementedBy.hpp"
  "Sources/Common/implementedBy.inl"
  "Sources/Common/SimpleDelegate.hpp"
  "Sources/Common/SimpleDelegate.inl"
  "Sources/Common/Version.cpp"
  "Sources/Common/Version.hpp"
  "Sources/Common/Version.inl"
  "Sources/Logger/Logger.cpp"
  "Sources/Logger/Logger.hpp"
  "Sources/Renderer/Graphics/Constants/GpuPreferences.hpp"
  "Sources/Renderer/Graphics/OpenGL/GraphicsRenderer_OpenGL.cpp"
  "Sources/Renderer/Graphics/OpenGL/GraphicsRenderer_OpenGL.hpp"
  "Sources/Renderer/Graphics/OpenGL/OpenGL.cpp"
  "Sources/Renderer/Graphics/OpenGL/OpenGL.hpp"
  "Sources/Renderer/Graphics/OpenGL/OpenGL_ErrorChecking.cpp"
  "Sources/Renderer/Graphics/OpenGL/OpenGL_ErrorChecking.hpp"
  "Sources/Renderer/Graphics/OpenGL/OpenGL_ErrorChecking.inl"
  "Sources/Renderer/Graphics/OpenGL/OpenGL_ErrorChecking_FuncImpl.inl"
  "Sources/Renderer/Graphics/OpenGL/OpenGL_Loader.cpp"
  "Sources/Renderer/Graphics/OpenGL/OpenGL_Loader.hpp"
  "Sources/Renderer/Graphics/GraphicsRenderer_Interface.cpp"
  "Sources/Renderer/Graphics/GraphicsRenderer_Interface.hpp"
  "Sources/Renderer/Graphics/GraphicsRendererFactory.cpp"
  "Sources/Renderer/Graphics/GraphicsRendererFactory.hpp"
  "Sources/System/DeviceTypes/Graphics/GeometryTypes.cpp"
  "Sources/System/DeviceTypes/Graphics/GeometryTypes.hpp"
  "Sources/System/DeviceTypes/Graphics/RendererTypes.cpp"
  "Sources/System/DeviceTypes/Graphics/RendererTypes.hpp"
  "Sources/System/DeviceTypes/Input/GamepadTypes.cpp"
  "Sources/System/DeviceTypes/Input/GamepadTypes.hpp"
  "Sources/System/DeviceTypes/Input/KeyboardTypes.cpp"
  "Sources/System/DeviceTypes/Input/KeyboardTypes.hpp"
  "Sources/System/EventProcessing/EventHandlers/Input/GamepadEventHandler.cpp"
  "Sources/System/EventProcessing/EventHandlers/Input/GamepadEventHandler.hpp"
  "Sources/System/EventProcessing/EventHandlers/Input/KeyboardEventHandler.cpp"
  "Sources/System/EventProcessing/EventHandlers/Input/KeyboardEventHandler.hpp"
  "Sources/System/EventProcessing/EventHandlers/System/QuitEventHandler.cpp"
  "Sources/System/EventProcessing/EventHandlers/System/QuitEventHandler.hpp"
  "Sources/System/EventProcessing/EventHandlers/EventHandler.cpp"
  "Sources/System/EventProcessing/EventHandlers/EventHandler.hpp"
  "Sources/System/EventProcessing/InputDeviceStates/GamepadState.cpp"
  "Sources/System/EventProcessing/InputDeviceStates/GamepadState.hpp"
  "Sources/System/EventProcessing/InputDeviceStates/GamepadStateAccessor.cpp"
  "Sources/System/EventProcessing/InputDeviceStates/GamepadStateAccessor.hpp"
  "Sources/System/EventProcessing/InputDeviceStates/GamepadStateAccessor.inl"
  "Sources/System/EventProcessing/InputDeviceStates/KeyboardState.cpp"
  "Sources/System/EventProcessing/InputDeviceStates/KeyboardState.hpp"
  "Sources/System/EventProcessing/InputDeviceStates/KeyboardStateAccessor.cpp"
  "Sources/System/EventProcessing/InputDeviceStates/KeyboardStateAccessor.hpp"
  "Sources/System/EventProcessing/InputDeviceStates/KeyboardStateAccessor.inl"
  "Sources/System/EventProcessing/InputEventCallbacks_Interface.cpp"
  "Sources/System/EventProcessing/InputEventCallbacks_Interface.hpp"
  "Sources/System/EventProcessing/InputEventProcessor.cpp"
  "Sources/System/EventProcessing/InputEventProcessor.hpp"
  "Sources/System/EventProcessing/InputEventProcessor.inl"
  "Sources/System/EventProcessing/InputEventProcessorAccessor.cpp"
  "Sources/System/EventProcessing/InputEventProcessorAccessor.hpp"
  "Sources/System/EventProcessing/InputEventProcessorAccessor.inl"
  "Sources/System/EventProcessing/SystemEventCallbacks_Interface.cpp"
  "Sources/System/EventProcessing/SystemEventCallbacks_Interface.hpp"
  "Sources/System/EventProcessing/SystemEventProcessor.cpp"
  "Sources/System/EventProcessing/SystemEventProcessor.hpp"
  "Sources/System/EventProcessing/SystemEventProcessorAccessor.cpp"
  "Sources/System/EventProcessing/SystemEventProcessorAccessor.hpp"
  "Sources/System/EventProcessing/SystemEventProcessorAccessor.inl"
  "Sources/System/GUI/MessageBox.cpp"
  "Sources/System/GUI/MessageBox.hpp"
  "Sources/System/GUI/Monitor.cpp"
  "Sources/System/GUI/Monitor.hpp"
  "Sources/System/GUI/Window.cpp"
  "Sources/System/GUI/Window.hpp"
  "Sources/System/HostPlatform/FileSystem.cpp"
  "Sources/System/HostPlatform/FileSystem.hpp"
  "Sources/System/HostPlatform/OpenGLDevice.cpp"
  "Sources/System/HostPlatform/OpenGLDevice.hpp"
  "Sources/System/HostPlatform/OpenGLDevice.inl"
  "Sources/System/HostPlatform/SubSystems.cpp"
  "Sources/System/HostPlatform/SubSystems.hpp"
  "Sources/System/HostPlatform/SystemConsole.cpp"
  "Sources/System/HostPlatform/SystemConsole.hpp"
  "Sources/System/HostPlatform/SystemInfo.cpp"
  "Sources/System/HostPlatform/SystemInfo.hpp"
  "Sources/System/Platforms/Common/CompilerInfo.cpp"
  "Sources/System/Platforms/Common/CompilerInfo.hpp"
  $<$<PLATFORM_ID:Linux>:Sources/System/Platforms/Linux/HostPlatform/SystemConsole_Linux.cpp>
  $<$<PLATFORM_ID:Linux>:Sources/System/Platforms/Linux/HostPlatform/SystemConsole_Linux.hpp>
  $<$<PLATFORM_ID:Linux>:Sources/System/Platforms/Linux/HostPlatform/SystemInfo_Linux.cpp>
  $<$<PLATFORM_ID:Linux>:Sources/System/Platforms/Linux/HostPlatform/SystemInfo_Linux.hpp>
  "Sources/System/Platforms/SDL2/HostPlatform/FileSystem_SDL2.cpp"
  "Sources/System/Platforms/SDL2/HostPlatform/FileSystem_SDL2.hpp"
  "Sources/System/Platforms/SDL2/HostPlatform/OpenGLDevice_SDL2.cpp"
  "Sources/System/Platforms/SDL2/HostPlatform/OpenGLDevice_SDL2.hpp"
  "Sources/System/Platforms/SDL2/HostPlatform/SubSystems_SDL2.cpp"
  "Sources/System/Platforms/SDL2/HostPlatform/SubSystems_SDL2.hpp"
  "Sources/System/Platforms/SDL2/Gamepad_SDL2.cpp"
  "Sources/System/Platforms/SDL2/Gamepad_SDL2.hpp"
  "Sources/System/Platforms/SDL2/Gamepad_SDL2.inl"
  "Sources/System/Platforms/SDL2/Keyboard_SDL2.cpp"
  "Sources/System/Platforms/SDL2/Keyboard_SDL2.hpp"
  "Sources/System/Platforms/SDL2/Keyboard_SDL2.inl"
  "Sources/System/Platforms/SDL2/Main_SDL2.cpp"
  "Sources/System/Platforms/SDL2/Main_SDL2.hpp"
  "Sources/System/Platforms/SDL2/SDL2_ErrorChecking.cpp"
  "Sources/System/Platforms/SDL2/SDL2_ErrorChecking.hpp"
  $<$<PLATFORM_ID:Windows>:Sources/System/Platforms/Windows/HostPlatform/SystemConsole_Windows.cpp>
  $<$<PLATFORM_ID:Windows>:Sources/System/Platforms/Windows/HostPlatform/SystemConsole_Windows.hpp>
  $<$<PLATFORM_ID:Windows>:Sources/System/Platforms/Windows/HostPlatform/SystemInfo_Windows.cpp>
  $<$<PLATFORM_ID:Windows>:Sources/System/Platforms/Windows/HostPlatform/SystemInfo_Windows.hpp>
  "Sources/System/Platforms/FileSystem_Implementation.hpp"
  "Sources/System/Platforms/OpenGLDevice_Implementation.hpp"
  "Sources/System/Platforms/SubSystems_Implementation.hpp"
  "Sources/System/Platforms/SystemConsole_Implementation.hpp"
  "Sources/System/Platforms/SystemInfo_Implementation.hpp"
  "Sources/System/HostPlatform.cpp"
  "Sources/System/HostPlatform.hpp"
  "Sources/System/HostPlatform.inl"
  "Sources/System/EventProcessor.cpp"
  "Sources/System/EventProcessor.hpp"
  "Sources/System/EventProcessor.inl"
  "Sources/System/Main.cpp"
  "Sources/System/Main.hpp"
)

set (.main_SourceFiles
  "Sources/main.cpp"
  "Sources/main.hpp"
)

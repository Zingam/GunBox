include_guard ()

set (.Engine_SourceFiles
  "Sources/Application/ApplicationInfo.cpp"
  "Sources/Application/ApplicationInfo.hpp"
  "Sources/Application/ApplicationInfo.inl"
  "Sources/Application/CommandLineArgs.cpp"
  "Sources/Application/CommandLineArgs.hpp"
  "Sources/Application/CoreApplication.cpp"
  "Sources/Application/CoreApplication.hpp"
  "Sources/Application/CoreApplication.inl"
  "Sources/Application/CoreApplicationFactory.cpp"
  "Sources/Application/CoreApplicationFactory.hpp"
  "Sources/Application/Preferences.cpp"
  "Sources/Application/Preferences.hpp"
  "Sources/Application/Preferences.inl"
  "Sources/Common/Macros/Base.cpp"
  "Sources/Common/Macros/Base.hpp"
  "Sources/Common/Macros/Logging.cpp"
  "Sources/Common/Macros/Logging.hpp"
  "Sources/Common/implementedBy.hpp"
  "Sources/Common/implementedBy.inl"
  "Sources/Common/SimpleDelegate.hpp"
  "Sources/Common/SimpleDelegate.inl"
  "Sources/Renderer/Graphics/Constants/GpuPreferences.hpp"
  "Sources/Renderer/Graphics/OpenGL/GraphicsRenderer_OpenGL.cpp"
  "Sources/Renderer/Graphics/OpenGL/GraphicsRenderer_OpenGL.hpp"
  "Sources/Renderer/Graphics/OpenGL/OpenGL.cpp"
  "Sources/Renderer/Graphics/OpenGL/OpenGL.hpp"
  "Sources/Renderer/Graphics/OpenGL/OpenGL_ErrorChecking.cpp"
  "Sources/Renderer/Graphics/OpenGL/OpenGL_ErrorChecking.hpp"
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
  "Sources/System/DeviceTypes/IO/GamepadTypes.cpp"
  "Sources/System/DeviceTypes/IO/GamepadTypes.hpp"
  "Sources/System/DeviceTypes/IO/KeyboardTypes.cpp"
  "Sources/System/DeviceTypes/IO/KeyboardTypes.hpp"
  "Sources/System/EventProcessing/EventHandlers/Input/GamepadEventHandler.cpp"
  "Sources/System/EventProcessing/EventHandlers/Input/GamepadEventHandler.hpp"
  "Sources/System/EventProcessing/EventHandlers/Input/KeyboardEventHandler.cpp"
  "Sources/System/EventProcessing/EventHandlers/Input/KeyboardEventHandler.hpp"
  "Sources/System/EventProcessing/EventHandlers/System/QuitEventHandler.cpp"
  "Sources/System/EventProcessing/EventHandlers/System/QuitEventHandler.hpp"
  "Sources/System/EventProcessing/EventHandlers/EventHandler.cpp"
  "Sources/System/EventProcessing/EventHandlers/EventHandler.hpp"
  "Sources/System/EventProcessing/InputEventCallbacks.cpp"
  "Sources/System/EventProcessing/InputEventCallbacks.hpp"
  "Sources/System/EventProcessing/InputEventProcessor.cpp"
  "Sources/System/EventProcessing/InputEventProcessor.hpp"
  "Sources/System/EventProcessing/InputEventProcessorAccessor.cpp"
  "Sources/System/EventProcessing/InputEventProcessorAccessor.hpp"
  "Sources/System/EventProcessing/InputEventProcessorAccessor.inl"
  "Sources/System/EventProcessing/SystemEventCallbacks.cpp"
  "Sources/System/EventProcessing/SystemEventCallbacks.hpp"
  "Sources/System/EventProcessing/SystemEventProcessor.cpp"
  "Sources/System/EventProcessing/SystemEventProcessor.hpp"
  "Sources/System/EventProcessing/SystemEventProcessorAccessor.cpp"
  "Sources/System/EventProcessing/SystemEventProcessorAccessor.hpp"
  "Sources/System/EventProcessing/SystemEventProcessorAccessor.inl"
  "Sources/System/HostPlatform/OpenGLDevice.cpp"
  "Sources/System/HostPlatform/OpenGLDevice.hpp"
  "Sources/System/HostPlatform/OpenGLDevice.inl"
  "Sources/System/HostPlatform/SubSystems.cpp"
  "Sources/System/HostPlatform/SubSystems.hpp"
  "Sources/System/HostPlatform/SubSystems.inl"
  "Sources/System/HostPlatform/SystemConsole.cpp"
  "Sources/System/HostPlatform/SystemConsole.hpp"
  "Sources/System/HostPlatform/SystemConsole.inl"
  $<$<PLATFORM_ID:Linux>:Sources/System/Platforms/Linux/HostPlatform/SystemConsole_Linux.cpp>
  $<$<PLATFORM_ID:Linux>:Sources/System/Platforms/Linux/HostPlatform/SystemConsole_Linux.hpp>
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
  "Sources/System/Platforms/SubSystems_Implementation.hpp"
  "Sources/System/Platforms/SystemConsole_Implementation.hpp"
  "Sources/System/HostPlatform.cpp"
  "Sources/System/HostPlatform.hpp"
  "Sources/System/HostPlatform.inl"
  "Sources/System/EventProcessor.cpp"
  "Sources/System/EventProcessor.hpp"
  "Sources/System/EventProcessor.inl"
  "Sources/System/Monitor.cpp"
  "Sources/System/Monitor.hpp"
  "Sources/System/Window.cpp"
  "Sources/System/Window.hpp"
)

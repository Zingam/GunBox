include_guard ()

set (.Engine_SourceFiles
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
  "Sources/Application/ProductInfo.cpp"
  "Sources/Application/ProductInfo.hpp"
  "Sources/Application/ProductInfo.inl"
  "Sources/Common/Macros/Base.cpp"
  "Sources/Common/Macros/Base.hpp"
  "Sources/Common/Macros/SDL2_ErrorChecking.cpp"
  "Sources/Common/Macros/SDL2_ErrorChecking.hpp"
  "Sources/Renderer/OpenGL/OpenGL.cpp"
  "Sources/Renderer/OpenGL/OpenGL.hpp"
  "Sources/Renderer/OpenGL/OpenGL_ErrorChecking.cpp"
  "Sources/Renderer/OpenGL/OpenGL_ErrorChecking.hpp"
  "Sources/Renderer/OpenGL/OpenGL_Loader.cpp"
  "Sources/Renderer/OpenGL/OpenGL_Loader.hpp"
  "Sources/Renderer/Renderer.cpp"
  "Sources/Renderer/Renderer.hpp"
  "Sources/Renderer/RendererBase.cpp"
  "Sources/Renderer/RendererBase.hpp"
  "Sources/System/EventHandlers/Application/Quit.cpp"
  "Sources/System/EventHandlers/Application/Quit.hpp"
  "Sources/System/EventHandlers/Controller/ControllerDeviceAdded.cpp"
  "Sources/System/EventHandlers/Controller/ControllerDeviceAdded.hpp"
  "Sources/System/EventHandlers/Controller/ControllerDeviceRemoved.cpp"
  "Sources/System/EventHandlers/Controller/ControllerDeviceRemoved.hpp"
  "Sources/System/EventHandlers/EventHandler.cpp"
  "Sources/System/EventHandlers/EventHandler.hpp"
  $<$<PLATFORM_ID:Linux>:Sources/System/Platforms/Linux/HostPlatform_Linux.cpp>
  $<$<PLATFORM_ID:Linux>:Sources/System/Platforms/Linux/HostPlatform_Linux.hpp>
  $<$<PLATFORM_ID:Windows>:Sources/System/Platforms/Windows/HostPlatform_Windows.cpp>
  $<$<PLATFORM_ID:Windows>:Sources/System/Platforms/Windows/HostPlatform_Windows.hpp>
  "Sources/System/Platforms/HostPlatform_Implementation.hpp"
  "Sources/System/EventProcessor.cpp"
  "Sources/System/EventProcessor.hpp"
  "Sources/System/EventProcessor.inl"
  "Sources/System/Geometry.cpp"
  "Sources/System/Geometry.hpp"
  "Sources/System/HostPlatform.cpp"
  "Sources/System/HostPlatform.hpp"
  "Sources/System/HostPlatform.inl"
  "Sources/System/InputProcessor.cpp"
  "Sources/System/InputProcessor.hpp"
  "Sources/System/Monitor.cpp"
  "Sources/System/Monitor.hpp"
  "Sources/System/Window.cpp"
  "Sources/System/Window.hpp"
)

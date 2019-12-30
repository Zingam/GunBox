#glad2 Loader

To generate the necessary source files make the following settings:

1. **Generator:**
    - C/C++
2. **APIs:**
    - **gl**: Version 4.6
      - Core
      - Common
    - **gles2**:  Version 3.2
    - **vulkan**: Version 1.1
3. **Extensions:**
    - *Required extensions:*
        - VK_EXT_debug_utils
        - VK_KHR_surface
        - VK_KHR_swapchain
    - *Optional extensions:*
        - VK_KHR_android_surface
        - VK_KHR_win32_surface
        - VK_KHR_xcb_surface
4. **Options:**
-- none selected --
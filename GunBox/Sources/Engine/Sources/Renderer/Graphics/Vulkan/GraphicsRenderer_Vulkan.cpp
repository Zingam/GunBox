// Self
#include "GraphicsRenderer_Vulkan.hpp"

// Project headers - Application
#include "Application/ModuleInfo.hpp"
// Project headers - Common
#include "Common/Macros/Logging.hpp"
// Project headers - Logger
#include "Logger/LogAPI.hpp"
// Project headers - Renderer
#include "Renderer/Graphics/Vulkan/Objects/Instance.hpp"
// Project headers - System
#include "System/HostPlatform.hpp"

// C Standard Library
#include <cassert>

NAMESPACE_BEGIN(Renderer::Graphics)

////////////////////////////////////////////////////////////////////////////////
// Constructors & Destructors
////////////////////////////////////////////////////////////////////////////////

GraphicsRenderer_Vulkan::GraphicsRenderer_Vulkan(
  Application::CoreApplication const& coreApplication,
  Application::Preferences& preferences,
  System::HostPlatform& hostPlatform)
  : GraphicsRenderer_Interface{ coreApplication, preferences, hostPlatform }
{}

GraphicsRenderer_Vulkan::~GraphicsRenderer_Vulkan() {}

////////////////////////////////////////////////////////////////////////////////
// Methods
////////////////////////////////////////////////////////////////////////////////

bool
GraphicsRenderer_Vulkan::SetupRenderingPipeLine()
{
  return false;
}

////////////////////////////////////////////////////////////////////////////////
// Virtual methods
////////////////////////////////////////////////////////////////////////////////

void
GraphicsRenderer_Vulkan::Finalize()
{
  hostPlatform.GPUDevice_Vulkan().Finalize();
  GraphicsRenderer_Interface::Finalize();
}

bool
GraphicsRenderer_Vulkan::Initialize()
{
  assert(!isInitialized && "Renderer is already initialized!");

  using namespace std::string_literals;

  ELogI("Initializing: Vulkan Renderer"s);

  // Initialize the host platform Vulkan device object
  auto& GPUDevice_Vulkan = hostPlatform.GPUDevice_Vulkan();
  auto isSuccess = GPUDevice_Vulkan.Initialize();
  if (isSuccess) {
    if (IsFalse(GreaterOrEqual(
          *GPUDevice_Vulkan.InstanceVersion(),
          Instance::MinimalRequiredVersion()))) {
      ELogVE("Failed to create Vulkan surface"s);

      return isInitialized;
    }
  }

  // Create window
  isSuccess = GraphicsRenderer_Interface::Initialize();
  if (!isSuccess) {
    return isInitialized;
  }

  // Attaching a system window also enumerates the surface creation extensions
  isSuccess = GPUDevice_Vulkan.EnumerateInstanceExtensions();
  if (!isSuccess) {
    ELogVE("No Vulkan surfrace creation extensions are available!"s);

    return isInitialized;
  }

  // Vulkan instance
  instance = std::make_unique<Instance>(*this);
  // Vulkan surface
  auto surface = GPUDevice_Vulkan.CreateSurface(*instance, *this->window);
  if (IsNull(surface)) {
    ELogVE("Failed to create Vulkan surface"s);

    return isInitialized;
  }
  // Vulkan surface
  auto surface1 = GPUDevice_Vulkan.CreateSurface(*instance, *this->window);
  if (IsNull(surface1)) {
    ELogVE("Failed to create Vulkan surface"s);

    return isInitialized;
  }
  // Vulkan physical device
  instance->EnumeratePhysicalDevices();
  instance->ListPhysicalDevices();

#if defined(PREFER_INTEGRATED_GPU)
  auto const physicalDeviceType = PhysicalDevice::Type_t::GPU_Integrated;
#else
  auto const physicalDeviceType = PhysicalDevice::Type_t::GPU_Discrete;
#endif
  instance->SelectPhysicalDevice(physicalDeviceType);

  if (!instance->SelectedPhysicalDevice().has_value()) {
    ELogVE("Failed to select Vulkan physical device."s);
    return isInitialized;
  }

  auto const& physicalDevice{ instance->SelectedPhysicalDevice()->get() };
  // TODO: Check if the surface is properly initialized
  EnumerateSurfaceProperties(*surface, physicalDevice);
  auto const queueFamilyResult{ physicalDevice.FindGraphicsQueueFamily() };
  optional_ref<QueueFamily const> queueFamily;
  if (auto const queueFamily_Ptr =
        std::get_if<QueueFamily_Ref_t>(&queueFamilyResult);
      IsInstance(queueFamily_Ptr)) {
    queueFamily = *queueFamily_Ptr;
  } else {
    [[maybe_unused]] auto capabilityNotAvailableError =
      get<std::string>(queueFamilyResult);
    ELogVE(capabilityNotAvailableError);
    return isInitialized;
  }

  // Check if the device can present to the surface
  VkBool32 isSupported = VK_FALSE;
  if (
    #pragma warning(suppress: 26812) // Allow unscoped enum
    VK_SUCCESS != (vkGetPhysicalDeviceSurfaceSupportKHR(
                    physicalDevice.Get(),
                    queueFamily->get().Index(),
                    surface->Get(),
                    &isSupported))) {
    return isInitialized;
  }

  [[maybe_unused]] auto const& caps1 = get(queueFamily).Capabilities();

  [[maybe_unused]] auto const& caps = queueFamily->get().Capabilities();
  // clang-format off
  ELogI("      + Selected queue family:"s);
  ELogI("          Index:           "s, queueFamily->get().Index());
  ELogI("          Capabilities:"s);
  ELogI("            Compute:       "s, std::boolalpha, caps.Compute);
  ELogI("            Graphics:      "s, std::boolalpha, caps.Graphics);
  ELogI("            Protected:     "s, std::boolalpha, caps.ProtectedMemory);
  ELogI("            SparseBinding: "s, std::boolalpha, caps.SparseBinding);
  ELogI("            Transfer:      "s, std::boolalpha, caps.Transfer);
  // clang-format on

  auto computeQueue = physicalDevice.FindComputeQueueFamily();
  auto transferQueue = physicalDevice.FindTransferQueueFamily();

  isInitialized = true;

  return isInitialized;
}

void
GraphicsRenderer_Vulkan::Render()
{}

NAMESPACE_END(Renderer::Graphics)

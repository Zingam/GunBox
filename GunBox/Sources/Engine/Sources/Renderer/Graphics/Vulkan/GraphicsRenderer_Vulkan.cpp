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

  // Create window
  auto isSuccess = GraphicsRenderer_Interface::Initialize();
  if (isSuccess) {
    auto& GPUDevice_Vulkan = hostPlatform.GPUDevice_Vulkan();
    isSuccess = GPUDevice_Vulkan.Initialize(*window);
    if (isSuccess) {
      instance = std::make_unique<Instance>(*this);
      instance->EnumeratePhysicalDevices();
      ListPhysicalDevices(*instance);

#if defined(PREFER_INTEGRATED_GPU)
      auto const physicalDeviceType = PhysicalDevice::Type_t::GPU_Integrated;
#else
      auto const physicalDeviceType = PhysicalDevice::Type_t::GPU_Discrete;
#endif
      auto const& physicalDevice{ instance->SelectPhysicalDevice(
        physicalDeviceType) };

      ELogI("Vulkan renderer:");
      ELogI("  - Selected physical device:");
      ELogI("      Name: ", physicalDevice.Name());
      ELogI("      Type: ", physicalDevice.TypeAsString());

      auto const queueFamilyResult{ physicalDevice.FindGraphicsQueueFamily() };
      std::unique_ptr<QueueFamily const> queueFamily_Ptr;
      std::string capabilityNotAvailableError;

      if (auto const queueFamilyData =
            std::any_cast<std::reference_wrapper<QueueFamily const>>(
              &queueFamilyResult);
          IsInstance(queueFamilyData)) {
        queueFamily_Ptr.reset(&queueFamilyData->get());
      } else if (auto const errorData =
                   std::any_cast<std::string>(&queueFamilyResult);
                 IsInstance(errorData)) {
        capabilityNotAvailableError = *errorData;
      } else {
        assert(false && "Unknown any_cast<T>() result!");
      }

      // If everything is OK
      if (IsInstance(queueFamily_Ptr)) {
        auto const& queueFamily{ *queueFamily_Ptr.release() };

        [[maybe_unused]] auto const& caps = queueFamily.Capabilities();

        ELogI("    - Selected queue family:");
        ELogI("        Index:           ", queueFamily.Index());
        ELogI("        Capabilities:");
        ELogI("          Compute:       ", std::boolalpha, caps.Compute);
        ELogI("          Graphics:      ", std::boolalpha, caps.Graphics);
        ELogI("          Protected:     ", std::boolalpha, caps.ProtectedMemory);
        ELogI("          SparseBinding: ", std::boolalpha, caps.SparseBinding);
        ELogI("          Transfer:      ", std::boolalpha, caps.Transfer);

      } else if (!capabilityNotAvailableError.empty()) {
        reLogE(capabilityNotAvailableError);
      } else {
        assert(false && "Unknown any_cast<T>() result!");
      }
    } else {
      reLogE("No Vulkan surfrace creation extensions are available!");

      isInitialized = false;
    }
  } else {
    isInitialized = false;
  }

  return isInitialized;
}

void
GraphicsRenderer_Vulkan::Render()
{}

NAMESPACE_END(Renderer::Graphics)

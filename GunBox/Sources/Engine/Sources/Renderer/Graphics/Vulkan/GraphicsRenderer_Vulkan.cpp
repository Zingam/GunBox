// Self
#include "GraphicsRenderer_Vulkan.hpp"

// Project headers - Application
#include "Application/ModuleInfo.hpp"
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
  Application::ApplicationInfo const& applicationInfo,
  Application::EngineInfo const& engineInfo,
  Application::Preferences& preferences,
  System::HostPlatform& hostPlatform)
  : GraphicsRenderer_Interface{ applicationInfo,
                                engineInfo,
                                preferences,
                                hostPlatform }
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
      auto& physicalDevice =
        instance->SelectPhysicalDevice(PhysicalDevice::Type_t::GPU_Integrated);
      auto result = physicalDevice.FindGraphicsQueueFamily();

      reLogI("  Selected physical device:");
      reLogI("    Name: ", physicalDevice.Name());
      reLogI("    Type: ", physicalDevice.TypeAsString());

      std::unique_ptr<QueueFamily const> queueFamily_Ptr;
      std::string capabilityNotAvailableError;

      if (auto data =
            std::any_cast<std::reference_wrapper<QueueFamily const>>(&result);
          IsInstance(data)) {
        queueFamily_Ptr.reset(&data->get());
      } else if (auto data = std::any_cast<std::string>(&result);
                 IsInstance(data)) {
        capabilityNotAvailableError = *data;
      } else {
        assert(false && "Unknown any_cast<T>() result!");
      }

      // If everything is OK
      if (capabilityNotAvailableError.empty()) {
        auto const& queueFamily = *queueFamily_Ptr.release();
        auto& caps = queueFamily.Capabilities();

        reLogI("    Queue family selected at index:");
        reLogI("      Index:           ", queueFamily.Index());
        reLogI("      Capabilities:");
        reLogI("        Compute:       ", std::boolalpha, caps.Compute);
        reLogI("        Graphics:      ", std::boolalpha, caps.Graphics);
        reLogI("        Protected:     ", std::boolalpha, caps.ProtectedMemory);
        reLogI("        SparseBinding: ", std::boolalpha, caps.SparseBinding);
        reLogI("        Transfer:      ", std::boolalpha, caps.Transfer);
      }

      // To prevent crash on destructor call
      if (IsInstance(queueFamily_Ptr)) {
        queueFamily_Ptr.release();
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

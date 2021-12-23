// Self
#include "Instance.hpp"
////////////////////////////////////////////////////////////////////////////////

// Project headers - Application
#include "Application/CommandLineArgs.hpp"
#include "Application/ModuleInfo.hpp"
// Project headers - Common
#include "Common/Macros/Logging.hpp"
// Project headers - Renderer
#include "Renderer/Graphics/GraphicsRenderer_Interface.hpp"
#include "Renderer/Graphics/GraphicsRenderer_InterfaceAccessor.hpp"
#include "Renderer/Graphics/Vulkan/Objects/Utilities/PropertyEnumerators.hpp"
#include "Renderer/Graphics/Vulkan/Objects/Utilities/Utilities.hpp"

// Project headers - System
#include "System/HostPlatform.hpp"

// C Standard Library
#include <cstdint>
#include <cstring>
// C++ Standard Library
#include <type_traits>

////////////////////////////////////////////////////////////////////////////////
// Macros (file scope)
////////////////////////////////////////////////////////////////////////////////

#if !defined(GRIProperty)
/// <summary>
/// Gets a property of <c>GraphicsRenderer_Interface.</c>
/// </summary>
#  define GRIProperty(PropertyName)                                            \
    GraphicsRenderer_InterfaceAccessor::PropertyName(graphicsRenderer)
#else
#  error GetGRIProp is already defined!
#endif

////////////////////////////////////////////////////////////////////////////////
// Helper functions (file scope)
////////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Compares two name strings for equality.
/// </summary>
template<
  typename LHS,
  typename RHS,
  typename = std::enable_if_t<
    (std::is_same<const char*, LHS>::value ||
     std::is_same<const char[], LHS>::value) &&
    (std::is_same<const char*, RHS>::value ||
     std::is_same<const char[], RHS>::value)>>
bool
AreNamesEqual(LHS lhs, RHS rhs)
{
  return (0 == strcmp(lhs, rhs));
}

////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(Renderer::Graphics)

////////////////////////////////////////////////////////////////////////////////
// Constructors & Destructors
////////////////////////////////////////////////////////////////////////////////

Instance::Instance(GraphicsRenderer_Interface const& graphicsRenderer)
  : graphicsRenderer{ graphicsRenderer }
{
  this->Create();
}

Instance::~Instance()
{
  if (isValidationEnabled) {
    DebugMessangerDestroy();
  }

  surface.reset();

  // Be carefull to release all Vulkan objects before destroying the Vulkan
  // instance
  vkDestroyInstance(instance, nullptr);
  instance = VK_NULL_HANDLE;
}

////////////////////////////////////////////////////////////////////////////////
// Properties
////////////////////////////////////////////////////////////////////////////////
VkInstance
Instance::Get() const
{
  return this->instance;
}

std::vector<PhysicalDevice>&
Instance::PhysicalDevices()
{
  return physicalDevices;
}

optional_ref<PhysicalDevice const>
Instance::SelectedPhysicalDevice() const
{
  return selectedPhysicalDevice;
}

Version
Instance::MinimalRequiredVersion()
{
  return Version{ { 1, 2, 0, 0 } };
};

////////////////////////////////////////////////////////////////////////////////
// Properties
////////////////////////////////////////////////////////////////////////////////

void
Instance::Create()
{
  // Initialize glad
  auto& vulkanDevice = GRIProperty(HostPlatform).GPUDevice_Vulkan();
  // Load the global level function pointers
  auto isSuccess =
    LoadVulkanGlobalFunctionPointers(vulkanDevice.GetInstanceProcAddress());
  if (!isSuccess) {
    assert(false && "Failed to load Vulkan global level function pointers!");
  }

  // Create Vulkan instance
  auto const& applicationInfo = GRIProperty(ApplicationInfo);
  auto const& engineInfo = GRIProperty(EngineInfo);

  VkApplicationInfo vulkanApplicationInfo{
    .sType = VK_STRUCTURE_TYPE_APPLICATION_INFO,
    .pNext = nullptr,
    .pApplicationName = applicationInfo.Title().c_str(),
    .applicationVersion = applicationInfo.GetVersion().AsNumber(),
    .pEngineName = engineInfo.Title().c_str(),
    .engineVersion = engineInfo.GetVersion().AsNumber(),
    .apiVersion = VK_API_VERSION_1_1,
  };

  assert(
    GreaterOrEqual(
      Instance::MinimalRequiredVersion(),
      Version{ { VK_VERSION_MAJOR(vulkanApplicationInfo.apiVersion),
                 VK_VERSION_MINOR(vulkanApplicationInfo.apiVersion),
                 VK_VERSION_PATCH(vulkanApplicationInfo.apiVersion),
                 0 } }) &&
    "The minimal required version and the requested version do not match");

  auto const& layersToEnable = GetLayerNamesToEnable();
  isValidationEnabled = ((layersToEnable.size() > 0ull) ? true : false);
  auto const& extensionNamesToEnable =
    GetExtensionNamesToEnable(isValidationEnabled);

  // Check if enough extensions are available (the surface creation extensions
  // are the minimum requirement)
  if (0ULL < extensionNamesToEnable.size()) {
    VkInstanceCreateInfo instanceCreateInfo{
      .sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
      .pNext = nullptr,
      .flags = 0u,
      .pApplicationInfo = &vulkanApplicationInfo,
      .enabledLayerCount = static_cast<std::uint32_t>(layersToEnable.size()),
      .ppEnabledLayerNames = layersToEnable.data(),
      .enabledExtensionCount =
        static_cast<std::uint32_t>(extensionNamesToEnable.size()),
      .ppEnabledExtensionNames = extensionNamesToEnable.data(),
    };

    #pragma warning(suppress: 26812) // Allow unscoped enum
    if (vkCallSuccess(
          vkCreateInstance(&instanceCreateInfo, nullptr, &instance))) {

      auto isSuccess = LoadVulkanInstanceFunctionPointers(
        vulkanDevice.GetInstanceProcAddress(), instance);
      if (!isSuccess) {
        assert(false && "Failed to load Vulkan instance function pointers!");
      }

      if (isValidationEnabled) {
        DebugMessangerCreate();
      }
    }

    assert(IsInstance(instance) && "Vulkan instance is not initialized!");
  }
}

void
Instance::DebugMessangerCreate()
{
  constexpr auto MessageSeverityFlags = []() {
    VkDebugUtilsMessageSeverityFlagsEXT messageSeverityFlags = 0u;

#if VULKAN_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_INFO
    messageSeverityFlags |= VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT;
    messageSeverityFlags |= VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT;
#endif
    messageSeverityFlags |= VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT;
    messageSeverityFlags |= VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;

    return messageSeverityFlags;
  };
  constexpr auto MessageTypeFlags = []() {
    VkDebugUtilsMessageTypeFlagsEXT messageTypeFlags = 0u;

    messageTypeFlags |= VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT;
    messageTypeFlags |= VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT;
    messageTypeFlags |= VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;

    return messageTypeFlags;
  };

  VkDebugUtilsMessengerCreateInfoEXT createInfo{};
  createInfo.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
  createInfo.pNext = nullptr;
  createInfo.flags = 0u;
  createInfo.messageSeverity = MessageSeverityFlags();
  createInfo.messageType = MessageTypeFlags();
  createInfo.pfnUserCallback = DebugMessangerCallback;
  createInfo.pUserData = nullptr;

  if (vkCallFail(vkCreateDebugUtilsMessengerEXT(
        instance, &createInfo, nullptr, &debugMessenger))) {
    ELogE("Failed to create DebugMessenger!");
  }

#if DEBUG_UTILS_MESSANGER_CALLBACK_TEST
  using namespace std::string_literals;

  std::vector<std::pair<VkDebugUtilsMessageSeverityFlagBitsEXT, std::string>>
    messageSeverityFlags{
      { VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT, "Verbose"s },
      { VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT, "Info"s },
      { VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT, "Warning"s },
      { VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT, "Error"s }
    };
  std::vector<std::pair<VkDebugUtilsMessageTypeFlagBitsEXT, std::string>>
    messageTypeFlags{
      { VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT, "General"s },
      { VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT, "Validation"s },
      { VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT, "Performance"s }
    };
  for (auto const messageSeverity : messageSeverityFlags) {
    for (auto const messageType : messageTypeFlags) {
      std::string message{ "Callback Test: severity - "s +
                           messageSeverity.second + ", type - "s +
                           messageType.second };

      VkDebugUtilsMessengerCallbackDataEXT callbackData{};
      callbackData.sType =
        VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CALLBACK_DATA_EXT;
      callbackData.pNext = nullptr;
      callbackData.flags = 0u;
      callbackData.pMessageIdName = "Debug Message";
      callbackData.messageIdNumber = 1;
      callbackData.pMessage = message.c_str();
      callbackData.queueLabelCount = 0;
      callbackData.pQueueLabels = nullptr;
      callbackData.cmdBufLabelCount = 0;
      callbackData.pCmdBufLabels = nullptr;
      callbackData.objectCount = 0;
      callbackData.pObjects = nullptr;

      vkSubmitDebugUtilsMessageEXT(
        instance, messageSeverity.first, messageType.first, &callbackData);
    }
  }
#endif // defined(DEBUG_MESSANGER_TEST)
}

void
Instance::DebugMessangerDestroy()
{
  if (IsInstance(instance) && IsInstance(debugMessenger)) {
    vkDestroyDebugUtilsMessengerEXT(instance, debugMessenger, nullptr);
  }
}

std::vector<char const*>
Instance::GetExtensionNamesToEnable(bool isValidationEnabled) const
{
  auto& vulkanDevice = GRIProperty(HostPlatform).GPUDevice_Vulkan();
  auto const& surfaceExtenionNames =
    vulkanDevice.SurfaceCreationExtensionNames();

  std::vector<char const*> requestedExtensionNamesToEnable;
  // Check if surface extensions are available:
  //   VK_KHR_surface
  //   VK_KHR_<platform>_surface
  // which are the required minimum for the graphics renderer
  if (2ULL <= surfaceExtenionNames.size()) {
    for (auto extensionName : surfaceExtenionNames) {
      requestedExtensionNamesToEnable.push_back(extensionName);
    }

    if (isValidationEnabled) {
      auto const& debugExtensionNames = vulkanDevice.DebugExtensionNames();
      for (auto extensionName : debugExtensionNames) {
        requestedExtensionNamesToEnable.push_back(extensionName);
      }
    }

    auto availableExtensions = EnumerateInstanceExtensions();

    using namespace std::string_literals;

    ELogI("      + Extensions to enable:"s);
    std::vector<char const*> extensionNamesToEnable;
    for (auto const requestedExtension : requestedExtensionNamesToEnable) {
      for (auto const& availableExtension : availableExtensions) {
        if (AreNamesEqual(
              requestedExtension, availableExtension.extensionName)) {
          extensionNamesToEnable.emplace_back(requestedExtension);
          ELogI("          "s, requestedExtension);
        }
      }
    }

    return extensionNamesToEnable;
  }

  return {};
}

std::vector<char const*>
Instance::GetLayerNamesToEnable() const
{
  auto const& commandLineArgs = GRIProperty(CommandLineArgs);
  if (commandLineArgs.has_value()) {
    auto const& rendererFeatures = commandLineArgs->RendererFeatures();
    auto debugFeature = std::find(
      rendererFeatures.begin(),
      rendererFeatures.end(),
      System::DeviceTypes::Graphics::APIFeatures_t::Debug);

    if (debugFeature != rendererFeatures.end()) {
      return GetRequiredLayerNames();
    }
  }

  return {};
}

std::vector<char const*>
Instance::GetRequiredLayerNames() const
{
  std::vector<char const*> availableLayerNames;
  auto const& vulkanDevice = GRIProperty(HostPlatform).GPUDevice_Vulkan();
  auto const layers = EnumerateInstanceLayers();
  for (auto const layerName : vulkanDevice.ValidationLayerNames()) {
    for (auto const& layer : layers) {
      if (AreNamesEqual(layerName, layer.layerName)) {
        availableLayerNames.emplace_back(layerName);
      }
    }
  }

  using namespace std::string_literals;

  ELogI("      + Layers to enable:"s);
  for ([[maybe_unused]] auto const instanceLayer : availableLayerNames) {
    ELogI("          "s, instanceLayer);
  }

  return availableLayerNames;
}

VKAPI_ATTR VkBool32 VKAPI_CALL
#pragma warning(suppress: 26812) // Allow unscoped enum
Instance::DebugMessangerCallback(
  VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
  VkDebugUtilsMessageTypeFlagsEXT messageTypes,
  VkDebugUtilsMessengerCallbackDataEXT const* pCallbackData,
  void* pUserData)
{
  using namespace std::string_literals;

#if VULKAN_DEBUG_UTILS_MESSANGER_LOADER_MESSAGES_DISABLED
  if (AreNamesEqual(pCallbackData->pMessageIdName, "Loader Message")) {
    return VK_FALSE;
  }
#endif

  ELogVL(pCallbackData->pMessage);

  return VK_FALSE;
}

void
Instance::EnumeratePhysicalDevices()
{
  physicalDevices =
    Vulkan::Objects::Utilities::EnumeratePhysicalDevices<PhysicalDevice>(*this);
}

void
Instance::ListPhysicalDevices()
{
  using namespace std::string_literals;

  ELogI("  - Vulkan devices: ("s, PhysicalDevices().size(), ")"s);
  for (auto const& device : PhysicalDevices()) {
    ELogI("      + Physical device:"s);
    ELogI("          Name: "s, device.Name());
    ELogI("          Type: "s, device.TypeAsString());

    ELogI("          Queue families: ("s, device.QueueFamilies().size(), ")"s);
    ListQueueFamilies(device);

    ELogI("          Extensions:"s);
    ListPhysicalDeviceExtensions(device);
  }
}

void
Instance::SelectPhysicalDevice(PhysicalDevice::Type_t const physicalDeviceType)
{
  assert(
    IsFalse(physicalDevices.empty()) && "No physical devices are available");

  auto physicalDevice = FindPhysicalDevice(physicalDeviceType);
  if (physicalDevice.has_value()) {
    selectedPhysicalDevice = physicalDevice->get();
  } else if (0 < physicalDevices.size()) {
    selectedPhysicalDevice = physicalDevices[0];
  } else {
    selectedPhysicalDevice.reset();
  }

  if (selectedPhysicalDevice.has_value()) {
    using namespace std::string_literals;

    ELogI("  - Selected physical device:"s);
    ELogI("      Name: "s, selectedPhysicalDevice->get().Name());
    ELogI("      Type: "s, selectedPhysicalDevice->get().TypeAsString());
  } else {
    using namespace std::string_literals;

    ELogE("No suitable physical device is available!"s);
  }
}

optional_ref<PhysicalDevice const>
Instance::FindPhysicalDevice(PhysicalDevice::Type_t physicalDeviceType) const
{
  assert(
    IsFalse(physicalDevices.empty()) && "No physical devices are available");

  for (auto const& physicalDevice : physicalDevices) {
    if (physicalDevice.Type() == physicalDeviceType) {
      return std::reference_wrapper<PhysicalDevice const>{ physicalDevice };
    }
  }

  return {};
}

////////////////////////////////////////////////////////////////////////////////
// Free functions
////////////////////////////////////////////////////////////////////////////////

std::vector<VkExtensionProperties>
EnumerateInstanceExtensions()
{
  return EnumerateInstanceExtensions({});
}

std::vector<VkExtensionProperties>
EnumerateInstanceExtensions(std::optional<std::string> const& layerName)
{
  // clang-format off
  assert(
    IsInstance(vkEnumerateInstanceExtensionProperties) &&
    "vkEnumerateInstanceExtensionProperties is not initialized. Were Vulkan function pointers properly loaded?");
  // clang-fomrat on

  char const* layerName_cstr = nullptr;
  if (layerName) {
    layerName_cstr = layerName.value().c_str();
  }

  auto instanceExtensionCount = 0U;
  if (vkCallSuccess(vkEnumerateInstanceExtensionProperties(
        layerName_cstr, &instanceExtensionCount, nullptr))) {
    std::vector<VkExtensionProperties> instanceExtensions(instanceExtensionCount);
    if (vkCallSuccess(vkEnumerateInstanceExtensionProperties(
          layerName_cstr,
          &instanceExtensionCount,
          instanceExtensions.data()))) {
      using namespace std::string_literals;

      ELogI("  - Vulkan instance extensions:"s);
      ELogI("      + Available extensions:"s);
      for ([[maybe_unused]] auto const& extension : instanceExtensions) {
        ELogI("          "s, extension.extensionName);
      }

      return instanceExtensions;
    }
  }

  return {};
}

std::vector<VkLayerProperties>
EnumerateInstanceLayers()
{
  assert(
    IsInstance(vkEnumerateInstanceLayerProperties) &&
    "vkEnumerateInstanceLayerProperties is not initialized. Were Vulkan "
    "function pointers properly loaded?");

  auto instanceLayerCount = 0U;
  if (vkCallSuccess(
        vkEnumerateInstanceLayerProperties(&instanceLayerCount, nullptr))) {
    std::vector<VkLayerProperties> instanceLayers(instanceLayerCount);
    if (vkCallSuccess(vkEnumerateInstanceLayerProperties(
          &instanceLayerCount, instanceLayers.data()))) {
      using namespace std::string_literals;

      ELogI("  - Vulkan instance layers:"s);
      ELogI("      + Available layers:"s);
      for ([[maybe_unused]] auto const& instanceLayer : instanceLayers) {
        ELogI("          "s, instanceLayer.layerName);
      }

      return instanceLayers;
    }
  }

  return {};
}

NAMESPACE_END(Renderer::Graphics)

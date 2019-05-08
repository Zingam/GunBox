// Self
#include "Attributes.hpp"

NAMESPACE_BEGIN(Renderer::Graphics::Vulkan::Layers)

////////////////////////////////////////////////////////////////////////////////
// Free functions
////////////////////////////////////////////////////////////////////////////////

auto
MatchAttributeName(VkExtensionProperties properties, std::string const& name)
  -> bool
{
  return (properties.extensionName == name);
}

auto
MatchAttributeName(VkLayerProperties properties, std::string const& name)
  -> bool
{
  return (properties.layerName == name);
}

NAMESPACE_END(Renderer::Graphics::Vulkan::Layers)

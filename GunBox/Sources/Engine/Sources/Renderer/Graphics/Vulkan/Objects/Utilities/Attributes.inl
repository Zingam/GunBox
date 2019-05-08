#pragma once

////////////////////////////////////////////////////////////////////////////////
// Inline implementations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(Renderer::Graphics::Vulkan)

template<typename Attributes>
auto
GetAvailableAttributes(
  std::vector<Attributes> const& attributes,
  std::vector<std::string> const& requestedAttributeNames)
  -> std::vector<std::string>
{
  std::vector<std::string> enabledAttributeNames;
  for (auto& attributeName : requestedAttributeNames) {
    for (auto& attribute : attributes) {
      if (MatchAttributeName(attribute, attributeName)) {
        enabledAttributeNames.push_back(attributeName);
      }
    }
  }

  return enabledAttributeNames;
}

NAMESPACE_END(Renderer::Graphics::Vulkan)

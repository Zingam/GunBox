// Self
#include "RendererTypes.hpp"

NAMESPACE_BEGIN(System::DeviceTypes::Graphics)

////////////////////////////////////////////////////////////////////////////////
// Free functions
////////////////////////////////////////////////////////////////////////////////

std::string
AsString(System::DeviceTypes::Graphics::API_t graphicsApi)
{
  using namespace std::string_literals;
  using namespace System::DeviceTypes::Graphics;

  switch (graphicsApi) {
    case API_t::Direct3D_12:
      return "Direct3D 12"s;
    case API_t::OpenGL:
      return "OpenGL"s;
    case API_t::Vulkan:
      return "Vulkan"s;
    default:
      return "Unknown"s;
  }
}

NAMESPACE_END(System::DeviceTypes::Graphics)

#pragma once

////////////////////////////////////////////////////////////////////////////////
// Inline method implementations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(Application)

////////////////////////////////////////////////////////////////////////////////
// Properties
////////////////////////////////////////////////////////////////////////////////

inline bool&
Preferences::Fullscreen()
{
  return data.fullscreen;
}

inline System::DeviceTypes::Graphics::Rectangle2D&
Preferences::MainWindowMetrics()
{
  return data.mainWindowMetrics;
}

inline System::DeviceTypes::Graphics::API_t&
Preferences::RendererAPI()
{
  return data.rendererApi;
}

inline bool
Preferences::SuccesfullyLoaded() const
{
  return successfullyLoaded;
}


NAMESPACE_END(Application)

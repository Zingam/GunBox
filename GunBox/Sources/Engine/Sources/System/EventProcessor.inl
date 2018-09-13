////////////////////////////////////////////////////////////////////////////////
// Inline method implementations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_START(System)

template<typename EventHandler>
inline void
EventProcessor::RegisterEventHandler()
{
  eventHandlers.emplace_back(std::make_unique<EventHandler>());
}

NAMESPACE_END(System)
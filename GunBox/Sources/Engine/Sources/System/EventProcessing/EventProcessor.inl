////////////////////////////////////////////////////////////////////////////////
// Inline method implementations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(System)

template<typename EventHandler, typename... Args>
inline void
EventProcessor::RegisterEventHandler(Args&&... args)
{
  eventHandlers.emplace_back(
    std::make_unique<EventHandler>(std::forward<Args>(args)...));
}

NAMESPACE_END(System)

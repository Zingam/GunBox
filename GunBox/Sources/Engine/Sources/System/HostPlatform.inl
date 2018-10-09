////////////////////////////////////////////////////////////////////////////////
// Inline method implementations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(System)

inline void
HostPlatform::HideSystemConsole()
{
  o_ptr->HideSystemConsole();
}

inline void
HostPlatform::ShowSystemConsole()
{
  o_ptr->ShowSystemConsole();
}

NAMESPACE_END(System)

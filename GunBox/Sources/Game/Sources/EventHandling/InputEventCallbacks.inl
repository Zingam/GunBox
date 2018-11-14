#pragma once

// C++ Standard Library
#include <type_traits>

////////////////////////////////////////////////////////////////////////////////
// Inline method implementations
////////////////////////////////////////////////////////////////////////////////

NAMESPACE_BEGIN(GunBox)

template<typename Commander, typename... Args>
auto
InputEventCallbacks::SetCommander(Args&&... args) -> void
{
  static_assert(
    std::is_base_of_v<Commander_Interface, Commander>,
    "Type 'Commander' is not derived from 'Commander_Interface'.");

  commander = std::make_unique<Commander>(std::forward<Args>(args)...);
}

NAMESPACE_END(GunBox)

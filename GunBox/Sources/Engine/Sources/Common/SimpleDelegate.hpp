#pragma once
////////////////////////////////////////////////////////////////////////////////

// C++ Standard Library
#include <memory>
#include <type_traits>

////////////////////////////////////////////////////////////////////////////////
// Class declarations
////////////////////////////////////////////////////////////////////////////////

template<typename ClassName, typename MethodPointerType>
class SimpleDelegate
{
  // Because of 'decltype' the order of declarations matters
private:
  MethodPointerType method;
  ClassName& object;

public:
  SimpleDelegate(ClassName& object, MethodPointerType method);

  // Public method templates
public:
  template<typename... Args>
  auto Invoke(Args... args) -> std::enable_if_t<
    std::is_same_v<void, decltype((object.*method)(args...))>,
    decltype((object.*method)(args...))>;

  template<typename... Args>
  auto Invoke(Args... args) -> std::enable_if_t<
    !std::is_same_v<void, decltype((object.*method)(args...))>,
    decltype((object.*method)(args...))>;

  // Public operator templates
public:
  template<typename... Args>
  auto operator()(Args... args) -> std::enable_if_t<
    std::is_same_v<void, decltype((object.*method)(args...))>,
    decltype((object.*method)(args...))>;

  template<typename... Args>
  auto operator()(Args... args) -> std::enable_if_t<
    !std::is_same_v<void, decltype((object.*method)(args...))>,
    decltype((object.*method)(args...))>;
};

////////////////////////////////////////////////////////////////////////////////
// Free functions
////////////////////////////////////////////////////////////////////////////////

// WORKAROUND: error C2668: 'make_unique_delegate': ambiguous call to
// overloaded function
#if !defined(_MSC_VER)
template<typename ClassName, typename MethodPointerType>
auto
make_unique_delegate(ClassName object, MethodPointerType method_Ptr)
  -> std::unique_ptr<SimpleDelegate<ClassName, MethodPointerType>>;
#endif

////////////////////////////////////////////////////////////////////////////////
// Inline implementations
////////////////////////////////////////////////////////////////////////////////

#include "SimpleDelegate.inl"

////////////////////////////////////////////////////////////////////////////////

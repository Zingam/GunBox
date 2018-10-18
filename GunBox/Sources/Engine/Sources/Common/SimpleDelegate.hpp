#pragma once

// C++ Standard Library
#include <memory>
#include <type_traits>

template<typename ClassName, typename MethodPointerType>
class SimpleDelegate
{
  // Because of 'decltype' the order of declarations matters
private:
  MethodPointerType method;
  ClassName& object;

public:
  SimpleDelegate(ClassName& object, MethodPointerType method);

public:
  template<typename... Args>
  inline auto operator()(Args... args)
    -> std::enable_if_t<std::is_same_v<void, decltype(this->Invoke(args...))>,
                        decltype(this->Invoke(args...))>;

  template<typename... Args>
  inline auto operator()(Args... args)
    -> std::enable_if_t<!std::is_same_v<void, decltype(this->Invoke(args...))>,
                        decltype(this->Invoke(args...))>;

private:
  template<typename... Args>
  inline auto Invoke(Args... args) -> std::enable_if_t<
    std::is_same_v<void, decltype((object.*method)(args...))>,
    decltype((object.*method)(args...))>;

  template<typename... Args>
  inline auto Invoke(Args... args) -> std::enable_if_t<
    !std::is_same_v<void, decltype((object.*method)(args...))>,
    decltype((object.*method)(args...))>;
};

////////////////////////////////////////////////////////////////////////////////
// Free functions
////////////////////////////////////////////////////////////////////////////////

template<typename ClassName, typename MethodPointerType>
inline auto
make_unique_delegate(ClassName object, MethodPointerType method_Ptr)
  -> std::unique_ptr<SimpleDelegate<ClassName, MethodPointerType>>;

////////////////////////////////////////////////////////////////////////////////
// Inline method implementations
////////////////////////////////////////////////////////////////////////////////

#include "SimpleDelegate.inl"

////////////////////////////////////////////////////////////////////////////////

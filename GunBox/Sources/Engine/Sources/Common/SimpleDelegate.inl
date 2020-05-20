#pragma once

////////////////////////////////////////////////////////////////////////////////
// Inline implementations
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Constructor templates
////////////////////////////////////////////////////////////////////////////////

template<typename ClassName, typename MethodPointerType>
SimpleDelegate<ClassName, MethodPointerType>::SimpleDelegate(
  ClassName& object,
  MethodPointerType method)
  : method{ method }
  , object{ object }
{}

////////////////////////////////////////////////////////////////////////////////
// Public method templates
////////////////////////////////////////////////////////////////////////////////

template<typename ClassName, typename MethodPointerType>
template<typename... Args>
auto
SimpleDelegate<ClassName, MethodPointerType>::operator()(Args... args)
  -> std::enable_if_t<
    std::is_same_v<void, decltype(this->Invoke(args...))>,
    decltype(this->Invoke(args...))>
{
  this->Invoke(std::forward<Args>(args)...);
}

template<typename ClassName, typename MethodPointerType>
template<typename... Args>
auto
SimpleDelegate<ClassName, MethodPointerType>::operator()(Args... args)
  -> std::enable_if_t<
    !std::is_same_v<void, decltype(this->Invoke(args...))>,
    decltype(this->Invoke(args...))>
{
  return this->Invoke(std::forward<Args>(args)...);
}

////////////////////////////////////////////////////////////////////////////////
// Private method templates
////////////////////////////////////////////////////////////////////////////////

template<typename ClassName, typename MethodPointerType>
template<typename... Args>
auto
SimpleDelegate<ClassName, MethodPointerType>::Invoke(Args... args)
  -> std::enable_if_t<
    std::is_same_v<void, decltype((object.*method)(args...))>,
    decltype((object.*method)(args...))>
{
  (object.*method)(std::forward<Args>(args)...);
}

template<typename ClassName, typename MethodPointerType>
template<typename... Args>
auto
SimpleDelegate<ClassName, MethodPointerType>::Invoke(Args... args)
  -> std::enable_if_t<
    !std::is_same_v<void, decltype((object.*method)(args...))>,
    decltype((object.*method)(args...))>
{
  return (object.*method)(std::forward<Args>(args)...);
}

////////////////////////////////////////////////////////////////////////////////
// Free function templates
////////////////////////////////////////////////////////////////////////////////

template<typename ClassName, typename MethodPointerType>
std::unique_ptr<SimpleDelegate<ClassName, MethodPointerType>>
make_unique_delegate(ClassName& object, MethodPointerType method_Ptr)
{
  using SimpleDelegateType =
    SimpleDelegate<ClassName, MethodPointerType>;

  return std::make_unique<SimpleDelegateType>(object, method_Ptr);
}

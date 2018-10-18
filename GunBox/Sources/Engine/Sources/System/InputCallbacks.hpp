// Project headers - Common
#include "Common/Macros/Base.hpp"

NAMESPACE_BEGIN(System)

class InputCallbacks
{
public:
  InputCallbacks() = default;
  virtual ~InputCallbacks() = 0;

  // Pure virtual methods
public:
  virtual auto GamepadAxisMotion() -> void = 0;
  virtual auto GamepadButtonDown() -> void = 0;
  virtual auto GamepadButtonUp() -> void = 0;
  virtual auto KeyboardKeyDown() -> void = 0;
  virtual auto KeyboardKeyUp() -> void = 0;
};

NAMESPACE_END(System)

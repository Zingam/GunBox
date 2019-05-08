#pragma once

#if !defined(vkCallSuccess)
#  define vkCallSuccess(x) (VK_SUCCESS == (x))
#else
#  error vkCallSuccess is already defined...
#endif //! defined

#if !defined(vkCallFail)
#  define vkCallFail(x) (VK_SUCCESS != (x))
#else
#  error vkCallFail is already defined...
#endif //! defined

#pragma once

#if !defined(NAMESPACE_START)
#  define NAMESPACE_START(ns) namespace ns {
#else
#  error NAMESPACE_START is already defined...
#endif

#if !defined(NAMESPACE_END)
#  define NAMESPACE_END(ns) }
#else
#  error NAMESPACE_END is already defined...
#endif

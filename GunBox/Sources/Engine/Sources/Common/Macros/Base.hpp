#pragma once

////////////////////////////////////////////////////////////////////////////////
// Name:
//   Base.hpp
// Description:
//   BASE MACROS header
// Summary:
//   Defines 'namespace' definition and 'pragma message' macros. Always include
//   on top.
////////////////////////////////////////////////////////////////////////////////

/// Macro: NAMESPACE_BEGIN(ns)
#if !defined(NAMESPACE_BEGIN)
#  define NAMESPACE_BEGIN(ns) namespace ns {
#else
#  error NAMESPACE_BEGIN is already defined...
#endif

/// Macro: NAMESPACE_END(ns)
#if !defined(NAMESPACE_END)
#  define NAMESPACE_END(ns) }
#else
#  error NAMESPACE_END is already defined...
#endif

#if !defined(DISABLE_PRAGMA_MESSAGE_REMINDER_MACRO)

////////////////////////////////////////////////////////////////////////////////
// Private helper macros (starting with '$PRAGMA_MESSAGE_')
////////////////////////////////////////////////////////////////////////////////

/// Macro: $PRAGMA_MESSAGE_StringizeWithQuotes
#  if !defined($PRAGMA_MESSAGE_StringizeWithQuotes)
// Converts the parameter to a string surrounded with quotes (step 1)
#    define $PRAGMA_MESSAGE_StringizeWithQuotes(string) #    string
// Note:
// When a macro parameter is used with a leading '#', the preprocessor replaces
// it with the literal text of the actual argument, converted to a string
// constant.  Unlike normal parameter replacement, the argument is not
// macro-expanded first. This is called stringizing.
#  else
#    error $PRAGMA_MESSAGE_StringizeWithQuotes is already defined
#  endif

/// Macro: $PRAGMA_MESSAGE_ToStringWithQuotes(macro, string) macro(string)
#  if !defined($PRAGMA_MESSAGE_ToStringWithQuotes)
#    define $PRAGMA_MESSAGE_ToStringWithQuotes(macro, string) macro(string)
#  else
#    error $PRAGMA_MESSAGE_ToStringWithQuotes is already defined
#  endif

/// Macro: $PRAGMA_MESSAGE_Stringize
#  if !defined($PRAGMA_MESSAGE_Stringize)
// Converts the parameter to a string without quotes (step 1)
#    define $PRAGMA_MESSAGE_Stringize(string) "" #    string
// Note:
// The '##' preprocessing operator performs token pasting. When a macro is
// expanded, the two tokens on either side of each '##' operator are combined
// into a single token, which then replaces the '##' and the two original tokens
// in the macro expansion.
#  else
#    error $PRAGMA_MESSAGE_Stringize is already defined
#  endif

/// Macro: $PRAGMA_MESSAGE_ToString
#  if !defined($PRAGMA_MESSAGE_ToString)
// Converts the parameter to a string without quotes (step 2)
#    define $PRAGMA_MESSAGE_ToString(string) $PRAGMA_MESSAGE_Stringize(string)
#  else
#    error $PRAGMA_MESSAGE_ToString is already defined
#  endif

/// Macro: $PRAGMA_MESSAGE_Line
#  if !defined($PRAGMA_MESSAGE_Line)
#    define $PRAGMA_MESSAGE_Line                                               \
      $PRAGMA_MESSAGE_ToStringWithQuotes($PRAGMA_MESSAGE_StringizeWithQuotes,  \
                                         __LINE__)
#  else
#    error $PRAGMA_MESSAGE_Line is already defined
#  endif

////////////////////////////////////////////////////////////////////////////////
// Statements like:
//		#pragma message(pragma_message_Reminder "Fix this problem!")
// Which will cause messages like:
//		C:\Source\Project\main.cpp(47): Reminder -> Fix this problem!
// to show up during compiles.  Note that you can NOT use the
// words "error" or "warning" in your reminders, since it will
// make the IDE think it should abort execution.  You can double
// click on these messages and jump to the line in question.
////////////////////////////////////////////////////////////////////////////////

/// Macro: pragma_message_Note
#  if !defined(pragma_message_Note)
#    define pragma_message_Note __FILE__ "(" $PRAGMA_MESSAGE_Line ") : NOTE -> "
#  else
#    error pragma_message_Note is already defined
#  endif

/// Macro: pragma_message_Reminder
#  if !defined(pragma_message_Reminder)
#    define pragma_message_Reminder                                            \
      __FILE__ "(" $PRAGMA_MESSAGE_Line ") : Reminder -> "
#  else
#    error pragma_message_Reminder is already defined
#  endif

/// Macro: pragma_message_Info
#  if !defined(pragma_message_Info)
#    define pragma_message_Info "    INFO -> "
#  else
#    error pragma_message_Info is already defined
#  endif

// clang-format off

/// Macro: pragma_message_InfoBold
#  if !defined(pragma_message_InfoBold)
# if !defined (__clang__)
#    define pragma_message_InfoBold(message)                                   \
      "\n"                                                                     \
      "=================================================================="     \
      "==================================================================\n"   \
      "  INFO -> " $PRAGMA_MESSAGE_ToString(message) " \n"                     \
      "=================================================================="     \
      "==================================================================\n"
#else
#    define pragma_message_InfoBold(message) "" $PRAGMA_MESSAGE_ToString(message)
#endif
#  else
#    error pragma_message_InfoBold is already defined
#  endif

/// Macro: pragma_message_FileInfo
#  if !defined(pragma_message_FileInfo)
# if !defined (__clang__)
#    define pragma_message_FileInfo(message)                                   \
      "\n"                                                                     \
      "=================================================================="     \
      "==================================================================\n"   \
      "  INFO -> " $PRAGMA_MESSAGE_ToString(message) ":\n"                     \
      "          -> " __FILE__ " \n"                                           \
      "=================================================================="     \
      "==================================================================\n"
#else
#    define pragma_message_FileInfo(message) "" $PRAGMA_MESSAGE_ToString(message)
#endif
#  else
#    error pragma_message_FileInfo is already defined
#  endif

// clang-format on

#endif

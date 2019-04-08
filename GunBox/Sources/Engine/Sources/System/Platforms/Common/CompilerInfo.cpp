// Self
#include "CompilerInfo.hpp"

// C++ Standard Library
#include <sstream>

// clang-format off
#define CONVERT_TO_C_STR(x) #x
#define VERSION_TO_STRING(x) CONVERT_TO_C_STR(x)s
// clang-format on

NAMESPACE_BEGIN(System::HostPlatformClasses)

CompilerInfo::CompilerInfo()
{
  using namespace std::string_literals;

  Version::BuildNumber_t buildNumber{ 0 };
  Version::Major_t major{ 0 };
  Version::Minor_t minor{ 0 };
  Version::PatchLevel_t patchLevel{ 0 };

  std::string longVersion;

  // Clang/LLVM:
  //   __clang_major__      - Contains the major version number
  //                          (e.g. "3" for version 3.0.1)
  //   __clang_minor__      - Ccontains the minor version number
  //                          (e.g. "0" for version 3.0.1)
  //   __clang_patchlevel__ - Contains the patch level number
  //                          (e.g. "1" for version 3.0.1)
  //   __clang_version__    - Contains a version string
  //                          (e.g. "3.0 (tags/RELEASE_30/final)" for version
  //                          3.0.0). The format of the string is undefined and
  //                          varies with different distributions.
  //   __cplusplus          - Expands to a version number. Depending on the
  //                          language standard selected, the value of the macro
  //                          is 199711L for the 1998 C++ standard, 201103L for
  //                          the 2011 C++ standard, 201402L for the 2014 C++
  //                          standard, 201703L for the 2017 C++ standard, or an
  //                          unspecified value strictly larger than 201703L for
  //                          the experimental languages enabled by -std=c++2a
  //                          and -std=gnu++2a.
  // The following macros are defined per GNU GCC/G++ and indicate Clang
  // compatibility:
  //   __GNUC__             - Contains the major version number
  //                          (e.g. "4" for version 4.2.1)
  //   __GNUG__             - Contains the major version number
  //                          (e.g. "4" for version 4.2.1)
  //   __GNUC_MINOR__       - Contains the minor version number
  //                          (e.g. "2" for version 4.2.1)
  //   __GNUC_PATCHLEVEL__  - Contains the patch level number
  //                          (e.g. "1" for version 4.2.1)
  //   __VERSION__          - Contains a long version string
  //                          (e.g. "4.2.1 Compatible Clang 3.0
  //                          (tags/RELEASE_30/final)" for version 3.0.0 with
  //                          GCC 4.2.1 compatibility). The format of the string
  //                          is undefined and varies with different
  //                          distributions.
#if defined(__clang__)
  this->name = "Clang"s;
#  if defined(__clang_major__)
  major = __clang_major__;
#  endif
#  if defined(__clang_minor__)
  minor = __clang_minor__;
#  endif
#  if defined(__clang_patchlevel__)
  patchLevel = __clang_patchlevel__;
#  endif
#  if defined(__clang_version__)
  longVersion = __clang_version__;
#  endif
#  if defined(__cplusplus)
  this->languageStandard = __cplusplus;
#  endif
#  if defined(__GNUC__) // __GNUG__
  major = __GNUC__;
#    if defined(__GNUC_MINOR__)
  minor = __GNUC_MINOR__;
#    endif
#    if defined(__GNUC_PATCHLEVEL__)
  patchLevel = __GNUC_PATCHLEVEL__;
#    endif
#    if defined(__VERSION__)
  longVersion = __VERSION__;
#    endif
#  endif
  // GNU GCC/G++:
  //   __GNUC__             - Contains the major version number
  //                          (e.g. "4" for version 4.2.1)
  //   __GNUG__             - Contains the major version number
  //                          (e.g. "4" for version 4.2.1)
  //   __GNUC_MINOR__       - Contains the minor version number
  //                          (e.g. "2" for version 4.2.1)
  //   __GNUC_PATCHLEVEL__  - Contains the patch level number
  //                          (e.g. "1" for version 4.2.1)
  //   __VERSION__          - Contains a long version string
  //                          (e.g. "4.6.1" for version 4.6.1)
  //   __cplusplus          - Expands to a version number. Depending on the
  //                          language standard selected, the value of the macro
  //                          is 199711L for the 1998 C++ standard, 201103L for
  //                          the 2011 C++ standard, 201402L for the 2014 C++
  //                          standard, 201703L for the 2017 C++ standard, or an
  //                          unspecified value strictly larger than 201703L for
  //                          the experimental languages enabled by -std=c++2a
  //                          and -std=gnu++2a.
#elif defined(__GNUC__) // __GNUG__
  major = __GNUC__;
#  if defined(__GNUC_MINOR__)
  minor = __GNUC_MINOR__;
#  endif
#  if defined(__GNUC_PATCHLEVEL__)
  patchLevel = __GNUC_PATCHLEVEL__;
#  endif
#  if defined(__VERSION__)
  longVersion = __VERSION__;
#  endif
#  if defined(__cplusplus)
  this->languageStandard = __cplusplus;
#  endif
  // Microsoft Visual Studio:
  //   _MSC_VER             - Contains the major and minor version numbers as an
  //                          integer (e.g. "1500" is version 15.00).
  //   _MSC_FULL_VER        - Contains the major version, minor version, and
  //                          build numbers as an integer
  //                          (e.g. "150020706" is version 15.00.20706).
  //   _MSC_BUILD           - Contains the revision number after the major
  //                          version, minor version, and build numbers
  //                          (e.g. "1" is revision 1, such as
  //                          for 15.00.20706.01)
#elif defined(_MSC_VER)
  this->name = "MSVC"s;
#  if defined(_MSC_BUILD) // __GNUG__
  patchLevel = _MSC_BUILD;
#  endif
#  if defined(_MSC_FULL_VER) // __GNUG__
  longVersion = VERSION_TO_STRING(_MSC_FULL_VER);
#  endif
#  if defined(_MSC_VER) // __GNUG__
#    if defined(_MSC_FULL_VER) && (999999999 >= _MSC_FULL_VER)
  constexpr std::uint32_t majorVersion = _MSC_VER / 1'00;
  constexpr std::uint32_t minorVersion = _MSC_VER - majorVersion * 1'00;
  constexpr std::uint32_t buildVersion = _MSC_FULL_VER - _MSC_VER * 1'00000;
  if (
    (99 >= majorVersion) && (99 >= minorVersion) && (999'999 >= buildVersion)) {
    major = majorVersion;
    minor = minorVersion;
    buildNumber = buildVersion;
  } else {
    major = _MSC_VER;
  }
#    else
  {
    major = _MSC_VER;
  }
#    endif
#  endif
#  if defined(_MSVC_LANG)
  this->languageStandard = _MSVC_LANG;
#  endif
#else
#  error Unsupported compiler...
#endif

#if (_MSC_VER)
  this->version = std::make_unique<Version>(
    Version::Version_t{ major, minor, patchLevel, buildNumber },
    [major, minor, patchLevel, buildNumber]() {
      std::stringstream ss;
      ss << major << '.';
      ss << minor << '.';
      ss << buildNumber << '.';
      ss << patchLevel;

      return ss.str();
    });
#else
  this->version = std::make_unique<Version>(
    Version::Version_t{ major, minor, patchLevel, buildNumber }, longVersion);
#endif
}

std::uint32_t
CompilerInfo::LanguageStandard() const
{
  return this->languageStandard;
}

std::string const&
CompilerInfo::Name() const
{
  return this->name;
}

Version const&
CompilerInfo::GetVersion() const
{
  return *(this->version);
}

NAMESPACE_END(System::HostPlatformClasses)

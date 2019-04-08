////////////////////////////////////////////////////////////////////////////////
// Inline method implementations
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Constructor templates
////////////////////////////////////////////////////////////////////////////////

/// <summary>
///   Constructs an object representing an abstract component version.
///   <para>
///   It accepts an argument of type <code>Version_t</code>, where the first
///   element represents a major number, the second element the minor number,
///   the third element is the patch level and the forth element the build
///   number, e.g. <b>Major.Minor.PatchLevel.BuildNumber</b>. The output format
///   string can be customized via a lambda function, which returns a string.
///   </para>
/// </summary>
/// <example>
///   <code>
///   <![CDATA[
///   Version version {
///     Version::Version_t{ major, minor, patchLevel, buildNumber },
///       [major, minor, patchLevel, buildNumber]() {
///         std::stringstream ss;
///         ss << major << '.';
///         ss << minor << '.';
///         ss << buildNumber << '.';
///         ss << patchLevel;
///         return ss.str();
///     }}]]>
///   </code>
/// </example>
template<typename FormatFunc>
Version::Version(Version_t version, FormatFunc formatFunc)
  : version{ std::move(version) }
{
  static_assert(
    std::is_invocable<FormatFunc>::value,
    "The constructor argument must be an invocable lambda function");

  this->versionString = formatFunc();
}

template<typename FormatFunc>
Version::Version(
  Version_t version,
  std::string const& longVersion,
  FormatFunc formatFunc)
  : Version(version, formatFunc)
{
  this->versionString = formatFunc();
}

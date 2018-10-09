#pragma once

////////////////////////////////////////////////////////////////////////////////
// Product strings
////////////////////////////////////////////////////////////////////////////////

#if !defined(Game_DeveloperOrganization)
#  define Game_DeveloperOrganization "RMM"
#else
#  error Game_Developer is already defined...
#endif

#if !defined(Game_Title)
#  define Game_Title "GunBox"
#else
#  error Game_Name is already defined...
#endif

////////////////////////////////////////////////////////////////////////////////
// Version numbers
////////////////////////////////////////////////////////////////////////////////

#if !defined(Game_VersionBuildNumber)
#  define Game_VersionBuildNumber 0
#else
#  error Game_VersionBuildNumber is already defined...
#endif

#if !defined(Game_VersionMajor)
#  define Game_VersionMajor 0
#else
#  error Game_VersionMajor is already defined...
#endif

#if !defined(Game_VersionMinor)
#  define Game_VersionMinor 1
#else
#  error Game_VersionMinor is already defined...
#endif

#if !defined(Game_VersionPatch)
#  define Game_VersionPatch 0
#else
#  error Game_VersionPatch is already defined...
#endif

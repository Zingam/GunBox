#if !defined(GPUPREFERENCE_H_INCLUDE_ONCE__)
#  define GPUPREFERENCE_H_INCLUDE_ONCE__
#else
#  error This file is already included. Include it just once in "main.cpp"
#endif

#if defined(_WINDOWS) && !defined(PREFER_INTEGRATED_GPU)
// NVIDIA
extern "C"
{
  // Global Variable NvOptimusEnablement (new in Driver Release 302)
  //
  // Starting with the Release 302 drivers, application developers can direct
  // the Optimus driver at runtime to use the High Performance Graphics to
  // render any application–even those applications for which there is no
  // existing application profile. They can do this by exporting a global
  // variable named NvOptimusEnablement. The Optimus driver looks for the
  // existence and value of the export. Only the LSB of the DWORD matters at
  // this time. A value of 0x00000001 indicates that rendering should be
  // performed using High Performance Graphics. A value of 0x00000000
  // indicates that this method should be ignored.
  //
  // NOTE: Needs to be in an executable in order to be detected.
  __declspec(dllexport) volatile unsigned long NvOptimusEnablement = 0x00000001;
}
// AMD
extern "C"
{
  // Global Variable AmdPowerXpressRequestHighPerformance
  //
  // This will select the high performance GPU as long as no profile exists that
  // assigns the application to another GPU.
  // Supported in driver 13.35 and newer.
  //
  // NOTE: Needs to be in an executable in order to be detected.
  __declspec(dllexport) volatile int AmdPowerXpressRequestHighPerformance = 1;
}
#endif

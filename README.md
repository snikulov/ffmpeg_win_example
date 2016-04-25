ffmpeg_win_example
==================

CMake + FFMPEG for Microsoft Visual Studio example

Used 3rd parties tools/libs
============================

 - Zeranoe FFmpeg builds (DEV + Shared) http://ffmpeg.zeranoe.com/builds/ install anywhere on build machine
 - msinttypes an ISO C9x compliant stdint.h and inttypes.h for Microsoft Visual Studio http://code.google.com/p/msinttypes/
      Note: I've renamed stdint.h from this paroject to mstdint.h to avoid clash with existed stdint.h for MSVS2010+
 - cmake http://cmake.org/
 - ninja http://martine.github.io/ninja/
 - Visual studio https://www.visualstudio.com/



Usage
======

 - set INCLUDE=%INCLUDE%;< path to ffmpeg include folder >
 - set LIB=%LIB%;< path to ffmpeg lib folder >
 - cmake < path to this project clone with submodules > -G[Ninja | any other generator your want]
 - ninja

Done!

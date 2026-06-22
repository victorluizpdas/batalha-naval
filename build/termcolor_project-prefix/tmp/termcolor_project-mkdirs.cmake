# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file LICENSE.rst or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION ${CMAKE_VERSION}) # this file comes with cmake

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "C:/Users/Victor/Desktop/batalha naval/build/termcolor_project-prefix/src/termcolor_project")
  file(MAKE_DIRECTORY "C:/Users/Victor/Desktop/batalha naval/build/termcolor_project-prefix/src/termcolor_project")
endif()
file(MAKE_DIRECTORY
  "C:/Users/Victor/Desktop/batalha naval/build/termcolor_project-prefix/src/termcolor_project-build"
  "C:/Users/Victor/Desktop/batalha naval/build/termcolor_project-prefix"
  "C:/Users/Victor/Desktop/batalha naval/build/termcolor_project-prefix/tmp"
  "C:/Users/Victor/Desktop/batalha naval/build/termcolor_project-prefix/src/termcolor_project-stamp"
  "C:/Users/Victor/Desktop/batalha naval/build/termcolor_project-prefix/src"
  "C:/Users/Victor/Desktop/batalha naval/build/termcolor_project-prefix/src/termcolor_project-stamp"
)

set(configSubDirs Debug;Release;MinSizeRel;RelWithDebInfo)
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/Victor/Desktop/batalha naval/build/termcolor_project-prefix/src/termcolor_project-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Users/Victor/Desktop/batalha naval/build/termcolor_project-prefix/src/termcolor_project-stamp${cfgdir}") # cfgdir has leading slash
endif()

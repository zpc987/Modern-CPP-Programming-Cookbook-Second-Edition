cmake_minimum_required(VERSION 3.15.0)
project(cppcookbook)

if(MSVC)
  message(status "Setting MSVC flags")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHc /std:c++latest")
else()
  message(status "Setting GCC/Clang flags")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a -fexceptions -g -Wall")
endif()

message(status "** CMAKE_CXX_FLAGS: ${CMAKE_CXX_FLAGS}")

SET(BOOST_PATH "" CACHE STRING "Path to the installation path of Boost")
SET(GTEST_PATH "" CACHE STRING "Path to the installation path of Google Test")
SET(GTEST_PATH_LIB "" CACHE STRING "Path to the Google Test libraries directory")
SET(CATCH_PATH "" CACHE STRING "Path to the installation path of Catch2")
SET(RANGES_PATH "" CACHE STRING "Path to the installation path of Ranges-v3")
SET(CPPCORO_PATH "" CACHE STRING "Path to the installation path of cppcoro")
SET(SKIP_TEST_PROJECTS false CACHE BOOL "Flag to prevent the generation of unit test projects")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

add_subdirectory(chapter01)
add_subdirectory(chapter02)
add_subdirectory(chapter03)
add_subdirectory(chapter04)
add_subdirectory(chapter05)
add_subdirectory(chapter06)
add_subdirectory(chapter07)
add_subdirectory(chapter08)
add_subdirectory(chapter09)
add_subdirectory(chapter10)

if(NOT ${SKIP_TEST_PROJECTS})
   add_subdirectory(chapter11/chapter11ca_01)
   add_subdirectory(chapter11/chapter11ca_02)
   add_subdirectory(chapter11/chapter11ca_03)
   add_subdirectory(chapter11/chapter11ca_04)

   if(MSVC)
     message(status "Setting MSVC flags for Boost and GTest")
     set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHc /std:c++latest")
   else()
     message(status "Setting GCC/Clang flags for Boost and GTest")
     set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a -fexceptions -g -Wall")
   endif()
   message(status "** CMAKE_CXX_FLAGS: ${CMAKE_CXX_FLAGS}")

   add_subdirectory(chapter11/chapter11bt_01_1)
   add_subdirectory(chapter11/chapter11bt_01_2)
   add_subdirectory(chapter11/chapter11bt_01_3)
   add_subdirectory(chapter11/chapter11bt_02)
   add_subdirectory(chapter11/chapter11bt_03)
   add_subdirectory(chapter11/chapter11bt_04)
   add_subdirectory(chapter11/chapter11bt_05)

   add_subdirectory(chapter11/chapter11gt_01)
   add_subdirectory(chapter11/chapter11gt_02)
   add_subdirectory(chapter11/chapter11gt_03)
   add_subdirectory(chapter11/chapter11gt_04)
   add_subdirectory(chapter11/chapter11gt_05)
else()
   message(status "Skipping generating unit testing projects")
endif()

#add_subdirectory(chapter12/chapter12_03)
#add_subdirectory(chapter12/chapter12_04)
#add_subdirectory(chapter12/chapter12_05)
#add_subdirectory(chapter12/chapter12_06)
#add_subdirectory(chapter12/chapter12_07)
#add_subdirectory(chapter12/chapter12_07_1)
#add_subdirectory(chapter12/chapter12_08)
#add_subdirectory(chapter12/chapter12_08_1)

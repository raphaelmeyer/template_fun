cmake_minimum_required(VERSION 3.7)
project(template_fun)

set(CMAKE_CXX_STANDARD 14)

include(googletest.cmake)

set(LIBNAME tfun)

add_library(${LIBNAME} INTERFACE)
target_include_directories(${LIBNAME} INTERFACE include)

add_subdirectory(test)

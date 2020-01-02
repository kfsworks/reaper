#project(pear)
#add_executable(${PROJECT_NAME} "main.cpp")

# export CC=/usr/bin/clang && export CXX=/usr/bin/clang++ && cd build/default  && cmake -D_CMAKE_TOOLCHAIN_PREFIX=llvm- -GNinja ../..
# ln -s ./build/default/compile_commands.json  compile_commands.json
# gcc -isystem /usr/include/libusb-1.0 -lusb-1.0 listdevs.c /usr/include/libusb-1.0 -lusb-1.0 listdevs.c

cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(reaper)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# CMAKE_PREFIX_PATH

find_package(PkgConfig)
pkg_check_modules(libusb-1.0 REQUIRED libusb-1.0)

find_path(LIBUSB_INCLUDE_DIR
  NAMES libusb.h
  PATHS
    /usr
    /usr/local
    /opt
    "${CMAKE_BINARY_DIR}\\include"
    PATH_SUFFIXES libusb-1.0
)
#message(${LIBUSB_INCLUDE_DIR})

include_directories("${LIBUSB_INCLUDE_DIR}")
#include_directories(include)
#include_directories(src/mingw)

find_library(LIBUSB_LIBRARY
  NAMES usb-1.0
  PATHS
    /usr
    /usr/local
    /opt
    "${CMAKE_BINARY_DIR}/MS64/static"
    "${CMAKE_BINARY_DIR}/MS64/dll"
)
#message("CMAKE_BINARY_DIR: ${CMAKE_BINARY_DIR}")
#message("LIBUSB_LIBRARY: ${LIBUSB_LIBRARY}")
#message("PROJECT_NAME: ${PROJECT_NAME}")

# set(CMAKE_VERBOSE_MAKEFILE ON)
file(GLOB REAPER_SOURCES_XX RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
  include/*.hpp
  src/*.cpp
)

#set(REAPER_SOURCES_XX
#  ${REAPER_SOURCES_XX}
#  ${CMAKE_CURRENT_BINARY_DIR}/include/.hpp
#)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")
add_library(libreaper STATIC ${REAPER_SOURCES_XX})

#target_include_directories(
#  cheeseburgerlib
#  PUBLIC
#    "include"
#)

add_executable(reaper
  src/main.cpp
)

target_link_libraries(${PROJECT_NAME} ${LIBUSB_LIBRARY} libreaper)
#target_link_libraries(${PROJECT_NAME} ${LIBUSB_LIBRARY})

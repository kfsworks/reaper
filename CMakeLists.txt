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

find_path(LIBUSB_INCLUDE_DIR
  NAMES libusb.h
  PATH_SUFFIXES "include" "libusb" "libusb-1.0"
)

find_library(LIBUSB_LIBRARY
  NAMES usb
  PATH_SUFFIXES "lib" "lib32" "lib64"
)

# set(CMAKE_VERBOSE_MAKEFILE ON)

#add_library(cheeseburgerlib
#  include/random_generator.hpp
#  src/random_generator.cpp
#)

#target_include_directories(
#  cheeseburgerlib
#  PUBLIC
#    "include"
#)

add_executable(reaper
  src/main.cpp
)

target_include_directories(reaper LIBUSB_INCLUDE_DIR)
target_link_libraries(reaper LIBUSB_LIBRARY)
#target_link_libraries(cpp_demo cheeseburgerlib)

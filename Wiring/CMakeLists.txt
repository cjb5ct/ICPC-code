cmake_minimum_required(VERSION 3.17)
project(Wiring)

set(CMAKE_CXX_STANDARD 14)

add_executable(Wiring main.cpp electric.cpp electric.h findUnion.cpp findUnion.h)
cmake_minimum_required(VERSION 3.17)
project(Balltest)

set(CMAKE_CXX_STANDARD 14)

add_executable(Balltest main.cpp ballmanager.cpp ballmanager.h ball.cpp ball.h)
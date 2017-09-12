cmake_minimum_required(VERSION 3.6)
project(motion-vision)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/main.cpp src/ccd.cpp src/ccd.h src/Robot.cpp src/Robot.h src/Arm.cpp src/Arm.h)
add_executable(motion-vision ${SOURCE_FILES})
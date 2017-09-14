cmake_minimum_required(VERSION 3.6)
project(motion-vision)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/main.cpp src/Arm.cpp src/Arm.h src/Segment.cpp src/Segment.h src/Point.cpp src/Point.h)
add_executable(motion-vision ${SOURCE_FILES})
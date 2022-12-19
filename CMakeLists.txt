cmake_minimum_required(VERSION 3.24)
project(oop_course_3rd_task)

set(CMAKE_CXX_STANDARD 14)

include_directories(includes)

add_executable(oop_course_3rd_task srcs/main.cpp srcs/ROV.cpp includes/ROV.h srcs/Mission.cpp includes/Mission.h srcs/Visitor.cpp includes/Visitor.h srcs/Input.cpp includes/Input.h)

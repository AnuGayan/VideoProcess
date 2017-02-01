cmake_minimum_required(VERSION 3.6)
project(PlaneCpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(PlaneCpp ${SOURCE_FILES})
find_package(OpenCV REQUIRED)
include_directories($(OpenCV_INCLUDE_DIRS))
target_link_libraries(PlaneCpp ${OpenCV_LIBS})
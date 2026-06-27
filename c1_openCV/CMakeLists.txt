cmake_minimum_required(VERSION 3.10)
project(OpenCV_Test)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV REQUIRED)

add_executable(my_opencv_app main.cpp)

target_include_directories(my_opencv_app PRIVATE ${OpenCV_INCLUDE_DIRS})

target_link_libraries(my_opencv_app ${OpenCV_LIBS})
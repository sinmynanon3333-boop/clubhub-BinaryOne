cmake_minimum_required(VERSION 3.15)
project(MyFltkApp CXX)
set(CMAKE_CXX_STANDARD 17)

find_package(FLTK CONFIG REQUIRED)
add_executable(app src/main.cpp)
target_include_directories(app PRIVATE src)
target_link_libraries(app PRIVATE fltk fltk_forms fltk_images comctl32 ws2_32)
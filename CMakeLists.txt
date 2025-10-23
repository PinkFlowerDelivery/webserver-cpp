cmake_minimum_required(VERSION 4.0)

project(Webserver VERSION 1.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(main src/main.cpp src/network/socket.cpp)

target_compile_options(main PRIVATE -g)

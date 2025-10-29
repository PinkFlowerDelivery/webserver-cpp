cmake_minimum_required(VERSION 4.0)

project(Webserver VERSION 1.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(main src/main.cpp src/network/Socket.cpp
                    src/protocol/ParseHttp.cpp)

include(FetchContent)

FetchContent_Declare(
  fmt
  GIT_REPOSITORY "https://github.com/fmtlib/fmt.git"
  GIT_TAG "12.0.0")

FetchContent_MakeAvailable(fmt)

target_link_libraries(main PUBLIC fmt::fmt)

target_compile_options(main PRIVATE -g)

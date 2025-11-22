cmake_minimum_required(VERSION 4.0)

project(Webserver VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_C_COMPILER clang)
set(CMAKE_CPP_COMPILER clang++)

add_executable(main src/main.cpp src/network/Socket.cpp
    src/protocol/HttpParser.cpp src/protocol/ParserUtils.cpp)

include(FetchContent)

FetchContent_Declare(
  fmt
  GIT_REPOSITORY "https://github.com/fmtlib/fmt.git"
  GIT_TAG "12.0.0")

FetchContent_Declare(
        json
        GIT_REPOSITORY "https://github.com/nlohmann/json.git"
        GIT_TAG "v3.12.0"
)

FetchContent_MakeAvailable(fmt json)

target_link_libraries(main PUBLIC fmt::fmt nlohmann_json::nlohmann_json)

target_compile_options(main PRIVATE -g)

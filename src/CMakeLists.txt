cmake_minimum_required(VERSION 3.5)
project(minecraft_server_launcher)
add_executable(minecraft_server_launcher main.cpp)
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")
add_definitions(-Wall -Wextra -O2)
add_subdirectory(menu)
target_include_directories(minecraft_server_launcher PUBLIC ${PROJECT_SOURCE_DIR})
target_link_libraries(minecraft_server_launcher menu -lncurses)
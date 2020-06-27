cmake_minimum_required(VERSION 3.13)
project(runtime_polymorphism)

set(CMAKE_CXX_STANDARD 17)

add_library(runtime_polymorphism library.hpp library.cpp)
add_executable(main client.cpp)

target_link_libraries(main runtime_polymorphism)
set_target_properties(main PROPERTIES LINKER_LANGUAGE CXX)

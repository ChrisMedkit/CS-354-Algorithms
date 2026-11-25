cmake_minimum_required(VERSION 3.20)
project(assignment CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()
add_compile_options(-Wall -Wextra -Wpedantic)

# Library code shared by the program and the tests (add .cpp files here)
add_library(core STATIC src/anagrams.cpp)
target_include_directories(core PUBLIC src)

add_executable(main src/main.cpp)
target_link_libraries(main PRIVATE core)

enable_testing()
add_executable(tests tests/test_main.cpp)
target_link_libraries(tests PRIVATE core)
add_test(NAME tests COMMAND tests)

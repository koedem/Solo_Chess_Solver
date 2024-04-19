cmake_minimum_required(VERSION 3.21)
project(Solo_Chess_Solver)

set(CMAKE_CXX_STANDARD 20)
add_compile_options(-ggdb -g3)
add_compile_definitions("NDEBUG")

set(CMAKE_CXX_FLAGS "-O3 -Wall -Wextra")
#set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic -ggdb -g3 -flto -march=native")

# Process Abseil's CMake build system
add_subdirectory(abseil-cpp)

add_executable(Solo_Chess_Solver main.cpp
        Board.h
        MoveGenerator.h
        Utils.h
        DFS.h
        Positions.h
        Hashtable.h
        Hashset.h)

# Declare dependency on the absl::strings library
target_link_libraries(Solo_Chess_Solver absl::flat_hash_map)
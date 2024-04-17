cmake_minimum_required(VERSION 3.27)
project(Solo_Chess_Solver)

set(CMAKE_CXX_STANDARD 20)

# Process Abseil's CMake build system
add_subdirectory(abseil-cpp)

add_executable(Solo_Chess_Solver main.cpp
        Board.h
        MoveGenerator.h
        Utils.h
        DFS.h
        Positions.h)

# Declare dependency on the absl::strings library
target_link_libraries(Solo_Chess_Solver absl::flat_hash_map)
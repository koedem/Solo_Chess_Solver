cmake_minimum_required(VERSION 3.21)
project(Solo_Chess_Solver)

set(CMAKE_CXX_STANDARD 20)
add_compile_options(-ggdb -g3)
add_compile_definitions("NDEBUG")

set(CMAKE_CXX_FLAGS "-O3 -Wall -Wextra")
# -fno-inline-functions
#set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic -ggdb -g3 -flto -march=native")

add_executable(Solo_Chess_Solver main.cpp
        Board.h
        MoveGenerator.h
        Utils.h
        DFS.h
        Positions.h
        Hashtable.h
        Hashset.h)

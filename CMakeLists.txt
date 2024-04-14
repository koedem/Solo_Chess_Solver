cmake_minimum_required(VERSION 3.27)
project(Solo_Chess_Solver)

set(CMAKE_CXX_STANDARD 20)

add_executable(Solo_Chess_Solver main.cpp
        Board.h
        MoveGenerator.h
        Utils.h)

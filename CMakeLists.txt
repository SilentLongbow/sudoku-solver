cmake_minimum_required(VERSION 4.1)
project(sudoku-solver)

set(CMAKE_CXX_STANDARD 23)

add_executable(sudoku-solver main.cpp "src/sudoku.cpp" "src/sudoku.h")
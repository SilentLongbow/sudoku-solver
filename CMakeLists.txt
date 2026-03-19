cmake_minimum_required(VERSION 3.3)
project(sudoku-solver)

set(CMAKE_CXX_STANDARD 23)

add_executable(sudoku-solver "src/main.cpp" "src/sudoku.cpp" "src/sudoku.h")
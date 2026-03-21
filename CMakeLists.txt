cmake_minimum_required(VERSION 3.10)
project(sudoku-solver)

set(CMAKE_CXX_STANDARD 23)

add_executable(${PROJECT_NAME} "src/main.cpp" "src/sudoku.cpp" "src/sudoku.h")

find_package(glaze REQUIRED)
target_link_libraries(${PROJECT_NAME} glaze::glaze)
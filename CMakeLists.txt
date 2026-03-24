cmake_minimum_required(VERSION 3.10)
project(sudoku-solver)

set(CMAKE_CXX_STANDARD 23)

option(CMAKE_COMPILE_WARNING_AS_ERROR "Compile warnings as errors" ON)

add_executable(${PROJECT_NAME}  "src/sudoku-solver.cpp"  "src/json_handling.cpp" "src/json_handling.h")

find_package(glaze REQUIRED)
find_package(gtest REQUIRED)
target_link_libraries(${PROJECT_NAME} glaze::glaze gtest::gtest)
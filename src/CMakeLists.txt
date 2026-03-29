cmake_minimum_required(VERSION 3.20)
project(sudoku-solver)
set(SOLVER_LIBRARY solver)

set(CMAKE_CXX_STANDARD 23)
option(CMAKE_COMPILE_WARNING_AS_ERROR "Compile warnings as errors" ON)

# Put the actual logic behind a library - helps with testing for example
add_library(${SOLVER_LIBRARY} STATIC json_handling.cpp json_handling.h solving_logic.cpp solving_logic.h puzzle_type.h)
find_package(glaze REQUIRED)
target_link_libraries(${SOLVER_LIBRARY} PRIVATE glaze::glaze)

# Then the executable is 'just' main with the library statically linked
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE ${SOLVER_LIBRARY})

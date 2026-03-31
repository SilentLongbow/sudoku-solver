cmake_minimum_required(VERSION 3.20)
project(Sudoku-Solver)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
	
endif()

set(CMAKE_CXX_STANDARD 23)
option(CMAKE_COMPILE_WARNING_AS_ERROR "Compile warnings as errors" ON)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Sudoku Solver
add_subdirectory(src)

# Unit tests
add_subdirectory(tests)
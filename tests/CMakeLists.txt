cmake_minimum_required(VERSION 3.20)
project(gtests)

set(CMAKE_CXX_STANDARD 23)
option(CMAKE_COMPILE_WARNING_AS_ERROR "Compile warnings as errors" ON)


# Get paths for the code we want to test
set(SUDOKU_SOLVER_LIBRARY_NAME solver)
set(SOLVER_SRC_DIR  "${CMAKE_SOURCE_DIR}/src")

# Unit tests
add_executable(${PROJECT_NAME} "solving_logic_test.cpp" "json_handling_test.cpp")

# TODO: See if I can get away without using target_include_directories. I might not be able to of course
target_include_directories(${PROJECT_NAME} PUBLIC ${SOLVER_SRC_DIR})
target_link_libraries(${PROJECT_NAME} PUBLIC ${SUDOKU_SOLVER_LIBRARY_NAME})


find_package(gtest REQUIRED)
target_link_libraries(${PROJECT_NAME} PUBLIC gtest::gtest)

set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER Tests)
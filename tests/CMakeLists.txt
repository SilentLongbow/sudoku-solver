cmake_minimum_required(VERSION 3.20)
project(GTests)

include(CMakePrintHelpers)

set(CMAKE_CXX_STANDARD 23)
option(CMAKE_COMPILE_WARNING_AS_ERROR "Compile warnings as errors" ON)

# Get paths for the code we want to test
set(SUDOKU_SOLVER_LIBRARY_NAME solver)
set(SOLVER_SRC_DIR  "C:/Users/mattj/source/sudoku-solver/src")
message("==================================================${SOLVER_SRC_DIR}")
set(SOURCE_HEADER_FILES "${SOLVER_SRC_DIR}/json_handling.h" "${SOLVER_SRC_DIR}/solving_logic.h" "${SOLVER_SRC_DIR}/puzzle_type.h")


# Unit tests
add_executable(${PROJECT_NAME} "solving_logic_test.cpp" "json_handling_test.cpp" "${SOURCE_HEADER_FILES}")

target_include_directories(${PROJECT_NAME} PUBLIC "../src")
target_link_libraries(${PROJECT_NAME} PUBLIC ${SUDOKU_SOLVER_LIBRARY_NAME})
set_property(TARGET ${PROJECT_NAME} APPEND PROPERTY INCLUDE_DIRECTORIES ${SOLVER_SOURCE_DIR})


find_package(gtest REQUIRED)
target_link_libraries(${PROJECT_NAME} PUBLIC gtest::gtest)

cmake_print_properties(TARGETS ${PROJECT_NAME} PROPERTIES INCLUDE_DIRECTORIES LINK_DIRECTORIES)

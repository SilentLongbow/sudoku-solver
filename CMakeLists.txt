cmake_minimum_required(VERSION 3.10)
project(sudoku-solver)

set(CMAKE_CXX_STANDARD 23)

option(CMAKE_COMPILE_WARNING_AS_ERROR "Compile warnings as errors" ON)

add_executable(${PROJECT_NAME}  "src/sudoku-solver.cpp"  "src/json_handling.cpp" "src/json_handling.h" "src/solving_logic.cpp" "src/solving_logic.h")

find_package(glaze REQUIRED)
find_package(gtest REQUIRED)

target_link_libraries(${PROJECT_NAME} glaze::glaze gtest::gtest)

# An attempt at being smart and copying over the test data for easy access at runtime. This didn't work and should be set for unit tests anyway
#
#	add_custom_command(
#		TARGET ${PROJECT_NAME} POST_BUILD
#		COMMAND ${CMAKE_COMMAND} -E copy
#		${CMAKE_CURRENT_SOURCE_DIR}/test_data/
#		$<TARGET_FILE_DIR:${PROJECT_NAME}>)
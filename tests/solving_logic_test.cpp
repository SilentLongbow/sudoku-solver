#include <gtest/gtest.h>

#include <ranges>

#include "puzzle_type.h"
#include "solving_logic.h"

TEST(SolvingLogic, BacktrackingSolvesTrickyPuzzle) {
  SudokuPuzzle puzzle = {
    .puzzle_data = {
        0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 3, 0, 8, 5,
        0, 0, 1, 0, 2, 0, 0, 0, 0,
        0, 0, 0, 5, 0, 7, 0, 0, 0,
        0, 0, 4, 0, 0, 0, 1, 0, 0,
        0, 9, 0, 0, 0, 0, 0, 0, 0,
        5, 0, 0, 0, 0, 0, 0, 7, 3,
        0, 0, 2, 0, 1, 0, 0, 0, 0,
        0, 0, 0, 0, 4, 0, 0, 0, 9
    }
  };

  std::vector<int> expected_solved_result = {
    9, 8, 7, 6, 5, 4, 3, 2, 1,
    2, 4, 6, 1, 7, 3, 9, 8, 5,
    3, 5, 1, 9, 2, 8, 7, 4, 6,
    1, 2, 8, 5, 3, 7, 6, 9, 4,
    6, 3, 4, 8, 9, 2, 1, 5, 7,
    7, 9, 5, 4, 6, 1, 8, 3, 2,
    5, 1, 9, 2, 8, 6, 4, 7, 3,
    4, 7, 2, 3, 1, 9, 5, 6, 8,
    8, 6, 3, 7, 4, 5, 2, 1, 9
  };

  sudoku::backtracking_solver(puzzle);
  auto first_zero = std::find(puzzle.puzzle_data.begin(), puzzle.puzzle_data.end(), 0);
  EXPECT_EQ(first_zero, puzzle.puzzle_data.end()) << "The solved puzzle must not have any cells containing '0'";
  EXPECT_EQ(puzzle.puzzle_data, expected_solved_result);
}

TEST(SolvingLogic, CorrectlyGetsRowIndices)
{
  constexpr int position = 34;
  const std::vector<int> expected_row_positions = std::views::iota(27, 36) | std::ranges::to<std::vector>();

  const auto actual_row_positions = sudoku::indices_for_row_at(position);
  EXPECT_EQ(actual_row_positions, expected_row_positions);
}

TEST(SolvingLogic, CorrectlyGetsColumnIndices)
{
  constexpr int position = 34;
  const std::vector<int> expected_column_positions{ 7, 16, 25, 34, 43, 52, 61, 70, 79 };

  const auto actual_column_positions = sudoku::indices_for_column_at(position);
  EXPECT_EQ(actual_column_positions, expected_column_positions);
}

TEST(SolvingLogic, CorrectlyGetsBlockIndices)
{
  constexpr int position = 34;
  const std::vector<int> expected_block_positions{ 33, 34, 35, 42, 43, 44, 51, 52, 53 };

  const auto actual_block_positions = sudoku::indices_for_block_at(position);
  EXPECT_EQ(actual_block_positions, expected_block_positions);
}
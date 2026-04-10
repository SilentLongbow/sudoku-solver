#pragma once

#include "puzzle_type.h"

namespace sudoku
{
	// assumes a 9x9 sudoku grid
	std::vector<int> indices_for_block_at(const int position);
	std::vector<int> indices_for_row_at(const int position);
	std::vector<int> indices_for_column_at(const int position);

	void backtracking_solver(SudokuPuzzle& puzzle);

	// Takes a Sudoku puzzle arranged in row-major order and solves it by breaking
	// the puzzle down into views within row, column and block context.
	// The puzzle is update in-place, and the function returns whether the puzzle
	// was solved/is solvable.
	bool solve_puzzle(SudokuPuzzle& puzzle);
}

#pragma once

#include "puzzle_type.h"

namespace sudoku {
	
	// Takes a Sudoku puzzle arranged in row-major order and solves it by breaking
	// the puzzle down into views within row, column and block context
	void solve_puzzle(SudokuPuzzle& sudoku_puzzle);
}

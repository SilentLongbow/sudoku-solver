#pragma once

#include <optional>
#include <string>
#include <vector>

struct SudokuPuzzle {
	std::vector<std::vector<int>> puzzle_data;
};

bool puzzle_validity(SudokuPuzzle puzzle);
SudokuPuzzle read_puzzle_json(std::string_view);
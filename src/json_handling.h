#pragma once

#include <optional>
#include <string>
#include <vector>

#include "puzzle_type.h"

namespace input {
	bool puzzle_validity(SudokuPuzzle puzzle);
	SudokuPuzzle read_puzzle_json(std::string_view);
}
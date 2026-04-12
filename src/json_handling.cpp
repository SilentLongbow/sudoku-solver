#include "json_handling.h"

#include <glaze/glaze.hpp>
#include <vector>
#include <format>
#include <iostream>
#include <print>

bool input::puzzle_validity(SudokuPuzzle puzzle) {
	return false;
}

// Just thinking here. It might be best for me to make use of the two separate library functions:
// - Read the file and store it in memory as a json represntation
// - Pack the json data into a structure
// This would make that bit of the code easier to test. But at that point I would be testing the library and not my code.
// It would help add a layer that I can make use of for testing though.
// Maybe at a later date

SudokuPuzzle input::read_puzzle_json(std::string_view filename) {
	std::string input_buffer{};
	SudokuPuzzle loaded_puzzle;

	auto error_code = glz::read_file_json(loaded_puzzle, filename, std::string{});
	if (error_code) {
		std::cerr << glz::format_error(error_code, filename) << std::endl;
	}
	
	return loaded_puzzle;
}
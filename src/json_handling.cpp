#include "json_handling.h"

#include <glaze/glaze.hpp>
#include <vector>
#include <format>
#include <iostream>
#include <print>

bool input::puzzle_validity(SudokuPuzzle puzzle) {
	return false;
}


SudokuPuzzle input::read_puzzle_json(std::string_view filename) {
	std::string input_buffer{};
	SudokuPuzzle loaded_puzzle;

	auto error_code = glz::read_file_json(loaded_puzzle, filename, std::string{});
	if (error_code) {
		std::cerr << glz::format_error(error_code, filename) << std::endl;
	}
	
	return loaded_puzzle;
}
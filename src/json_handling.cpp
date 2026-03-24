#include "json_handling.h"

#include <glaze/glaze.hpp>
#include <vector>
#include <format>
#include <iostream>

bool puzzle_validity(SudokuPuzzle puzzle) {
	return false;
}


SudokuPuzzle read_puzzle_json(std::string_view file_name) {
	std::string input_buffer{};
	SudokuPuzzle simple_puzzle;

	auto error_code = glz::read_file_json(simple_puzzle, file_name, std::string{});
	if (!error_code) {
		simple_puzzle.puzzle_data;
		for (int i = 0; i < simple_puzzle.puzzle_data.size(); i++) {
			for (int j = 0; j < simple_puzzle.puzzle_data[i].size(); j++) {

			}
		}
	}
	else {
		std::string something_bad = std::format("Issue reading the JSON file '{}'. Error is: {}", file_name, static_cast<int>(error_code.ec));
		std::cerr << something_bad << std::endl;
	}
	SudokuPuzzle puzzle = { .puzzle_data = {} };
	return puzzle;
}
#include <filesystem>
#include <format>
#include <iostream>
#include <print>
#include <vector>
#ifdef WIN32
#include <Windows.h>
#endif


#include "json_handling.h"
#include "solving_logic.h"

// This is a very basic argument parsing function that doesn't pick up POSIX-style arguments such as -rm,
// -r -m would need to be used. This is 'stolen' from 
// https://stackoverflow.com/questions/865668/parsing-command-line-arguments-in-c
bool option_exists(char** begin, char** end, const std::string& option) {
	return std::find(begin, end, option) != end;
}

char* get_command_line_option(char** begin, char** end, const std::string& option) {
	auto option_in_argv = std::find(begin, end, option);

	// for a given known option, --option <value>, if we've found option, we need to make
	// sure that <value> is also there after it.
	if (option_in_argv != end && ++option_in_argv != end) {
		return *option_in_argv;
	}
	return 0;
}

int main(int argc, char* argv[]) {
	std::filesystem::path input_file{};
	if (option_exists(argv, argv + argc, "--test_file")) {
		input_file = get_command_line_option(argv, argv + argc, "--test_file");
	}
	else {
		input_file = std::filesystem::current_path() / ".." / "test_data" / "no_puzzle.json";
	}
	if (input_file.is_relative()) {
		input_file = std::filesystem::current_path() / input_file;
	}

	auto file_exists = std::filesystem::exists(input_file);
	if (!file_exists) {
		std::println(stderr, "File at path '{}' does not exist", input_file.string());
		return -1;
	}

	auto puzzle = input::read_puzzle_json(input_file.string());
	sudoku::solve_puzzle(puzzle);
}
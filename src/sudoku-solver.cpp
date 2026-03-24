#include <filesystem>
#include <format>
#include <iostream>
#include <vector>

#include "json_handling.h"

constexpr std::string_view path_from_current_to_base = "../../";

int main() {
	auto puzzle = read_puzzle_json(std::format("{}{}", path_from_current_to_base, "test_data/single_puzzle.json"));
}
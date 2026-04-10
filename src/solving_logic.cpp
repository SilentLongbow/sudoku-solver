#include "solving_logic.h"

#include <cmath>
#include <ranges>
#include <vector>

#include "puzzle_type.h"

namespace
{
	constexpr int PUZZLE_EDGE_LENGTH = 9;
	constexpr int BLOCK_EDGE_LENGTH = 3;
}

// assumes a 9x9 sudoku grid
std::vector<int> sudoku::indices_for_block_at(const int position)
{
	const auto position_column = position % PUZZLE_EDGE_LENGTH;
	const auto block_column_number = std::floor(static_cast<double>(position_column) / BLOCK_EDGE_LENGTH);

	const auto position_row = std::floor(static_cast<double>(position) / PUZZLE_EDGE_LENGTH);
	const auto block_row_number = std::floor(static_cast<double>(position_row) / BLOCK_EDGE_LENGTH);

	int top_left = 0 + (BLOCK_EDGE_LENGTH * block_column_number) /* * some row multiplier? */;
	int bottom_right = (2 + (BLOCK_EDGE_LENGTH * block_column_number)) + (2);
	return std::vector<int>{};
}

// assumes a 9x9 sudoku grid
std::vector<int> sudoku::indices_for_row_at(const int position)
{
	const int row_number = std::floor(static_cast<double>(position) / PUZZLE_EDGE_LENGTH);
	auto row_indices = std::views::iota(0, PUZZLE_EDGE_LENGTH)
		| std::views::transform([row_number](int value) { return value + (PUZZLE_EDGE_LENGTH * row_number); })
		| std::ranges::to<std::vector>();
	return row_indices;
}

// assumes a 9x9 sudoku grid
std::vector<int> sudoku::indices_for_column_at(const int position)
{
	const int column_number = position % PUZZLE_EDGE_LENGTH;
	auto column_indices = std::views::iota(0, PUZZLE_EDGE_LENGTH)
		| std::views::transform([column_number](int value) { return column_number + (value * PUZZLE_EDGE_LENGTH); })
		| std::ranges::to<std::vector>();
	return column_indices;
}

bool value_is_valid_for_position(const SudokuPuzzle& puzzle, const int value, const int positon)
{
}

void sudoku::backtracking_solver(SudokuPuzzle& puzzle)
{
	std::vector<size_t> already_filled_indices{};
	already_filled_indices.reserve(puzzle.puzzle_data.size());

	for (int i = 0; i < puzzle.puzzle_data.size(); ++i)
	{
		if (puzzle.puzzle_data.at(i) != 0)
		{
			already_filled_indices.push_back(i);
		}
	}
	already_filled_indices.shrink_to_fit();

	int i = 0;
	int index_progression = 1;
	int next_value_to_insert = 1;
	while (0 >= i && i < puzzle.puzzle_data.size())
	{
		if (std::find(already_filled_indices.begin(), already_filled_indices.end(), i) != already_filled_indices.end())
		{
			i += index_progression;
			continue;
		}

		puzzle.puzzle_data[i] = next_value_to_insert;
		++next_value_to_insert;


		i += index_progression;
	}

}

bool sudoku::solve_puzzle(SudokuPuzzle& puzzle)
{
	if (puzzle.puzzle_data.empty())
	{
		return false;
	}

	return false;
}


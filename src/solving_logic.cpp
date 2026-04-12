#include "solving_logic.h"

#include <algorithm>
#include <cmath>
#include <ranges>
#include <vector>

#include "puzzle_type.h"

namespace
{
	constexpr int PUZZLE_EDGE_LENGTH = 9;
	constexpr int BLOCK_EDGE_LENGTH = 3;
}

bool value_present_in_indices(const SudokuPuzzle& puzzle, const int value, std::vector<int> indices)
{
	for (auto index : indices)
	{
		if (puzzle.puzzle_data.at(index) == value)
		{
			return true;
		}
	}
	return false;
}

// assumes a 9x9 sudoku grid
// It is worth investigating std::views::chunk_view for future reference.
std::vector<int> sudoku::indices_for_block_at(const int position)
{
	constexpr int indices_to_skip_per_block_row = PUZZLE_EDGE_LENGTH * BLOCK_EDGE_LENGTH;

	const auto position_column = position % PUZZLE_EDGE_LENGTH;
	const auto block_column_number = static_cast<int>(std::floor(static_cast<double>(position_column) / BLOCK_EDGE_LENGTH));

	const auto position_row = static_cast<int>(std::floor(static_cast<double>(position) / PUZZLE_EDGE_LENGTH));
	const auto block_row_number = static_cast<int>(std::floor(static_cast<double>(position_row) / BLOCK_EDGE_LENGTH));

	// I want to redo this. But for now it works.
	auto top_row = std::views::iota(0, 3)
							 | std::views::transform
								 (
									 [block_column_number, block_row_number, indices_to_skip_per_block_row](int index)
									 {
										 return index + (BLOCK_EDGE_LENGTH * block_column_number) + (block_row_number * indices_to_skip_per_block_row);
									 }
								 );
	auto middle_row = top_row | std::views::transform([](int index) { return index + PUZZLE_EDGE_LENGTH; });
	auto bottom_row = top_row | std::views::transform([](int index) { return index + (PUZZLE_EDGE_LENGTH * 2); });
	std::vector<int> block_indices{};
	block_indices.reserve(BLOCK_EDGE_LENGTH ^ 2);
	
	block_indices.append_range(top_row);
	block_indices.append_range(middle_row);
	block_indices.append_range(bottom_row);
	return block_indices;
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

bool sudoku::value_is_valid_for_position(const SudokuPuzzle& puzzle, const int value, const int position)
{
	auto row_indices = indices_for_row_at(position);
	auto column_indices = indices_for_column_at(position);
	auto block_indices = indices_for_block_at(position);

	bool value_already_present = value_present_in_indices(puzzle, value, row_indices)
		|| value_present_in_indices(puzzle, value, column_indices)
		|| value_present_in_indices(puzzle, value, block_indices);
	
	return !value_already_present;
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


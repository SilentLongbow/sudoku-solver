#include <gtest/gtest.h>

#include "puzzle_type.h"
#include "json_handling.h"

// Should this actually be how I do this? I would almost
// want a status returned too...
TEST(JSONLoadingTest, NoFilenameGivesEmptyPuzzle) {
	auto puzzle = input::read_puzzle_json("");
	EXPECT_TRUE(puzzle.puzzle_data.empty());
}
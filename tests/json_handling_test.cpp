#include <gtest/gtest.h>

#include "../src/puzzle_type.h"
#include "../src/json_handling.h"



TEST(JSONLoadingTest, InvalidJSONTableGivesAllZeros) {
	auto puzzle = input::read_puzzle_json("")
}
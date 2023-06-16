#include "pch.h"

TEST(test_grid_to_str, flat_and_map) {
	/*
	A grid and its flattened string are provided
	`grid_to_str()` is called to check if 
	flattening and character-mapping work properly
	*/
	int grid[9][9] = {
		{0, 1, 2, 3, 4, 5, 6, 7, 8},
		{9, 0, 1, 2, 3, 4, 5, 6, 7},
		{8, 9, 0, 1, 2, 3, 4, 5, 6},
		{7, 8, 9, 0, 1, 2, 3, 4, 5},
		{6, 7, 8, 9, 0, 1, 2, 3, 4},
		{5, 6, 7, 8, 9, 0, 1, 2, 3},
		{4, 5, 6, 7, 8, 9, 0, 1, 2},
		{3, 4, 5, 6, 7, 8, 9, 0, 1},
		{2, 3, 4, 5, 6, 7, 8, 9, 0},
	};
	char grid_str_ans[82] = {
		"$12345678"
		"9$1234567"
		"89$123456"
		"789$12345"
		"6789$1234"
		"56789$123"
		"456789$12"
		"3456789$1"
		"23456789$"
	};
	char grid_str[81];
	Sudoku s;
	s.grid_to_str(grid, grid_str);
	char* test_ptr = grid_str;
	char* ans_ptr = grid_str_ans;
	for (int i = 0; i < 81; i++) {
		EXPECT_EQ(*test_ptr++, *ans_ptr++);
	}
}

TEST(test_safe_check, row_col_box_check) {
	/*
	Some values are set in the first box ( from (0, 0) to (2, 2) )
	Following tests check whether 
	inserting a num into specific coordinate is safe
	*/
	int grid[9][9] = {
		      /* 0  1  2  3  4  5  6  7  8 */
		/* 0 */ {0, 1, 0, 0, 0, 0, 0, 0, 0},
		/* 1 */ {0, 0, 0, 0, 0, 0, 0, 0, 0},
		/* 2 */ {0, 0, 2, 0, 0, 0, 0, 0, 0},
		/* 3 */ {0, 0, 0, 0, 0, 0, 0, 0, 0},
		/* 4 */ {0, 0, 0, 0, 0, 0, 0, 0, 0},
		/* 5 */ {0, 0, 0, 0, 0, 0, 0, 0, 0},
		/* 6 */ {0, 0, 0, 0, 0, 0, 0, 0, 0},
		/* 7 */ {0, 0, 0, 0, 0, 0, 0, 0, 0},
		/* 8 */ {0, 0, 0, 0, 0, 0, 0, 0, 0},
	};
	Sudoku s;
	EXPECT_EQ(s.row_safe(grid, 1, 0, 0), false);	// row check: 1 cannot be inserted into (0, 0)
	EXPECT_EQ(s.row_safe(grid, 1, 1, 0), true);		// row check: 1 can    be inserted into (1, 0)
	EXPECT_EQ(s.row_safe(grid, 1, 2, 0), true);		// row check: 1 can    be inserted into (2, 0)
	EXPECT_EQ(s.col_safe(grid, 2, 0, 2), false);	// col check: 2 cannot be inserted into (0, 2)
	EXPECT_EQ(s.col_safe(grid, 2, 0, 3), true);		// col check: 2 can    be inserted into (0, 3)
	EXPECT_EQ(s.col_safe(grid, 3, 5, 5), true);		// col check: 3 can    be inserted into (5, 5)
	EXPECT_EQ(s.box_safe(grid, 1, 1, 0), false);	// box check: 1 cannot be inserted into (1, 0)
	EXPECT_EQ(s.box_safe(grid, 3, 1, 0), true);		// box check: 3 can    be inserted into (1, 0)
	EXPECT_EQ(s.safe_check(grid, 2, 3, 2), false);	// all check: 2 cannot be inserted into (3, 2)
	EXPECT_EQ(s.safe_check(grid, 4, 1, 2), true);	// all check: 4 can    be inserted into (1, 2)
}
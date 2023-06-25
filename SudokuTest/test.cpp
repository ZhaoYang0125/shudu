#include "pch.h"

TEST(test_board_to_str, check_char_map) 
{
	/*
	A board and its flattened string are provided
	`board_to_str()` is called to check if 
	flattening and character-mapping work properly
	*/
	int board[9][9] = {
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
	char board_str_ans[82] = {
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
	char board_str[81];
	Sudoku s;
	s.board_to_str(board, board_str);
	char* test_ptr = board_str;
	char* ans_ptr = board_str_ans;
	for (int i = 0; i < 81; i++) {
		EXPECT_EQ(*test_ptr++, *ans_ptr++);
	}
}

TEST(test_safe_check, row_check) 
{
	/*
	Some values are set in the first box ( from (0, 0) to (2, 2) )
	Following tests check whether 
	inserting a num into specific coordinate is safe
	*/
	int board[9][9] = {
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
	EXPECT_EQ(s.row_safe(board, 1, 0, 0), false);		// row check: 1 cannot be inserted into (0, 0)
	EXPECT_EQ(s.row_safe(board, 1, 1, 0), true);		// row check: 1 can    be inserted into (1, 0)
	EXPECT_EQ(s.row_safe(board, 1, 2, 0), true);		// row check: 1 can    be inserted into (2, 0)
}

TEST(test_safe_check, col_check)
{
	/*
	Some values are set in the first box ( from (0, 0) to (2, 2) )
	Following tests check whether
	inserting a num into specific coordinate is safe
	*/
	int board[9][9] = {
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
	EXPECT_EQ(s.col_safe(board, 2, 0, 2), false);		// col check: 2 cannot be inserted into (0, 2)
	EXPECT_EQ(s.col_safe(board, 2, 0, 3), true);		// col check: 2 can    be inserted into (0, 3)
	EXPECT_EQ(s.col_safe(board, 3, 5, 5), true);		// col check: 3 can    be inserted into (5, 5)
}

TEST(test_safe_check, box_check)
{
	/*
	Some values are set in the first box ( from (0, 0) to (2, 2) )
	Following tests check whether
	inserting a num into specific coordinate is safe
	*/
	int board[9][9] = {
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
	EXPECT_EQ(s.box_safe(board, 1, 1, 0), false);		// box check: 1 cannot be inserted into (1, 0)
	EXPECT_EQ(s.box_safe(board, 3, 1, 0), true);		// box check: 3 can    be inserted into (1, 0)
}

TEST(test_safe_check, all_check)
{
	/*
	Some values are set in the first box ( from (0, 0) to (2, 2) )
	Following tests check whether
	inserting a num into specific coordinate is safe
	*/
	int board[9][9] = {
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
	EXPECT_EQ(s.safe_check(board, 2, 3, 2), false);		// all check: 2 cannot be inserted into (3, 2)
	EXPECT_EQ(s.safe_check(board, 4, 1, 2), true);		// all check: 4 can    be inserted into (1, 2)
}

TEST(test_get_next, get_blank)
{
	/*
	Use a board set with some values to test search result.
	*/
	Sudoku s;
	int r, c;

	int board0[9][9] = {
		/*       0  1  2  3  4  5  6  7  8 */
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
	EXPECT_EQ(s.get_next(board0, &r, &c, true), true);	// a blank at (0, 0) will be found
	EXPECT_EQ(r, 0);
	EXPECT_EQ(c, 0);

	int board1[9][9] = {
		/*       0  1  2  3  4  5  6  7  8 */
		/* 0 */ {3, 1, 0, 0, 0, 0, 0, 0, 0},
		/* 1 */ {0, 0, 0, 0, 0, 0, 0, 0, 0},
		/* 2 */ {0, 0, 2, 0, 0, 0, 0, 0, 0},
		/* 3 */ {0, 0, 0, 0, 0, 0, 0, 0, 0},
		/* 4 */ {0, 0, 0, 0, 0, 0, 0, 0, 0},
		/* 5 */ {0, 0, 0, 0, 0, 0, 0, 0, 0},
		/* 6 */ {0, 0, 0, 0, 0, 0, 0, 0, 0},
		/* 7 */ {0, 0, 0, 0, 0, 0, 0, 0, 0},
		/* 8 */ {0, 0, 0, 0, 0, 0, 0, 0, 0},
	};
	EXPECT_EQ(s.get_next(board1, &r, &c, true), true);	// a blank at (0, 2) will be found
	EXPECT_EQ(r, 0);
	EXPECT_EQ(c, 2);

	int board2[9][9] = {
		/*       0  1  2  3  4  5  6  7  8 */
		/* 0 */ {3, 1, 4, 2, 5, 6, 7, 8, 9},
		/* 1 */ {0, 0, 0, 0, 0, 0, 0, 0, 0},
		/* 2 */ {0, 0, 2, 0, 0, 0, 0, 0, 0},
		/* 3 */ {0, 0, 0, 0, 0, 0, 0, 0, 0},
		/* 4 */ {0, 0, 0, 0, 0, 0, 0, 0, 0},
		/* 5 */ {0, 0, 0, 0, 0, 0, 0, 0, 0},
		/* 6 */ {0, 0, 0, 0, 0, 0, 0, 0, 0},
		/* 7 */ {0, 0, 0, 0, 0, 0, 0, 0, 0},
		/* 8 */ {0, 0, 0, 0, 0, 0, 0, 0, 0},
	};
	EXPECT_EQ(s.get_next(board2, &r, &c, true), true);	// a blank at (0, 2) will be found
	EXPECT_EQ(r, 1);
	EXPECT_EQ(c, 0);

	int board3[9][9] = {
		/*       0  1  2  3  4  5  6  7  8 */
		/* 0 */ {1, 1, 1, 1, 1, 1, 1, 1, 1},
		/* 1 */ {1, 1, 1, 1, 1, 1, 1, 1, 1},
		/* 2 */ {1, 1, 1, 1, 1, 1, 1, 1, 1},
		/* 3 */ {1, 1, 1, 1, 1, 1, 1, 1, 1},
		/* 4 */ {1, 1, 1, 1, 1, 1, 1, 1, 1},
		/* 5 */ {1, 1, 1, 1, 1, 1, 1, 1, 1},
		/* 6 */ {1, 1, 1, 1, 1, 1, 1, 1, 1},
		/* 7 */ {1, 1, 1, 1, 1, 1, 1, 1, 1},
		/* 8 */ {1, 1, 1, 1, 1, 1, 1, 1, 1},
	};
	EXPECT_EQ(s.get_next(board3, &r, &c, true), false);	// no blank
}

TEST(test_backtracking_fill, check_no_confics)
{
	// Generate a finale and check if it is valid

	int n_finale = 1;					// number of final results
	char* input = nullptr;				// file path of games (both relative and absolute path are ok)
	int n_puzzle = 0;					// number of games to be generated
	int difficulty = MIN_DIFFICULTY;	// difficulty (easy, middle or hard, default is easy)
	int n_blank = MIN_BLANK;			// number of blanks
	bool unique = false;				// whether solution is unique (default is not)

	Sudoku s;
	s.init(n_finale, input, n_puzzle, difficulty, n_blank, unique);
	int board[9][9];
	s.empty_board(board);
	s.backtracking_fill(board);
	int* ptr = nullptr;
	for (int i = 0; i < 9; i++) {
		ptr = board[i];
		for (int j = 0; j < 9; j++) {
			int tmp = *ptr;
			*ptr++ = 0;
			EXPECT_EQ(s.safe_check(board, tmp, i, j), true);
		}
	}
}

//TEST(test_backtracking_fill, check_solution_count)
//{
//	// Generate a finale and check if it is valid
//	int n_finale = 0;					// number of final results
//	char* input = nullptr;				// file path of games (both relative and absolute path are ok)
//	int n_puzzle = 1;					// number of games to be generated
//	int difficulty = MIN_DIFFICULTY;	// difficulty (easy, middle or hard, default is easy)
//	int n_blank = MIN_BLANK;			// number of blanks
//	bool unique = false;				// whether solution is unique (default is not)
//
//	Sudoku s;
//	s.init(n_finale, input, n_puzzle, difficulty, n_blank, unique);
//	int board[9][9];
//	int n_solution = 0;
//	bool early_stop = false;
//	while (n_solution <= 1) {	// theoretically more than one solution `can` be found
//		s.gen_puzzle(board);
//		s.backtracking_fill(board, early_stop, &n_solution);
//	}
//	EXPECT_EQ(true, true);	// while reaching here, a puzzle has more than one solution
//}

TEST(test_native_poke, check_uniqueness)
{
	// Since the test metioned above works, we use backtracking filling method to 
	// check if unique puzzles will be generated as required.
	int n_finale = 0;					// number of final results
	char* input = nullptr;				// file path of games (both relative and absolute path are ok)
	int n_puzzle = 1;					// number of games to be generated
	int difficulty = MIN_DIFFICULTY;	// difficulty (easy, middle or hard, default is easy)
	int n_blank = MIN_BLANK;			// number of blanks
	bool unique = true;					// whether solution is unique (default is not)

	int max_test_times = 100;

	Sudoku s;
	s.init(n_finale, input, n_puzzle, difficulty, n_blank, unique);
	int board[9][9];
	int n_solution = 1;
	for (int i = 0; i < max_test_times; i++) {
		s.naive_poke(board);			// since `unique` is true, only one-solution puzzle will be generated
		s.backtracking_fill(board, false, &n_solution);
		if (n_solution >= 2) {
			break;
		}
	}
	EXPECT_EQ(n_solution, 1);	// while reaching here, `max_test_times` is ran out
}

TEST(test_native_poke, check_n_blanks)
{
	int n_finale = 0;					// number of final results
	char* input = nullptr;				// file path of games (both relative and absolute path are ok)
	int n_puzzle = 1;					// number of games to be generated
	int difficulty = MIN_DIFFICULTY;	// difficulty (easy, middle or hard, default is easy)
	int n_blank = MIN_BLANK;			// number of blanks
	bool unique = true;					// whether solution is unique (default is not)

	Sudoku s;
	int board[9][9];
	while (n_blank <= MAX_BLANK) {
		s.init(n_finale, input, n_puzzle, difficulty, n_blank, unique);
		s.naive_poke(board);
		int n_board_blanks = s.get_board_blanks(board);
		EXPECT_EQ(n_board_blanks, n_blank);
		n_blank++;
	}
}

TEST(test_native_poke, check_difficulty)
{
	int n_finale = 0;					// number of final results
	char* input = nullptr;				// file path of games (both relative and absolute path are ok)
	int n_puzzle = 1;					// number of games to be generated
	int difficulty = MIN_DIFFICULTY;	// difficulty (easy, middle or hard, default is easy)
	int n_blank = MIN_BLANK;			// number of blanks
	bool unique = true;					// whether solution is unique (default is not)

	int max_test_times = 10;

	Sudoku s;
	int board[9][9];
	for (int i = 0; i < max_test_times; i++) {
		for (int j = MIN_DIFFICULTY; j <= MAX_DIFFICULTY; j++) {
			difficulty = j;
			s.init(n_finale, input, n_puzzle, difficulty, n_blank, unique);
			s.naive_poke(board);
			int puzzle_difficulty = s.analyze_difficulty(board);
			EXPECT_EQ(puzzle_difficulty, difficulty);
		}
	}
}

TEST(test_native_poke, check_n_blanks_and_difficulty)
{
	int n_finale = 0;					// number of final results
	char* input = nullptr;				// file path of games (both relative and absolute path are ok)
	int n_puzzle = 1;					// number of games to be generated
	int difficulty = MIN_DIFFICULTY;	// difficulty (easy, middle or hard, default is easy)
	int n_blank = MIN_BLANK;			// number of blanks
	bool unique = true;					// whether solution is unique (default is not)

	Sudoku s;
	int board[9][9];
	for (int i = MIN_BLANK; i <= MAX_BLANK; i++) {
		n_blank = i;
		for (int j = MIN_DIFFICULTY; j <= MAX_DIFFICULTY; j++) {
			difficulty = j;
			s.init(n_finale, input, n_puzzle, difficulty, n_blank, unique);
			s.naive_poke(board);
			int puzzle_difficulty = s.analyze_difficulty(board);
			int board_blanks = s.get_board_blanks(board);
			EXPECT_EQ(puzzle_difficulty, difficulty);
			EXPECT_EQ(board_blanks, n_blank);
		}
	}
}
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include "Sudoku.h"

//#define DEBUG_TEST
//#define DEBUG_TEST_GEN_FINALE
#define DEBUG_TEST_GEN_PUZZLE
//#define DEBUG_TEST_SPLIT_DIFFICULTY

/* global variants */
int n_finale = 0;					// number of final results
char* input = nullptr;				// file path of games (both relative and absolute path are ok)
int n_puzzle = 0;					// number of games to be generated
int difficulty = 0;					// difficulty (easy, middle or hard, default is easy)
int n_blank = 0;					// number of blanks
bool unique = true;					// whether solution is unique (default is not)

/* parse cmdline arguments */ 
int main(int argc, char* argv[]) {
	std::cout << LOGO << std::endl;
#ifndef DEBUG_TEST	// !DEBUG_TEST
	if (argc < 2) {
		Sudoku::print_usage();
		return 0;
	}
	for (int i = 1; i < argc; i++) {
		if (strcmp(argv[i], "-c") == 0) {
			Assert(++i < argc, 
				"The number of finales to be generated following with `-c` needs to be provided!");
			n_finale = atoi(argv[i]);
			Assert(n_finale >= MIN_FINALE && n_finale <= MAX_FINALE,
				"Invalid number of finals: %d. The valid range is [%d, %d]", n_finale, MIN_FINALE, MAX_FINALE);
			continue;
		}
		else if (strcmp(argv[i], "-s") == 0) {
			Assert(++i < argc, 
				"The file path of puzzles to be solved following with `-s` needs to be provided!");
			input = argv[i];
			continue;
		}
		else if (strcmp(argv[i], "-n") == 0) {
			Assert(++i < argc, 
				"The number of puzzles to be generated following with `-n` needs to be provided!");
			n_puzzle = atoi(argv[i]);
			Assert(n_puzzle >= MIN_PUZZLE && n_puzzle <= MAX_PUZZLE,
				"Invalid number of puzzles: %d. The valid range is [%d, %d]", n_puzzle, MIN_PUZZLE, MAX_PUZZLE);
			continue;
		}
		else if (strcmp(argv[i], "-m") == 0) {
			Assert(++i < argc, 
				"The difficulty of puzzles to be generated following with `-m` needs to be provided!");
			difficulty = atoi(argv[i]);
			Assert(difficulty >= MIN_DIFFICULTY && difficulty <= MAX_DIFFICULTY,
				"Invalid difficulty: %d. The valid range is [%d, %d]", difficulty, MIN_DIFFICULTY, MAX_DIFFICULTY);
			continue;
		}
		else if (strcmp(argv[i], "-r") == 0) {
			Assert(++i < argc, 
				"The number of blanks in each puzzle to be generated following with `-r` needs to be provided!");
			n_blank = atoi(argv[i]);
			Assert(n_blank >= MIN_BLANK && n_blank <= MAX_BLANK,
				"Invalid number of blanks: %d. The valid range is [%d, %d]", n_blank, MIN_BLANK, MAX_BLANK);
			continue;
		}
		else if (strcmp(argv[i], "-u") == 0) {
			unique = true;
			continue;
		}
		else if (strcmp(argv[i], "-h") == 0) {
			Sudoku::print_usage();
			continue;
		}
		else {
			Assert(false, "Please input write commands!");
		}
	}

	Sudoku s;
	s.init(n_finale, input, n_puzzle, difficulty, n_blank, unique);

	if (n_finale) {
		s.generate_finales();
	}
	if (n_puzzle) {
		s.generate_puzzles();
	}
	if (input) {
		s.solve_puzzles();
	}
#else	// DEBUG_TEST

#ifdef DEBUG_TEST_GEN_FINALE
	n_finale = 1;
	Sudoku s;
	s.init(n_finale, input, n_puzzle, difficulty, n_blank, unique);
	s.generate_finales();
#endif	// DEBUG_TEST_GEN_FINALE

#ifdef DEBUG_TEST_GEN_PUZZLE
	n_puzzle = 10;
	n_blank = 30;
	difficulty = MIN_DIFFICULTY;
	unique = true;
	Sudoku s;
	s.init(n_finale, input, n_puzzle, difficulty, n_blank, unique);
	s.generate_puzzles();
#endif	// DEBUG_TEST_GEN_PUZZLE

#ifdef DEBUG_TEST_SPLIT_DIFFICULTY
	Sudoku s;
	s.split_difficulty();
#endif	// DEBUG_TEST_SPLIT_DIFFICULTY

#endif	// DEBUG_TEST
	return 0;
}
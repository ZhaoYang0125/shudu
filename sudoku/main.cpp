#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include "Sudoku.h"

#define DEBUG_TEST

/* global variants */
int n_finale = 0;					// number of final results
char* input = nullptr;				// file path of games (both relative and absolute path are ok)
int n_puzzle = 0;					// number of games to be generated
int difficulty = MIN_DIFFICULTY;	// difficulty (easy, middle or hard, default is easy)
int n_blank = MIN_BLANK;			// number of blanks
bool unique = false;				// whether solution is unique (default is not)

/* parse cmdline arguments */
int main(int argc, char* argv[]) {
#ifndef DEBUG_TEST
	if (argc < 2) {
		Sudoku::print_usage();
		return 0;
	}
	for (int i = 1; i < argc; i++) {
		if (strcmp(argv[i], "-c") == 0) {
			Assert(++i < argc, 
				"The number of finales to be generated following with `-c` needs to be provided!");
			n_finale = atoi(argv[i]);
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
			continue;
		}
		else if (strcmp(argv[i], "-m") == 0) {
			Assert(++i < argc, 
				"The difficulty of puzzles to be generated following with `-m` needs to be provided!");
			difficulty = atoi(argv[i], );
			continue;
		}
		else if (strcmp(argv[i], "-r") == 0) {
			Assert(++i < argc, 
				"The number of blanks in each puzzle to be generated following with `-r` needs to be provided!");
			n_blank = atoi(argv[i]);
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
	n_puzzle = 1;
	Sudoku s;
	s.init(n_finale, input, n_puzzle, difficulty, n_blank, unique);
	s.generate_puzzles();
#endif	// DEBUG_TEST
	return 0;
}
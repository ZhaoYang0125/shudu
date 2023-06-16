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
			assert(++i < argc);
			n_finale = atoi(argv[i]);
			continue;
		}
		else if (strcmp(argv[i], "-s") == 0) {
			assert(++i < argc);
			input = argv[i];
			continue;
		}
		else if (strcmp(argv[i], "-n") == 0) {
			assert(++i < argc);
			n_puzzle = atoi(argv[i]);
			continue;
		}
		else if (strcmp(argv[i], "-m") == 0) {
			assert(++i < argc);
			difficulty = atoi(argv[i]);
			continue;
		}
		else if (strcmp(argv[i], "-r") == 0) {
			assert(++i < argc);
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
			std::cerr << "Wrong Commands!" << std::endl;
			Sudoku::print_usage();
			exit(1);
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
	n_finale = 1;
	Sudoku s;
	s.init(n_finale, input, n_puzzle, difficulty, n_blank, unique);
	s.generate_finales();
#endif	// DEBUG_TEST
	return 0;
}
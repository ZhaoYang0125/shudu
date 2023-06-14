#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include "Sudoku.h"

/* global variants */
int n_finals = 0;					// number of final results
char* input = nullptr;				// file path of games (both relative and absolute path are ok)
int n_puzzles = 0;					// number of games to be generated
int difficulty = MIN_DIFFICULTY;	// difficulty (easy, middle or hard, default is easy)
int n_blanks = MIN_BLANKS;			// number of blanks
bool unique = false;				// whether solution is unique (default is not)

/* parse cmdline arguments */
int main(int argc, char* argv[]) {
	if (argc < 2) {
		Sudoku::print_usage();
		return 0;
	}
	for (int i = 1; i < argc; i++) {
		if (strcmp(argv[i], "-c") == 0) {
			assert(++i < argc);
			n_finals = atoi(argv[i]);
			continue;
		}
		else if (strcmp(argv[i], "-s") == 0) {
			assert(++i < argc);
			input = argv[i];
			continue;
		}
		else if (strcmp(argv[i], "-n") == 0) {
			assert(++i < argc);
			n_puzzles = atoi(argv[i]);
			continue;
		}
		else if (strcmp(argv[i], "-m") == 0) {
			assert(++i < argc);
			difficulty = atoi(argv[i]);
			continue;
		}
		else if (strcmp(argv[i], "-r") == 0) {
			assert(++i < argc);
			n_blanks = atoi(argv[i]);
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
	s.init(n_finals, input, n_puzzles, difficulty, n_blanks, unique);

	if (n_finals) {
		s.generate_finals();
	}
	if (n_puzzles) {
		s.generate_puzzles();
	}
	if (input) {
		s.solve_puzzles();
	}
	return 0;
}
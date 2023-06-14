#include "Sudoku.h"
#include <cassert>
#include <cstring>

void Sudoku::init(int n_finals, char* input, int n_puzzles, int difficulty, int n_blanks, bool unique) {
	assert(n_finals >= MIN_FINALS && n_finals <= MAX_FINALS);
	assert(n_puzzles >= MIN_GAMES && n_puzzles <= MAX_GAMES);
	assert(difficulty >= MIN_DIFFICULTY && difficulty <= MAX_DIFFICULTY);
	assert(n_blanks >= MIN_BLANKS && n_blanks <= MAX_BLANKS);

	_n_finals = n_finals;
	if (input != nullptr) {	// deepcopy in case that `input` is out of its lifetime
		size_t length = strlen(input);
		_input = new char[length + 1];
		strncpy_s(_input, length + 1, input, length);
	}
	_n_puzzles = n_puzzles;
	_difficulty = difficulty;
	_n_blanks = n_blanks;
	_unique = unique;
}

void Sudoku::generate_finals() const {
	std::cout << "Generating " << _n_finals << " finals..." << std::endl;
	int grid[9][9];
	for (int i = 0; i < _n_finals; i++) {
		gen_final(grid);
		std::cout << "Final " << i + 1 << std::endl;
		print_grid(grid);
	}
	std::cout << "All " << _n_finals << " finals have been generated." << std::endl;
}

void Sudoku::generate_puzzles() const {
	

	std::cout << "generate_games" << std::endl;
}

void Sudoku::solve_puzzles() const {
	// TODO
	assert(false);
}

void Sudoku::print_grid(int grid[9][9]) const
{
	std::cout << "print_grid" << std::endl;
}

void Sudoku::gen_final(int grid[9][9]) const
{


}



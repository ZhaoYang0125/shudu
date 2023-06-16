#include "Sudoku.h"
#include <cassert>
#include <cstring>
#include <cstdio>

void Sudoku::init(int n_finale, char* input, int n_puzzle, int difficulty, int n_blank, bool unique) 
{
	// at this time, we do not know which function the user needs
	// so we check legality of params when calling corresponding functions
	_n_finale = n_finale;
	if (input != nullptr) {	// deepcopy in case that `input` is out of its lifetime
		size_t length = strlen(input);
		_input = new char[length + 1];
		strncpy_s(_input, length + 1, input, length);
	}
	_n_puzzle = n_puzzle;
	_difficulty = difficulty;
	_n_blank = n_blank;
	_unique = unique;
}

void Sudoku::generate_finales() const 
{
	assert(_n_finale >= MIN_FINALE && _n_finale <= MAX_FINALE);

	std::cout << "Generating " << _n_finale << " finales..." << std::endl;
	int grid[9][9];
	for (int i = 0; i < _n_finale; i++) {
		gen_finale(grid);
		std::cout << "Finale " << i + 1 << std::endl;
		print_grid(grid);
	}
	std::cout << "All " << _n_finale << " finale(s) have(has) been generated." << std::endl;
}

void Sudoku::generate_puzzles() const 
{
	assert(_n_puzzle >= MIN_PUZZLE && _n_puzzle <= MAX_PUZZLE);
	assert(_difficulty >= MIN_DIFFICULTY && _difficulty <= MAX_DIFFICULTY);
	assert(_n_blank >= MIN_BLANK && _n_blank <= MAX_BLANK);

	std::cout << "generate_games" << std::endl;
}

void Sudoku::solve_puzzles() const {
	// TODO
	assert(false);
}

void Sudoku::grid_to_str(int grid[9][9], char* grid_str) const
{
	int* ptr_src = nullptr;
	char *ptr_dst = grid_str;
	for (int i = 0; i < 9; i++) {
		ptr_src = grid[i];
		for (int j = 0; j < 9; j++) {
			*ptr_dst++ = character_map[*ptr_src++];
		}
	}
}

void Sudoku::print_grid(int grid[9][9]) const
{
	char grid_str[81];
	grid_to_str(grid, grid_str);	// flatten
	print_grid(grid_str);
}

void Sudoku::print_grid(char* grid_str) const
{
	const int buf_sz = 1024;
	char buffer[buf_sz];
	snprintf(buffer, buf_sz,
"-------------------------\n"
"| %c %c %c | %c %c %c | %c %c %c |\n"
"| %c %c %c | %c %c %c | %c %c %c |\n"
"| %c %c %c | %c %c %c | %c %c %c |\n"
"-------------------------\n"
"| %c %c %c | %c %c %c | %c %c %c |\n"
"| %c %c %c | %c %c %c | %c %c %c |\n"
"| %c %c %c | %c %c %c | %c %c %c |\n"
"------------------------- \n"
"| %c %c %c | %c %c %c | %c %c %c |\n"
"| %c %c %c | %c %c %c | %c %c %c |\n"
"| %c %c %c | %c %c %c | %c %c %c |\n"
"-------------------------",
grid_str[0], grid_str[1], grid_str[2], grid_str[3], grid_str[4], grid_str[5], grid_str[6], grid_str[7], grid_str[8], grid_str[9],
grid_str[10], grid_str[11], grid_str[12], grid_str[13], grid_str[14], grid_str[15], grid_str[16], grid_str[17], grid_str[18], grid_str[19],
grid_str[20], grid_str[21], grid_str[22], grid_str[23], grid_str[24], grid_str[25], grid_str[26], grid_str[27], grid_str[28], grid_str[29],
grid_str[30], grid_str[31], grid_str[32], grid_str[33], grid_str[34], grid_str[35], grid_str[36], grid_str[37], grid_str[38], grid_str[39],
grid_str[40], grid_str[41], grid_str[42], grid_str[43], grid_str[44], grid_str[45], grid_str[46], grid_str[47], grid_str[48], grid_str[49],
grid_str[50], grid_str[51], grid_str[52], grid_str[53], grid_str[54], grid_str[55], grid_str[56], grid_str[57], grid_str[58], grid_str[59],
grid_str[60], grid_str[61], grid_str[62], grid_str[63], grid_str[64], grid_str[65], grid_str[66], grid_str[67], grid_str[68], grid_str[69],
grid_str[70], grid_str[71], grid_str[72], grid_str[73], grid_str[74], grid_str[75], grid_str[76], grid_str[77], grid_str[78], grid_str[79],
grid_str[80]);
	std::cout << buffer << std::endl;
}

void Sudoku::gen_finale(int grid[9][9]) const
{
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			grid[i][j] = 0;
		}
	}
}


